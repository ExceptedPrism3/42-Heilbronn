.PHONY: all install build run debug lint clean fclean re

PYTHON = python3
PIP = pip

all: install

install:
	$(PIP) install --upgrade pip build setuptools wheel
	$(PIP) install -e .
	$(PIP) install flake8 mypy

build:
	$(PYTHON) -m build

run:
	$(PYTHON) a_maze_ing.py config.txt

debug:
	$(PYTHON) -m pdb a_maze_ing.py config.txt

lint:
	flake8 .
	mypy .

clean:
	rm -rf __pycache__
	rm -rf mazegen/__pycache__
	rm -rf build
	rm -rf *.egg-info
	rm -rf .mypy_cache
	find . -name "*.pyc" -delete

fclean: clean
	rm -rf dist
	rm -rf .venv
	rm -rf output.txt

re: fclean install
