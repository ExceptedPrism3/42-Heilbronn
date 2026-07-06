"""Fly-in entrypoint."""

from __future__ import annotations

import argparse
import sys

from parser import ParseError, parse_map
from simulator import Simulator


def parse_args() -> argparse.Namespace:
    """Parse command line arguments."""
    parser = argparse.ArgumentParser(
        description="Drone routing simulator for Fly-in."
    )
    parser.add_argument("map_file", help="Path to map file")
    parser.add_argument(
        "--visual",
        action="store_true",
        help="Enable colored terminal output",
    )
    parser.add_argument(
        "--stats",
        action="store_true",
        help="Print simulation metrics at the end",
    )
    return parser.parse_args()


def main() -> int:
    """Program entrypoint."""
    args = parse_args()
    try:
        graph = parse_map(args.map_file)
        simulator = Simulator(graph, visual=args.visual)
        result = simulator.run()
    except (ParseError, OSError, RuntimeError) as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1

    for turn in result.turns:
        print(" ".join(turn))

    if args.stats:
        print(f"# turns={result.total_turns}")
        avg = result.total_turns / max(result.delivered, 1)
        print(f"# avg_turns_per_drone={avg:.2f}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
