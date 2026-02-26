# A-Maze-ing 🌀
This project has been created as part of the 42 curriculum by (aben-cad)[https://profile-v3.intra.42.fr/users/aben-cad] and (drakotov)[https://profile-v3.intra.42.fr/users/drakotov].

## Description
A Python maze generator and visualizer for the terminal. It makes perfect mazes using Recursive Backtracker (DFS) and solves them with BFS.

The project has two main parts:
- `mazegen`: The core library.
- `a_maze_ing.py`: The CLI script to run it.

## Quick Start

### Install
You need Python 3.10 or newer.

1.  Clone the repo.
2.  Install the package:
    ```bash
    make install
    ```

### Run
To generate a maze from a config file:
```bash
make run
# or manual run:
python3 a_maze_ing.py config.txt
```

### Controls
Inside the visualizer:
- **N / Space**: New maze.
- **P**: Toggle path.
- **Q**: Quit.

### Clean up
To remove build files:
```bash
make fclean
```

## Configuration File
The `config.txt` uses `KEY=VALUE` format.

| Key | Description | Example |
| :--- | :--- | :--- |
| `WIDTH` | Width of the maze (cells). | `WIDTH=25` |
| `HEIGHT` | Height of the maze (cells). | `HEIGHT=15` |
| `ENTRY` | Entry coordinates (x,y). | `ENTRY=0,0` |
| `EXIT` | Exit coordinates (x,y). | `EXIT=24,14` |
| `OUTPUT_FILE` | Filename for output. | `OUTPUT_FILE=maze.txt` |
| `PERFECT` | Enforce perfect maze (single path). | `PERFECT=True` |
| `SEED` | (Optional) Integer seed for RNG. | `SEED=42` |

## Algorithms

### Generation: Recursive Backtracker (DFS)
We chose the **Recursive Backtracker** algorithm because:
1.  **Guaranteed Perfect Maze**: It inherently creates a spanning tree (no loops, full connectivity).
2.  **Aesthetics**: It produces long, winding corridors ("River" factor), which make for challenging and good-looking mazes.
3.  **Efficiency**: O(N) complexity relative to the number of cells.
4.  **Simplicity**: It is robust and easy to implement using a stack.

### Solving: Breadth-First Search (BFS)
We used **BFS** for the solver because it guarantees finding the **shortest path** in an unweighted grid, which is ideal for verifying the solution.

## Reusable Parts
The `mazegen` package is designed for reuse.
- `MazeGenerator`: Can be imported to generate maze grids in other applications.
- `algorithms`: Standalone implementations of DFS and BFS.
- `utils`: Helper functions for hex conversion and bitmask manipulation.

Example:
```python
from mazegen import MazeGenerator
maze = MazeGenerator()
maze.width = 10
maze.height = 10
maze.generate()
print(maze.to_hex())
```

## Team and Project Management
**Roles:**
- **Pixo**: Core architecture, `MazeGenerator` class, CLI implementation, Project Management.
- **Peer**: Algorithm research (DFS/BFS), initial visualizer concepts, "42" pattern logic.

**Planning Evolution:**
- **Phase 1**: Research & Design. Decided on a pure Python approach without heavy dependencies (like MLX) for better portability and stability in terminal environments.
- **Phase 2**: Implementation of `mazegen` core.
- **Phase 3**: Integration of `curses` visualizer.
- **Phase 4**: Strict compliance checks (MyPy/Flake8) and cleanup.

**Tools Used:**
- **Git**: Version control.
- **Flake8**: Style enforcement.
- **MyPy**: Static type checking.
- **Make**: Automation.

## Resources
- [Recursive Backtracker (Wikipedia)](https://en.wikipedia.org/wiki/Maze_generation_algorithm#Recursive_backtracker)
- [Curses Programming with Python](https://docs.python.org/3/howto/curses.html)
- [Setuptools/Wheel Documentation](https://setuptools.pypa.io/en/latest/userguide/quickstart.html)

**AI Usage**:
AI was used to:
- Draft the initial `setup.py` / `pyproject.toml` structure.
- Verify the hex bitmask logic for wall encoding.
- Debug `curses` rendering offsets.
