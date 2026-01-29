"""
Exercise 5: Garden Management System.
A comprehensive system combining all error handling techniques.
"""
from typing import List, Dict


# Custom Exceptions (Re-defined here for standalone file execution)
class GardenError(Exception):
    """Base class for garden errors."""
    pass


class PlantError(GardenError):
    """Error related to specific plants."""
    pass


class WaterError(GardenError):
    """Error related to watering."""
    pass


class GardenManager:
    """
    Manages a collection of plants with robust error handling.
    """
    def __init__(self) -> None:
        """Initialize the garden manager with empty plant lists."""
        self.plants: List[str] = []
        self.plant_stats: Dict[str, dict] = {}

    def add_plant(self, name: str) -> None:
        """Adds a plant if the name is valid."""
        try:
            if not name:
                raise ValueError("Plant name cannot be empty!")
            self.plants.append(name)
            # Default stats
            self.plant_stats[name] = {"water": 5, "sun": 8}
            print(f"Added {name} successfully")
        except ValueError as e:
            print(f"Error adding plant: {e}")

    def water_plants(self) -> None:
        """Waters all plants with cleanup in finally block."""
        print("Opening watering system")
        try:
            for plant in self.plants:
                print(f"Watering {plant} ... success")
            # Simulate a random system failure check
            # (Logic implied by prompt regarding recovering from failures)
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(self, name: str, water: int, sun: int) -> None:
        """Checks health constraints for a specific plant."""
        try:
            if water > 10:
                raise PlantError(
                    f"Water level {water} is too high (max 10)"
                )
            if sun < 2:
                raise PlantError(
                    f"Sunlight hours {sun} is too low (min 2)"
                )
            print(f"{name}: healthy (water: {water}, sun: {sun})")
        except PlantError as e:
            print(f"Error checking {name}: {e}")

    def emergency_stop(self) -> None:
        """Simulates a critical error."""
        raise GardenError("Not enough water in tank")


def test_garden_management() -> None:
    """Main execution of the Garden Management System."""
    print("=== Garden Management System ===")
    manager = GardenManager()

    print("\nAdding plants to garden...")
    manager.add_plant("tomato")
    manager.add_plant("lettuce")
    manager.add_plant("")  # Triggers error

    print("\nWatering plants...")
    manager.water_plants()

    print("\nChecking plant health...")
    # Valid check
    manager.check_plant_health("tomato", 5, 8)
    # Invalid check
    manager.check_plant_health("lettuce", 15, 8)

    print("\nTesting error recovery...")
    try:
        manager.emergency_stop()
    except GardenError as e:
        print(f"Caught GardenError: {e}")
        print("System recovered and continuing...")

    print("\nGarden management system test complete!")


if __name__ == "__main__":
    test_garden_management()
