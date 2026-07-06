*This project has been created as part of the 42 curriculum by aben-cad.*

# Fly-in

## Description

Fly-in is a turn-based drone routing simulator over a connected graph of zones.
The goal is to move all drones from `start_hub` to `end_hub` in as few turns as
possible while respecting:

- zone capacities (`max_drones`)
- connection capacities (`max_link_capacity`)
- zone movement costs (`normal`, `priority`, `restricted`, `blocked`)
- turn-by-turn movement and occupancy rules

The project is implemented in an object-oriented way with dedicated parser,
graph model, pathfinder, simulator, and visualizer components.

## Instructions

### Requirements

- Python 3.10+

### Run

```bash
python3 main.py maps/easy/01_linear_path.txt
python3 main.py maps/hard/03_ultimate_challenge.txt --stats
python3 main.py maps/medium/03_priority_puzzle.txt --visual --stats
```

### Makefile helpers

```bash
make install
make run
make debug
make clean
make lint
make lint-strict
```

## Algorithm Choices

The solution is a discrete-turn scheduler:

1. Parse map into a typed graph (`Zone`, `Edge`, `Graph`).
2. Use weighted shortest path (Dijkstra) per active drone each turn.
3. Schedule simultaneous moves with explicit capacity checks:
   - edge usage per turn
   - node occupancy after outgoing drones free slots
   - restricted-zone arrival reservation (next turn)
4. Apply movements and output per-turn lines in required format.

### Why this strategy

- Handles deadlocks better than a fixed precomputed route list.
- Adapts each turn to current occupancy and edge pressure.
- Keeps implementation understandable for peer review.

### Complexity

Let:

- `D` be number of active drones in a turn
- `V` zones, `E` edges

Per turn, shortest-path calls dominate: approximately
`O(D * (E log V))` with binary heap Dijkstra.

Memory:

- Graph storage: `O(V + E)`
- Drone states: `O(D)`
- Turn-local scheduling maps: `O(V + E)`

## Visual Representation

The simulator supports `--visual`:

- Movement tokens on **stdout** stay in the required `D<ID>-<zone>` format.
- Zone colors from map metadata are applied to zone names (and connection names
  built from colored endpoints).
- Turn summaries are printed on **stderr** so automated output checks on stdout
  remain valid.

Example:

```bash
python3 main.py maps/medium/03_priority_puzzle.txt --visual --stats
```

## AI Usage

AI was used for:

- scaffolding project architecture
- drafting parser/scheduler implementation
- refining typing/docstrings/lint compliance
- generating and checking edge-case handling logic

All generated code was reviewed, tested, and adjusted manually.

## Resources

- [Python argparse docs](https://docs.python.org/3/library/argparse.html)
- [Python dataclasses docs](https://docs.python.org/3/library/dataclasses.html)
- [Python heapq docs](https://docs.python.org/3/library/heapq.html)
- [PEP 257 – Docstring Conventions](https://peps.python.org/pep-0257/)
- [mypy docs](https://mypy.readthedocs.io/en/stable/)
- [flake8 docs](https://flake8.pycqa.org/en/latest/)
