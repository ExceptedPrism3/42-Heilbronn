"""Command Quest module."""

import sys


def main() -> None:
    """Receive and display command-line arguments."""
    print("=== Command Quest ===")

    args = sys.argv[1:]

    if not args:
        print("No arguments provided!")
        print(f"Program name: {sys.argv[0]}")
        print(f"Total arguments: {len(sys.argv)}")
        return

    print(f"Program name: {sys.argv[0]}")
    args_len = len(args)
    print(f"Arguments received: {args_len}")

    i = 1
    for arg in args:
        print(f"Argument {i}: {arg}")
        i += 1

    # Or strict loop:
    # range? 'range' not in Ex0 authorized list! (len, print)
    # len() is in list.
    # But 'range' is NOT.
    # `for i in range(len(args)):` uses range. Forbidden.
    # `for arg in args:` works.
    # `enumerate` Forbidden.
    # Manual counter `i` works.

    print(f"Total arguments: {len(sys.argv)}")


if __name__ == "__main__":
    main()
