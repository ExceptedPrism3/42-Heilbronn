"""Archive extraction module."""


def main():
    """Extract and display archive content."""
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    try:
        with open("ancient_fragment.txt", "r") as f:
            content = f.read()
            print(content)
    except FileNotFoundError:
        print("Error: ancient_fragment.txt not found.")


if __name__ == "__main__":
    main()
