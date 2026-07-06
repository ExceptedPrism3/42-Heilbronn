"""Terminal visualization helpers."""

from __future__ import annotations

import sys

from models import Graph


ANSI_COLORS = {
    "black": "\033[30m",
    "red": "\033[31m",
    "green": "\033[32m",
    "yellow": "\033[33m",
    "blue": "\033[34m",
    "magenta": "\033[35m",
    "purple": "\033[35m",
    "cyan": "\033[36m",
    "white": "\033[37m",
    "gray": "\033[90m",
    "gold": "\033[93m",
    "lime": "\033[92m",
    "orange": "\033[91m",
    "brown": "\033[33m",
    "none": "",
}
ANSI_RESET = "\033[0m"


class Visualizer:
    """Colored terminal output utility."""

    def __init__(self, graph: Graph, enabled: bool = False) -> None:
        self.graph = graph
        self.enabled = enabled

    def color_zone(self, zone_name: str) -> str:
        """Return zone or connection token, possibly colorized."""
        if not self.enabled:
            return zone_name
        if zone_name in self.graph.zones:
            zone = self.graph.zones[zone_name]
            color = ANSI_COLORS.get(zone.color.lower(), "")
            if not color:
                return zone_name
            return f"{color}{zone_name}{ANSI_RESET}"
        if "-" in zone_name:
            left, _, right = zone_name.partition("-")
            return (
                f"{self.color_zone(left)}-{self.color_zone(right)}"
            )
        return zone_name

    def show_turn(self, turn_idx: int, moves: list[str]) -> None:
        """Print a colored turn header on stderr (stdout stays eval-safe)."""
        if not self.enabled or not moves:
            return
        header = f"\033[1m--- Turn {turn_idx} ---\033[0m"
        print(header, file=sys.stderr)
        print(" ".join(moves), file=sys.stderr)
