import sys
import os


def detect_environment():
    in_venv = (sys.prefix != sys.base_prefix)
    in_venv = in_venv or (os.environ.get("VIRTUAL_ENV") is not None)

    current_prefix = sys.prefix

    print(f"Current Python: {sys.executable}")

    if in_venv:
        print("MATRIX STATUS: Welcome to the construct")
        print(f"Virtual Environment: {os.path.basename(current_prefix)}")
        print(f"Environment Path: {current_prefix}")
        print("SUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting the global system.")

        site_packages = os.path.join(
            current_prefix,
            "lib",
            f"python{sys.version_info.major}.{sys.version_info.minor}",
            "site-packages"
        )
        print("Package installation path:")
        print(site_packages)

    else:
        print("MATRIX STATUS: You're still plugged in")
        print("Virtual Environment: None detected")
        print("WARNING: You're in the global environment!")
        print("The machines can see everything you install.")
        print("To enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate # On Unix")
        print("matrix_env\\Scripts\\activate # On Windows")
        print("Then run this program again.")


if __name__ == "__main__":
    detect_environment()
