"""Score Analytics module."""

import sys


def main() -> None:
    """Process and analyze scores from command line."""
    print("=== Player Score Analytics ===")

    args = sys.argv[1:]
    if not args:
        print(f"No scores provided. Usage: python3 {sys.argv[0]} <score1> ...")
        return

    try:
        scores = [int(arg) for arg in args]
    except ValueError:
        print("Error: Scores must be numbers.")
        return

    print(f"Scores processed: {scores}")
    print(f"Total players: {len(scores)}")
    print(f"Total score: {sum(scores)}")
    print(f"Average score: {sum(scores) / len(scores)}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range: {max(scores) - min(scores)}")


if __name__ == "__main__":
    main()
