"""Generates mazes."""
from typing import List, Tuple, Optional, Set
from .algorithms import generate_dfs, solve_bfs
from .utils import to_hex


class MazeGenerator:
    """The maze generator."""
    def __init__(self) -> None:
        self.width = 20
        self.height = 15
        self.seed: Optional[int] = None
        self.grid: List[List[int]] = []
        self.entry: Tuple[int, int] = (0, 0)
        self.exit: Tuple[int, int] = (19, 14)

    def generate(self) -> None:
        """Make a new maze."""
        # Get blocked cells for "42" pattern
        blocked = self.get_42_mask()
        self.grid = generate_dfs(self.width, self.height, self.seed, blocked)

    def solve(self) -> List[Tuple[int, int]]:
        """Find the way out."""
        return solve_bfs(
            self.grid,
            self.width,
            self.height,
            self.entry,
            self.exit
        )

    def get_42_mask(self) -> Set[Tuple[int, int]]:
        """Get set of coordinates for '42' pattern."""
        blocked: Set[Tuple[int, int]] = set()
        if self.width < 7 or self.height < 7:
            return blocked

        # Combined "4 2" (width 9, height 5)
        bit_pattern = [
            [1, 0, 0, 1, 0, 1, 1, 1, 1],  # Width 9
            [1, 0, 0, 1, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 0, 1, 1, 1, 1],
            [0, 0, 0, 1, 0, 1, 0, 0, 0],
            [0, 0, 0, 1, 0, 1, 1, 1, 1]
        ]

        p_height = len(bit_pattern)
        p_width = len(bit_pattern[0])

        start_y = (self.height - p_height) // 2
        start_x = (self.width - p_width) // 2

        if start_x < 0 or start_y < 0:
            return blocked

        for r in range(p_height):
            for c in range(p_width):
                if bit_pattern[r][c] == 1:
                    blocked.add((start_x + c, start_y + r))

        return blocked

    def to_hex(self) -> str:
        """Dump grid as hex."""
        output = []
        for row in self.grid:
            line = "".join(to_hex(cell) for cell in row)
            output.append(line)
        return "\n".join(output)
