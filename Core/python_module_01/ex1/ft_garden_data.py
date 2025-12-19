class Plant:
    """
    Represents a plant with basic descriptive attributes.

    Attributes:
        name (str): The name of the plant.
        height (int): The height of the plant in centimeters.
        age (int): The age of the plant in days.
    """

    def __init__(self, name: str, height: int, age: int) -> None:
        """
        Initialize a new Plant instance.

        Args:
            name (str): The name of the plant.
            height (int): The height of the plant in centimeters.
            age (int): The age of the plant in days.
        """
        self.name = name
        self.height = height
        self.age = age

    def __str__(self) -> str:
        """
        Return a human-readable string representation of the plant.

        Returns:
            str: A formatted string describing the plant.
        """
        return f"{self.name}: {self.height}cm, {self.age} days old"


def main() -> None:
    """
    Main execution function of the program.

    Creates several Plant objects and displays their information
    as part of a simple garden plant registry.
    """
    print("=== Garden Plant Registry ===")
    print(Plant("Rose", 25, 30))
    print(Plant("Sunflower", 80, 45))
    print(Plant("Cactus", 15, 120))


if __name__ == "__main__":
    main()
