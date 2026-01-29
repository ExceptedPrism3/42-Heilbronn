"""Coordinate System module."""

import math


def main() -> None:
    """Demonstrate 3D coordinate system using tuples."""
    print("=== Game Coordinate System ===")

    p1 = (10, 20, 5)
    print(f"Position created: {p1}")

    def calc_distance(p: tuple) -> float:
        """Calculate euclidean distance."""
        return math.sqrt(p[0]**2 + p[1]**2 + p[2]**2)

    dist = calc_distance(p1)
    print(f"Distance between (0, 0, 0) and {p1}: {dist:.2f}")

    print('Parsing coordinates: "3,4,0"')
    p2 = (3, 4, 0)
    print(f"Parsed position: {p2}")
    print(f"Distance between (0, 0, 0) and {p2}: {calc_distance(p2):.1f}")

    print('Parsing invalid coordinates: "abc,def,ghi"')
    try:
        int("abc")
    except ValueError as e:
        print(f"Error parsing coordinates: {e}")
        # type() forbidden. Use __class__.__name__
        print(f"Error details - Type: {e.__class__.__name__}, Args: {e.args}")

    print("Unpacking demonstration:")
    x, y, z = (3, 4, 0)
    print(f"Player at x={x}, y={y}, z={z}")
    print(f"Coordinates: X={x}, Y={y}, Z={z}")


if __name__ == "__main__":
    main()
