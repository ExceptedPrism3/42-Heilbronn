"""
Exercise 3: Finally Block - Always Clean Up.
Ensures resource cleanup using the finally block.
"""
from typing import List, Optional


def water_plants(plant_list: List[Optional[str]]) -> None:
    """
    Simulates a watering cycle that must always close the system.

    Args:
        plant_list (list): A list of plant names (strings).
    """
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is None:
                raise ValueError("Cannot water None - invalid plant!")
            print(f"Watering {plant}")
        print("Watering completed successfully!")

    except ValueError as e:
        print(f"Error: {e}")

    finally:
        # This runs whether an error occurred or not
        print("Closing watering system (cleanup)")


def test_watering_system() -> None:
    """
    Tests the watering system with valid and invalid data.
    """
    print("=== Garden Watering System ===")

    print("\nTesting normal watering...")
    water_plants(["tomato", "lettuce", "carrots"])

    print("\nTesting with error...")
    # Passing None triggers the ValueError
    water_plants(["tomato", None])

    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
