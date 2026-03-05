install:
	uv sync

run:
	uv run python -m src

debug:
	uv run python -m pdb src/__main__.py

clean:
	rm -rf __pycache__ src/__pycache__ .mypy_cache .ruff_cache data/output/*
	find . -type d -name "__pycache__" -exec rm -r {} +
	find . -type d -name ".mypy_cache" -exec rm -r {} +

lint:
	uv run flake8 src/
	uv run mypy src/ --follow-imports=silent --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	uv run flake8 src/
	uv run mypy src/ --strict --follow-imports=silent

.PHONY: install run debug clean lint lint-strict
