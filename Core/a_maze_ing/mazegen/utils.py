"""Helpers and constants."""
from typing import List, Tuple

# Wall Bitmasks
NORTH = 1  # 0001
EAST = 2   # 0010
SOUTH = 4  # 0100
WEST = 8   # 1000

# Hex mapping for 0-15
HEX_MAP = "0123456789ABCDEF"


def to_hex(value: int) -> str:
    """Int to Hex."""
    if not 0 <= value <= 15:
        raise ValueError(f"Value {value} out of range (0-15)")
    return HEX_MAP[value]


def from_hex(char: str) -> int:
    """Hex to Int."""
    try:
        return int(char, 16)
    except ValueError:
        raise ValueError(f"Invalid hex character: {char}")


def get_neighbors(
    x: int,
    y: int,
    width: int,
    height: int
) -> List[Tuple[int, int, int]]:
    """Find neighbors."""
    neighbors = []
    # North
    if y > 0:
        neighbors.append((x, y - 1, NORTH))
    # South
    if y < height - 1:
        neighbors.append((x, y + 1, SOUTH))
    # East
    if x < width - 1:
        neighbors.append((x + 1, y, EAST))
    # West
    if x > 0:
        neighbors.append((x - 1, y, WEST))
    return neighbors


def get_opposite(direction: int) -> int:
    """Flip direction."""
    if direction == NORTH:
        return SOUTH
    if direction == SOUTH:
        return NORTH
    if direction == EAST:
        return WEST
    if direction == WEST:
        return EAST
    raise ValueError(f"Invalid direction: {direction}")


def coords_to_directions(coords: List[Tuple[int, int]]) -> str:
    """Path to string."""
    if not coords or len(coords) < 2:
        return ""

    directions = []
    for i in range(len(coords) - 1):
        cx, cy = coords[i]
        nx, ny = coords[i+1]

        if ny < cy:
            directions.append("N")
        elif ny > cy:
            directions.append("S")
        elif nx > cx:
            directions.append("E")
        elif nx < cx:
            directions.append("W")

    return "".join(directions)
