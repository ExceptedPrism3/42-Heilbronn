import importlib
import time


def check_package(name, display_name=None):
    if display_name is None:
        display_name = name

    try:
        if name == "numpy":
            import numpy as pkg
            version = pkg.__version__
        elif name == "pandas":
            import pandas as pkg
            version = pkg.__version__
        elif name == "matplotlib":
            import matplotlib as pkg
            version = pkg.__version__
        elif name == "requests":
            import requests as pkg
            version = pkg.__version__
        else:
            pkg = importlib.import_module(name)
            version = getattr(pkg, "__version__", "unknown")

        print(f"[OK] {display_name} ({version}) - Ready")
        return True
    except ImportError:
        print(f"[KO] {display_name} - Missing "
              "(Install via pip install -r requirements.txt)")
        return False


def main():
    print("LOADING STATUS: Loading programs...")
    print("Checking dependencies:")

    deps = [
        ("pandas", "Data manipulation ready"),
        ("requests", "Network access ready"),
        ("matplotlib", "Visualization ready")
    ]

    all_ok = True
    for pkg, desc in deps:
        if not check_package(pkg, display_name=pkg):
            all_ok = False

    if all_ok:
        print("Analyzing Matrix data...")
        # Simulate work
        time.sleep(0.5)
        print("Processing 1000 data points...")
        time.sleep(0.5)
        print("Generating visualization...")
        print("Analysis complete!")
        print("Results saved to: matrix_analysis.png")


if __name__ == "__main__":
    main()
