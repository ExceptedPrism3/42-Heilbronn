"""
Exercise 4: Raising Your Own Errors.
Validates input constraints and raises exceptions for invalid states.
"""


def check_plant_health(plant_name: str,
                       water_level: int,
                       sunlight_hours: int) -> None:
    """
    Checks if plant conditions are within valid ranges.

    Args:
        plant_name (str): Name of the plant.
        water_level (int): Water level (1-10).
        sunlight_hours (int): Sunlight hours (2-12).

    Raises:
        ValueError: If any condition is invalid.
    """
    if not plant_name:
        raise ValueError("Plant name cannot be empty!")

    if not (1 <= water_level <= 10):
        raise ValueError(
            f"Water level {water_level} is too high (max 10)"
            if water_level > 10 else
            f"Water level {water_level} is too low (min 1)"
        )

    if not (2 <= sunlight_hours <= 12):
        raise ValueError(
            f"Sunlight hours {sunlight_hours} is too low (min 2)"
            if sunlight_hours < 2 else
            f"Sunlight hours {sunlight_hours} is too high (max 12)"
        )

    print(f"Plant '{plant_name}' is healthy!")


def test_plant_checks() -> None:
    """
    Tests various invalid conditions to ensure errors are raised correctly.
    """
    print("=== Garden Plant Health Checker ===")

    print("\nTesting good values...")
    try:
        check_plant_health("tomato", 5, 8)
    except ValueError as e:
        print(f"Unexpected error: {e}")

    print("\nTesting empty plant name...")
    try:
        check_plant_health("", 5, 8)
    except ValueError as e:
        print(f"Error: {e}")

    print("\nTesting bad water level...")
    try:
        check_plant_health("lettuce", 15, 8)
    except ValueError as e:
        print(f"Error: {e}")

    print("\nTesting bad sunlight hours...")
    try:
        check_plant_health("fern", 5, 0)
    except ValueError as e:
        print(f"Error: {e}")

    print("\nAll error raising tests completed!")


if __name__ == "__main__":
    test_plant_checks()
