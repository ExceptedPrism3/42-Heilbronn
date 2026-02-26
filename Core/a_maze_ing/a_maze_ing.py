#!/usr/bin/env python3
"""The main script."""
import sys
import os
from typing import Dict, Any, Tuple, Optional
from mazegen import MazeGenerator, Visualizer
from mazegen.utils import coords_to_directions


def parse_config(filename: str) -> Dict[str, Any]:
    """Reads the config file."""
    config: Dict[str, Any] = {}
    if not os.path.exists(filename):
        print(f"Error: Config file '{filename}' not found.")
        sys.exit(1)

    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue

            if '=' not in line:
                print(f"Error: Invalid line in config: {line}")
                sys.exit(1)

            key, value = line.split('=', 1)
            key = key.strip()
            value = value.strip()

            config[key] = value

    return config


def validate_config(config: Dict[str, Any]) -> None:
    """Checks if config is valid."""
    required = ["WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE", "PERFECT"]
    for key in required:
        if key not in config:
            print(f"Error: Missing required key: {key}")
            sys.exit(1)

    try:
        w = int(config["WIDTH"])
        h = int(config["HEIGHT"])
        if w <= 0 or h <= 0:
            raise ValueError
    except ValueError:
        print("Error: WIDTH and HEIGHT must be positive integers.")
        sys.exit(1)

    # Validate Coordinates
    def parse_coord(c_str: str) -> Optional[Tuple[int, int]]:
        try:
            x, y = map(int, c_str.split(','))
            return x, y
        except ValueError:
            return None

    entry = parse_coord(config["ENTRY"])
    exit_p = parse_coord(config["EXIT"])

    if entry is None:
        print(f"Error: Invalid ENTRY format: {config['ENTRY']}")
        sys.exit(1)
    if exit_p is None:
        print(f"Error: Invalid EXIT format: {config['EXIT']}")
        sys.exit(1)

    if not (0 <= entry[0] < w and 0 <= entry[1] < h):
        print(f"Error: Entry {entry} out of bounds.")
        sys.exit(1)

    if not (0 <= exit_p[0] < w and 0 <= exit_p[1] < h):
        print(f"Error: Exit {exit_p} out of bounds.")
        sys.exit(1)


def main() -> None:
    """Run the program."""
    if len(sys.argv) != 2:
        print("Usage: python3 a_maze_ing.py config.txt")
        sys.exit(1)

    config_file = sys.argv[1]
    config = parse_config(config_file)
    validate_config(config)

    # Configure Generator
    maze = MazeGenerator()
    maze.width = int(config["WIDTH"])
    maze.height = int(config["HEIGHT"])
    # Type ignore because validate ensures valid ints
    entry_s = config["ENTRY"].split(',')
    exit_s = config["EXIT"].split(',')
    maze.entry = (int(entry_s[0]), int(entry_s[1]))
    maze.exit = (int(exit_s[0]), int(exit_s[1]))

    if "SEED" in config:
        try:
            maze.seed = int(config["SEED"])
        except ValueError:
            print("Error: Invalid SEED")
            sys.exit(1)

    # Generate
    maze.generate()

    # Solve
    path_coords = maze.solve()
    path_str = coords_to_directions(path_coords)

    # Write Output
    out_file = config["OUTPUT_FILE"]
    hex_grid = maze.to_hex()

    with open(out_file, 'w') as f:
        f.write(hex_grid)
        f.write("\n\n")
        f.write(f"{maze.entry[0]}, {maze.entry[1]}\n")
        f.write(f"{maze.exit[0]}, {maze.exit[1]}\n")
        f.write(f"{path_str}\n")

    print(f"Maze generated and saved to {out_file}.")

    # Visualization
    print("Starting visualizer...")
    vis = Visualizer(maze)
    vis.start()


if __name__ == "__main__":
    main()
