"""Stream management module."""


import sys


def main():
    """Manage IO streams."""
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")

    # Read from stdin
    # For testing, we assume input is piped or typed
    # "ARCH_7742" and "All systems nominal"

    try:
        print("Input Stream active. Enter archivist ID: ", end="", flush=True)
        arch_id = input()  # or sys.stdin.readline().strip()

        print("Input Stream active. Enter status report: ", end="", flush=True)
        status = input()

        # Standard Output
        print(f"[STANDARD] Archive status from {arch_id}: {status}")
        print("[STANDARD] Data transmission complete")

        # Error Output
        msg = "Communication channels verified"
        print(f"[ALERT] System diagnostic: {msg}", file=sys.stderr)

    except EOFError:
        pass


if __name__ == "__main__":
    main()
