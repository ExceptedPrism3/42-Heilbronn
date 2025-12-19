class Plant:
    """
    Represents a plant that can grow and age over time.

    Attributes:
        name (str): The name of the plant.
        height (int): The current height of the plant in centimeters.
        age (int): The current age of the plant in days.
    """

    def __init__(self, name: str, height: int, age: int) -> None:
        """
        Initialize a new Plant instance.

        Args:
            name (str): The name of the plant.
            height (int): The initial height of the plant in centimeters.
            age (int): The initial age of the plant in days.
        """
        self.name = name
        self.height = height
        self.age = age

    def grow(self, cm: int) -> None:
        """
        Increase the plant's height.

        Args:
            cm (int): The number of centimeters the plant grows.
        """
        self.height += cm

    def age_plant(self, days: int) -> None:
        """
        Increase the plant's age.

        Args:
            days (int): The number of days to add to the plant's age.
        """
        self.age += days

    def get_info(self) -> str:
        """
        Get a formatted description of the plant.

        Returns:
            str: A string describing the plant's name, height, and age.
        """
        return f"{self.name}: {self.height}cm, {self.age} days old"


def main() -> None:
    """
    Run a simple plant growth simulation.

    Creates a Plant instance and simulates its growth over
    several days, then displays the results.
    """
    rose = Plant("Rose", 25, 30)

    print("=== Day 1 ===")
    print(rose.get_info())

    growth_per_day = 1
    days_passed = 6

    for _ in range(days_passed):
        rose.grow(growth_per_day)
        rose.age_plant(1)

    print(f'=== Day {1 + days_passed} ===')
    print(rose.get_info())
    print(f'Growth this week: +{growth_per_day * days_passed}cm')


if __name__ == "__main__":
    main()
