"""Simulation engine for drone routing."""

from __future__ import annotations

from dataclasses import dataclass
from typing import Optional, cast

from models import Drone, Edge, Graph, ZoneType, zone_entry_cost
from pathfinder import Pathfinder
from visualizer import Visualizer


@dataclass
class SimulationResult:
    """Simulation outputs and metrics."""

    turns: list[list[str]]
    total_turns: int
    delivered: int


class Simulator:
    """Turn-based scheduler and simulator."""

    def __init__(self, graph: Graph, visual: bool = False) -> None:
        self.graph = graph
        self.pathfinder = Pathfinder(graph)
        self.visualizer = Visualizer(graph, enabled=visual)
        self.drones = [
            Drone(drone_id=i + 1, position=graph.start_zone)
            for i in range(graph.nb_drones)
        ]
        self.turn_idx = 0
        self._arrival_reservations: dict[int, dict[str, int]] = {}

    def run(self, max_turns: int = 2000) -> SimulationResult:
        """Run simulation until all drones reach end."""
        turns: list[list[str]] = []
        while not self._all_arrived():
            self.turn_idx += 1
            if self.turn_idx > max_turns:
                raise RuntimeError("Simulation exceeded max_turns")
            moves = self._run_turn()
            if moves:
                self.visualizer.show_turn(self.turn_idx, moves)
            turns.append(moves)
        return SimulationResult(
            turns=turns,
            total_turns=len(turns),
            delivered=self.graph.nb_drones,
        )

    def _all_arrived(self) -> bool:
        """Check if all drones have successfully arrived at the end zone."""
        return all(d.arrived for d in self.drones)

    def _run_turn(self) -> list[str]:
        """Execute a single turn of the simulation.

        Returns:
            A list of moves made during this turn, formatted as D<ID>-<target>.
        """
        moves_this_turn: list[str] = []
        node_occupancy = self._current_node_occupancy()
        edge_usage: dict[tuple[str, str], int] = {}
        planned_out: dict[str, int] = {}
        planned_in: dict[str, int] = {}

        # 1) Arrivals from restricted transitions finalize now.
        for drone in self.drones:
            if drone.in_transit and drone.arrival_turn == self.turn_idx:
                drone.in_transit = False
                drone.position = drone.transit_target
                drone.transit_target = ""
                drone.transit_connection = ""
                if drone.position == self.graph.end_zone:
                    drone.arrived = True
                moves_this_turn.append(
                    self._fmt_move(drone.drone_id, drone.position)
                )
                node_occupancy[drone.position] = (
                    node_occupancy.get(drone.position, 0) + 1
                )

        # 2) Decide movements for drones currently at nodes.
        active = [
            d
            for d in self.drones
            if (not d.arrived) and (not d.in_transit)
        ]
        active.sort(
            key=lambda d: self.pathfinder.path_cost(
                d.position, self.graph.end_zone
            )
        )

        for drone in active:
            path = self.pathfinder.shortest_path(
                drone.position, self.graph.end_zone
            )
            if len(path) < 2:
                continue
            next_zone_name = path[1]
            next_zone = self.graph.zones[next_zone_name]

            edge = self._find_edge(drone.position, next_zone_name)
            if edge is None:
                continue
            edge_key = edge.key
            if edge_usage.get(edge_key, 0) >= edge.max_link_capacity:
                continue

            move_cost = zone_entry_cost(next_zone.zone_type)
            if next_zone.zone_type == ZoneType.BLOCKED:
                continue

            if move_cost == 1:
                if not self._has_capacity_now(
                    zone_name=next_zone_name,
                    node_occupancy=node_occupancy,
                    planned_in=planned_in,
                    planned_out=planned_out,
                ):
                    continue
                self._schedule_normal_move(
                    drone,
                    next_zone_name,
                    edge_key,
                    edge_usage,
                    node_occupancy,
                    planned_in,
                    planned_out,
                    moves_this_turn,
                )
            else:
                if not self._has_capacity_at_arrival(next_zone_name):
                    continue
                self._schedule_restricted_move(
                    drone,
                    next_zone_name,
                    edge,
                    edge_key,
                    edge_usage,
                    node_occupancy,
                    planned_out,
                    moves_this_turn,
                )
        return moves_this_turn

    def _current_node_occupancy(self) -> dict[str, int]:
        """Compute the current number of drones in each zone.

        Returns:
            A dictionary mapping zone name to drone count.
        """
        occ: dict[str, int] = {}
        for d in self.drones:
            if not d.in_transit and not d.arrived:
                occ[d.position] = occ.get(d.position, 0) + 1
            elif d.arrived:
                occ[d.position] = occ.get(d.position, 0) + 1
        return occ

    def _find_edge(self, a: str, b: str) -> Optional[Edge]:
        """Find the edge connecting zones a and b.

        Args:
            a: Name of the first zone.
            b: Name of the second zone.

        Returns:
            The Edge object if a connection exists, otherwise None.
        """
        key = cast(tuple[str, str], tuple(sorted((a, b))))
        return self.graph.edges.get(key)

    def _zone_capacity(self, zone_name: str) -> int:
        """Get the maximum capacity of a zone.

        Args:
            zone_name: The name of the zone.

        Returns:
            The maximum capacity (effective capacity for start/end zones).
        """
        zone = self.graph.zones[zone_name]
        return zone.effective_capacity(self.graph.nb_drones)

    def _has_capacity_now(
        self,
        zone_name: str,
        node_occupancy: dict[str, int],
        planned_in: dict[str, int],
        planned_out: dict[str, int],
    ) -> bool:
        """Determine if a zone has available capacity in the current turn.

        Args:
            zone_name: The target zone.
            node_occupancy: Current drone counts in each zone.
            planned_in: Planned normal incoming moves count this turn.
            planned_out: Planned outgoing moves count this turn.

        Returns:
            True if the zone can accommodate another drone, False otherwise.
        """
        cap = self._zone_capacity(zone_name)
        current = node_occupancy.get(zone_name, 0)
        outgoing = planned_out.get(zone_name, 0)
        incoming = planned_in.get(zone_name, 0)
        return current - outgoing + incoming < cap

    def _has_capacity_at_arrival(self, zone_name: str) -> bool:
        """Determine if a restricted zone has capacity at next turn.

        Args:
            zone_name: The target restricted zone name.

        Returns:
            True if there will be capacity, False otherwise.
        """
        cap = self._zone_capacity(zone_name)
        future = self._arrival_reservations.setdefault(self.turn_idx + 1, {})
        return future.get(zone_name, 0) < cap

    def _schedule_normal_move(
        self,
        drone: Drone,
        next_zone_name: str,
        edge_key: tuple[str, str],
        edge_usage: dict[tuple[str, str], int],
        node_occupancy: dict[str, int],
        planned_in: dict[str, int],
        planned_out: dict[str, int],
        moves_this_turn: list[str],
    ) -> None:
        """Book and finalize a 1-turn move for a drone.

        Args:
            drone: The drone to move.
            next_zone_name: The destination zone.
            edge_key: The key of the connection being traversed.
            edge_usage: Tracked edge utilization counts.
            node_occupancy: Current zone occupants tracker.
            planned_in: Scheduled incoming tracker.
            planned_out: Scheduled outgoing tracker.
            moves_this_turn: Output list where move description is appended.
        """
        src = drone.position
        edge_usage[edge_key] = edge_usage.get(edge_key, 0) + 1
        planned_out[src] = planned_out.get(src, 0) + 1
        planned_in[next_zone_name] = planned_in.get(next_zone_name, 0) + 1
        node_occupancy[src] = node_occupancy.get(src, 0) - 1
        node_occupancy[next_zone_name] = (
            node_occupancy.get(next_zone_name, 0) + 1
        )

        drone.position = next_zone_name
        if next_zone_name == self.graph.end_zone:
            drone.arrived = True
        moves_this_turn.append(self._fmt_move(drone.drone_id, next_zone_name))

    def _schedule_restricted_move(
        self,
        drone: Drone,
        next_zone_name: str,
        edge: Edge,
        edge_key: tuple[str, str],
        edge_usage: dict[tuple[str, str], int],
        node_occupancy: dict[str, int],
        planned_out: dict[str, int],
        moves_this_turn: list[str],
    ) -> None:
        """Book and initiate a 2-turn movement into a restricted zone.

        Args:
            drone: The drone moving.
            next_zone_name: The destination restricted zone.
            edge: The Edge object traversed.
            edge_key: The canonical key for the edge.
            edge_usage: Tracked edge utilization counts.
            node_occupancy: Current zone occupants tracker.
            planned_out: Scheduled outgoing tracker.
            moves_this_turn: Output list where transit description is appended.
        """
        src = drone.position
        edge_usage[edge_key] = edge_usage.get(edge_key, 0) + 1
        planned_out[src] = planned_out.get(src, 0) + 1
        node_occupancy[src] = node_occupancy.get(src, 0) - 1

        # Reserve destination capacity for next turn (forced arrival).
        future = self._arrival_reservations.setdefault(self.turn_idx + 1, {})
        future[next_zone_name] = future.get(next_zone_name, 0) + 1

        drone.in_transit = True
        drone.transit_target = next_zone_name
        drone.transit_connection = f"{src}-{next_zone_name}"
        drone.arrival_turn = self.turn_idx + 1
        moves_this_turn.append(
            self._fmt_move(drone.drone_id, drone.transit_connection)
        )

    def _fmt_move(self, drone_id: int, target: str) -> str:
        """Format the move representation, colorizing if enabled.

        Args:
            drone_id: The ID of the drone.
            target: The target zone or transit connection name.

        Returns:
            The formatted move string, e.g. D1-hub or colored D1-hub.
        """
        return f"D{drone_id}-{self.visualizer.color_zone(target)}"
