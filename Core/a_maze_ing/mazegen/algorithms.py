"""Algorithms for the maze."""
import random
from typing import List, Tuple, Set, Optional
from .utils import NORTH, SOUTH, EAST, WEST, get_neighbors, get_opposite


def generate_dfs(
    width: int,
    height: int,
    seed: Optional[int] = None,
    blocked: Optional[Set[Tuple[int, int]]] = None
) -> List[List[int]]:
    """
    Make maze with DFS.
    Returns grid where 1=Closed, 0=Open.
    """
    if seed is not None:
        random.seed(seed)

    # Initialize grid with all walls closed (15 = 1111)
    grid = [[15 for _ in range(width)] for _ in range(height)]

    # Visited set
    visited: Set[Tuple[int, int]] = set()
    if blocked:
        visited.update(blocked)

    # Starting point (random or 0,0)
    start_x, start_y = 0, 0
    stack: List[Tuple[int, int]] = [(start_x, start_y)]
    visited.add((start_x, start_y))

    while stack:
        cx, cy = stack[-1]

        # Get unvisited neighbors
        # get_neighbors returns (nx, ny, direction_TO_neighbor)
        neighbors = get_neighbors(cx, cy, width, height)
        unvisited = []
        for nx, ny, direction in neighbors:
            if (nx, ny) not in visited:
                unvisited.append((nx, ny, direction))

        if unvisited:
            # Choose random unvisited neighbor
            nx, ny, direction = random.choice(unvisited)

            # Remove wall between current and neighbor
            # Direction is from Current TO Neighbor.
            # Convert closed-wall bitmask logic:
            # If we go NORTH, we open the NORTH wall of Current
            # And the SOUTH wall of Neighbor.

            # Open wall on current cell (Bitwise AND with Inverse)
            grid[cy][cx] &= ~direction

            # Open opposite wall on neighbor cell
            opposite = get_opposite(direction)
            grid[ny][nx] &= ~opposite

            # Mark visited and push to stack
            visited.add((nx, ny))
            stack.append((nx, ny))
        else:
            # Backtrack
            stack.pop()

    return grid


def solve_bfs(
    grid: List[List[int]],
    width: int,
    height: int,
    entry: Tuple[int, int],
    exit: Tuple[int, int]
) -> List[Tuple[int, int]]:
    """Solve with BFS."""
    start_x, start_y = entry
    end_x, end_y = exit

    # (x, y, path)
    queue: List[Tuple[int, int, List[Tuple[int, int]]]] = [
        (start_x, start_y, [])
    ]
    visited = set()
    visited.add((start_x, start_y))

    while queue:
        cx, cy, path = queue.pop(0)
        new_path = path + [(cx, cy)]

        if (cx, cy) == (end_x, end_y):
            return new_path

        # Get neighbors involves checking walls

        # North
        if cy > 0 and not (grid[cy][cx] & NORTH):
            if (cx, cy - 1) not in visited:
                visited.add((cx, cy - 1))
                queue.append((cx, cy - 1, new_path))

        # South
        is_south_open = not (grid[cy][cx] & SOUTH)
        if cy < height - 1 and is_south_open:
            if (cx, cy + 1) not in visited:
                visited.add((cx, cy + 1))
                queue.append((cx, cy + 1, new_path))

        # East
        if cx < width - 1 and not (grid[cy][cx] & EAST):
            if (cx + 1, cy) not in visited:
                visited.add((cx + 1, cy))
                queue.append((cx + 1, cy, new_path))

        # West
        if cx > 0 and not (grid[cy][cx] & WEST):
            if (cx - 1, cy) not in visited:
                visited.add((cx - 1, cy))
                queue.append((cx - 1, cy, new_path))

    return []
