PYTHON ?= python3

# Root project files
PY_SRC = main.py parser.py models.py pathfinder.py simulator.py visualizer.py
LINT_EXCLUDE = .venv,.mypy_cache,.pytest_cache,__pycache__,.git

.PHONY: install run debug clean lint lint-strict test-maps

install:
	$(PYTHON) -m pip install --upgrade pip
	$(PYTHON) -m pip install flake8 mypy

run:
	$(PYTHON) main.py maps/easy/01_linear_path.txt

debug:
	$(PYTHON) -m pdb main.py maps/easy/01_linear_path.txt

clean:
	rm -rf __pycache__ .mypy_cache .pytest_cache
	find . -type d -name "__pycache__" -prune -exec rm -rf {} \;

lint:
	flake8 $(PY_SRC)
	mypy $(PY_SRC) --warn-return-any --warn-unused-ignores \
		--ignore-missing-imports --disallow-untyped-defs \
		--check-untyped-defs

lint-strict:
	flake8 $(PY_SRC)
	mypy $(PY_SRC) --strict

test-maps:
	@for m in maps/easy/*.txt maps/medium/*.txt maps/hard/*.txt; do \
		echo "== $$m =="; \
		$(PYTHON) main.py "$$m" --stats || exit 1; \
	done
