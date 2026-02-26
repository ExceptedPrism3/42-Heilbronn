"""Draws maze in terminal."""
import curses
from typing import Optional, Any
from .utils import NORTH, SOUTH, EAST, WEST

# Colors
COLOR_WALL = 1
COLOR_PATH = 2
COLOR_TEXT = 3
COLOR_PLAYER = 4


class Visualizer:
    """Handles drawing."""
    def __init__(self, generator: Any) -> None:
        """Setup visualizer."""
        self.generator = generator
        self.show_path = True  # Show path automatically
        self.player_pos = self.generator.entry
        self.stdscr: Optional[Any] = None  # Curses window

    def start(self) -> None:
        """Run the UI."""
        curses.wrapper(self._main_loop)

    def _main_loop(self, stdscr: Any) -> None:
        """Loop for keys and drawing."""
        self.stdscr = stdscr
        curses.curs_set(0)  # Hide cursor
        curses.start_color()
        curses.use_default_colors()

        # Define color pairs
        curses.init_pair(COLOR_WALL, curses.COLOR_WHITE, -1)
        # Force Black BG for path to ensure it's visible against Cyan
        curses.init_pair(COLOR_PATH, curses.COLOR_CYAN, curses.COLOR_BLACK)
        curses.init_pair(COLOR_TEXT, curses.COLOR_WHITE, -1)
        curses.init_pair(COLOR_PLAYER, curses.COLOR_RED, -1)

        while True:
            self.render()
            try:
                key = stdscr.getch()
            except curses.error:
                continue

            if key == ord('q') or key == ord('Q'):
                break
            elif key == ord('n') or key == ord('N') or key == ord(' '):
                # Regenerate
                if self.generator.seed is not None:
                    self.generator.seed += 1
                self.generator.generate()
                self.player_pos = self.generator.entry
            elif key == ord('p') or key == ord('P'):
                self.show_path = not self.show_path
            # Movement
            elif key == curses.KEY_UP:
                self._move_player(0, -1)
            elif key == curses.KEY_DOWN:
                self._move_player(0, 1)
            elif key == curses.KEY_LEFT:
                self._move_player(-1, 0)
            elif key == curses.KEY_RIGHT:
                self._move_player(1, 0)

    def _move_player(self, dx: int, dy: int) -> None:
        """Move player."""
        px, py = self.player_pos
        nx, ny = px + dx, py + dy
        grid = self.generator.grid

        # Check bounds
        in_x = 0 <= nx < self.generator.width
        in_y = 0 <= ny < self.generator.height
        if not (in_x and in_y):
            return

        # Check Walls
        if dy == -1:  # North
            if grid[py][px] & NORTH:
                return
        elif dy == 1:  # South
            if grid[py][px] & SOUTH:
                return
        elif dx == 1:  # East
            if grid[py][px] & EAST:
                return
        elif dx == -1:  # West
            if grid[py][px] & WEST:
                return

        self.player_pos = (nx, ny)

    def render(self) -> None:
        """Draw everything."""
        if not self.stdscr:
            return

        self.stdscr.clear()

        height, width = self.stdscr.getmaxyx()
        gw = self.generator.width
        gh = self.generator.height
        grid = self.generator.grid

        # Check terminals size
        req_h = gh * 2 + 1
        req_w = gw * 2 + 1
        if req_h > height or req_w > width:
            self.stdscr.addstr(
                0, 0, "Terminal too small!", curses.color_pair(COLOR_TEXT)
            )
            self.stdscr.refresh()
            return

        # Solve path if needed
        path_coords = set()
        if self.show_path:
            path_coords = set(self.generator.solve())

        # Box Drawing Helper
        # We need to compute connections for each vertex (y, x).
        # Vertex grid size is (gh+1) * (gw+1).
        # Vertices are at screen coordinates (y*2, x*2).

        # Directions: N=1, S=2, E=4, W=8 (Local to vertex)
        box_chars = {
            0: " ", 1: "│", 2: "│", 3: "│",
            4: "─", 5: "└", 6: "┌", 7: "├",
            8: "─", 9: "┘", 10: "┐", 11: "┤",
            12: "─", 13: "┴", 14: "┬", 15: "┼"
        }

        # Iterate geometry
        for y in range(gh + 1):
            # Draw Horizontal Strip (Vertices and Horiz walls)
            for x in range(gw + 1):
                # Calculate Vertex Char at (y*2, x*2)
                mask = 0

                # Check UP (connects to vertex above?)
                # Wall UP corresponds to Vertical Wall at x-1.
                # Vertical wall segment ABOVE this vertex is West of (x, y-1).
                # Indices:
                # Down: West wall of (x, y)      -> grid[y][x] & WEST
                # Up:   West wall of (x, y-1)    -> grid[y-1][x] & WEST
                # Right: North wall of (x, y)    -> grid[y][x] & NORTH
                # Left:  North wall of (x-1, y)  -> grid[y][x-1] & NORTH

                # Handle boundaries carefully
                # DOWN
                if y < gh and x < gw:
                    if grid[y][x] & WEST:
                        mask |= 2  # South
                elif y < gh and x == gw:
                    if grid[y][x - 1] & EAST:
                        mask |= 2

                # UP
                if y > 0 and x < gw:
                    if grid[y - 1][x] & WEST:
                        mask |= 1  # North
                elif y > 0 and x == gw:
                    if grid[y - 1][x - 1] & EAST:
                        mask |= 1

                # RIGHT
                if x < gw and y < gh:
                    if grid[y][x] & NORTH:
                        mask |= 4  # East
                elif x < gw and y == gh:
                    if grid[y - 1][x] & SOUTH:
                        mask |= 4

                # LEFT
                if x > 0 and y < gh:
                    if grid[y][x - 1] & NORTH:
                        mask |= 8  # West
                elif x > 0 and y == gh:
                    if grid[y - 1][x - 1] & SOUTH:
                        mask |= 8

                char = box_chars.get(mask, " ")
                self._draw(y * 2, x * 2, char, COLOR_WALL)

                # Draw Horizontal Wall to the Right (if not last col)
                if x < gw:
                    is_wall = False
                    is_path_conn = False

                    # Logic for Horizontal Wall (North/South boundary)
                    if y < gh:
                        if grid[y][x] & NORTH:
                            is_wall = True
                        elif (x, y) in path_coords and \
                                (x, y - 1) in path_coords:
                            is_path_conn = True
                    else:
                        if grid[y - 1][x] & SOUTH:
                            is_wall = True

                    if is_wall:
                        self._draw(y * 2, x * 2 + 1, "─", COLOR_WALL)
                    elif is_path_conn:
                        self._draw(y * 2, x * 2 + 1, "░", COLOR_PATH)
                    else:
                        self._draw(y * 2, x * 2 + 1, " ", COLOR_WALL)

            # Draw Vertical Strip (Vert walls and Cell centers)
            # BELOW the current line of vertices
            if y < gh:
                for x in range(gw + 1):
                    # Vertical Wall
                    is_wall = False
                    is_path_conn = False

                    if x < gw:
                        if grid[y][x] & WEST:
                            is_wall = True
                        elif x > 0 and (x, y) in path_coords and \
                                (x - 1, y) in path_coords:
                            is_path_conn = True
                    elif x == gw:
                        if grid[y][x - 1] & EAST:
                            is_wall = True

                    if is_wall:
                        self._draw(y * 2 + 1, x * 2, "│", COLOR_WALL)
                    elif is_path_conn:
                        self._draw(y * 2 + 1, x * 2, "░", COLOR_PATH)
                    else:
                        self._draw(y * 2 + 1, x * 2, " ", COLOR_WALL)

                    # Cell Center (if x < gw)
                    if x < gw:
                        center_char = " "
                        color = COLOR_WALL
                        is_path = (x, y) in path_coords
                        is_start = (x, y) == self.generator.entry
                        is_end = (x, y) == self.generator.exit
                        is_player = (x, y) == self.player_pos
                        is_block = grid[y][x] == 15

                        if is_block:
                            center_char = "#"
                        elif is_player:
                            center_char = "█"  # Solid block for player
                            color = COLOR_PLAYER
                        elif is_start:
                            center_char = "S"
                            color = COLOR_PLAYER
                        elif is_end:
                            center_char = "E"
                            color = COLOR_PLAYER
                        elif is_path:
                            center_char = "░"
                            color = COLOR_PATH

                        self._draw(y * 2 + 1, x * 2 + 1, center_char, color)

        # Dimensions info
        item = f"Maze {gw}x{gh} | Seed: {self.generator.seed}"
        info = f"{item} | [N]ew [P]ath [Arrows]Move"
        self.stdscr.addstr(req_h, 0, info, curses.color_pair(COLOR_TEXT))

        if self.player_pos == self.generator.exit:
            self.stdscr.addstr(
                req_h + 1,
                0,
                "YOU WIN!",
                curses.color_pair(COLOR_PLAYER)
            )

        self.stdscr.refresh()

    def _draw(self, y: int, x: int, char: str, color: int) -> None:
        """Safe draw."""
        if not self.stdscr:
            return
        try:
            self.stdscr.addstr(y, x, char, curses.color_pair(color))
        except curses.error:
            pass
