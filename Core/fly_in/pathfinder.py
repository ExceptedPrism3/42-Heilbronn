"""Pathfinding helpers for drone routing."""

from __future__ import annotations

import heapq

from models import Graph, ZoneType, zone_pathfinding_weight


class Pathfinder:
    """Compute shortest weighted paths over graph."""

    def __init__(self, graph: Graph) -> None:
        self.graph = graph

    def shortest_path(self, start: str, end: str) -> list[str]:
        """Return lowest-cost node path from start to end."""
        if start == end:
            return [start]

        dist: dict[str, float] = {start: 0.0}
        prev: dict[str, str] = {}
        heap: list[tuple[float, str]] = [(0.0, start)]
        visited: set[str] = set()

        while heap:
            cur_cost, node = heapq.heappop(heap)
            if node in visited:
                continue
            visited.add(node)
            if node == end:
                break

            for edge in self.graph.adjacency.get(node, []):
                nxt = edge.other(node)
                zone = self.graph.zones[nxt]
                if zone.zone_type == ZoneType.BLOCKED:
                    continue
                weight = zone_pathfinding_weight(zone.zone_type)
                new_cost = cur_cost + weight
                if new_cost < dist.get(nxt, float("inf")):
                    dist[nxt] = new_cost
                    prev[nxt] = node
                    heapq.heappush(heap, (new_cost, nxt))

        if end not in prev and end != start:
            return []

        path = [end]
        cur = end
        while cur != start:
            cur = prev[cur]
            path.append(cur)
        path.reverse()
        return path

    def path_cost(self, start: str, end: str) -> float:
        """Return pathfinding cost for scheduling priority."""
        path = self.shortest_path(start, end)
        if not path:
            return float("inf")
        total = 0.0
        for zone_name in path[1:]:
            total += zone_pathfinding_weight(
                self.graph.zones[zone_name].zone_type
            )
        return total
