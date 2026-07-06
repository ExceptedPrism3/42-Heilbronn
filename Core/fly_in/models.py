"""Core domain models for the Fly-in project."""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum
from typing import cast


class ZoneType(str, Enum):
    """Supported zone types."""

    NORMAL = "normal"
    BLOCKED = "blocked"
    RESTRICTED = "restricted"
    PRIORITY = "priority"


def zone_entry_cost(zone_type: ZoneType) -> int:
    """Return the movement cost to enter a zone."""
    if zone_type == ZoneType.RESTRICTED:
        return 2
    return 1


def zone_pathfinding_weight(zone_type: ZoneType) -> float:
    """Return Dijkstra edge weight (priority zones are slightly preferred)."""
    if zone_type == ZoneType.BLOCKED:
        return float("inf")
    if zone_type == ZoneType.RESTRICTED:
        return 2.0
    if zone_type == ZoneType.PRIORITY:
        return 0.9
    return 1.0


@dataclass(frozen=True)
class Zone:
    """A graph node representing a zone/hub."""

    name: str
    x: int
    y: int
    zone_type: ZoneType = ZoneType.NORMAL
    color: str = "none"
    max_drones: int = 1
    is_start: bool = False
    is_end: bool = False

    def effective_capacity(self, nb_drones: int) -> int:
        """Return effective max occupancy for this zone."""
        if self.is_start or self.is_end:
            return max(self.max_drones, nb_drones)
        return self.max_drones


@dataclass(frozen=True)
class Edge:
    """Undirected connection between two zones."""

    a: str
    b: str
    max_link_capacity: int = 1

    @property
    def key(self) -> tuple[str, str]:
        """Canonical undirected key."""
        return cast(tuple[str, str], tuple(sorted((self.a, self.b))))

    def other(self, zone_name: str) -> str:
        """Return opposite endpoint of given zone."""
        if zone_name == self.a:
            return self.b
        if zone_name == self.b:
            return self.a
        raise ValueError(f"Zone '{zone_name}' is not part of this edge")

    def display_name(self) -> str:
        """Return display connection name."""
        return f"{self.a}-{self.b}"


@dataclass
class Drone:
    """Mutable state of a drone during simulation."""

    drone_id: int
    position: str
    arrived: bool = False
    in_transit: bool = False
    transit_target: str = ""
    transit_connection: str = ""
    arrival_turn: int = -1


@dataclass
class Graph:
    """In-memory graph representation."""

    nb_drones: int
    zones: dict[str, Zone] = field(default_factory=dict)
    edges: dict[tuple[str, str], Edge] = field(default_factory=dict)
    adjacency: dict[str, list[Edge]] = field(default_factory=dict)
    start_zone: str = ""
    end_zone: str = ""

    def add_zone(self, zone: Zone) -> None:
        """Add a zone to graph."""
        self.zones[zone.name] = zone
        self.adjacency.setdefault(zone.name, [])
        if zone.is_start:
            self.start_zone = zone.name
        if zone.is_end:
            self.end_zone = zone.name

    def add_edge(self, edge: Edge) -> None:
        """Add edge and update adjacency."""
        self.edges[edge.key] = edge
        self.adjacency[edge.a].append(edge)
        self.adjacency[edge.b].append(edge)
