"""
Exercise 2: Making Your Own Error Types.
Defines custom exception classes for agricultural monitoring.
"""


class GardenError(Exception):
    """Base class for garden-related errors."""
    pass


class PlantError(GardenError):
    """Exception raised for plant health issues."""
    pass


class WaterError(GardenError):
    """Exception raised for watering system issues."""
    pass


def test_custom_errors() -> None:
    """
    Demonstrates raising and catching custom exception types.
    """
    print("=== Custom Garden Errors Demo ===")

    # Test 1: Catching a specific PlantError
    print("\nTesting PlantError...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    # Test 2: Catching a specific WaterError
    print("\nTesting WaterError...")
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    # Test 3: Catching via the base GardenError (Polymorphism)
    print("\nTesting catching all garden errors...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except GardenError as e:
        print(f"Caught a garden error: {e}")

    try:
        raise WaterError("Not enough water in the tank!")
    except GardenError as e:
        print(f"Caught a garden error: {e}")

    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    test_custom_errors()
