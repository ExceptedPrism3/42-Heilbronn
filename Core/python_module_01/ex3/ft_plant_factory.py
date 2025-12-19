"""
Creates and displays a small collection of Plant objects.

This script defines a simple Plant class and a main routine that
instantiates several plants from predefined data, prints each one,
and reports the total number created.
"""


class Plant:
    """
    Represents a plant with a name, height, and age.

    This class stores basic plant attributes and provides a string
    representation suitable for console output.
    """

    def __init__(self, name: str, height: int, age: int) -> None:
        """
        Initialize a Plant instance.

        Args:
            name: The name of the plant.
            height: The height of the plant in centimeters.
            age: The age of the plant in days.
        """
        self.name = name
        self.height = height
        self.age = age

    def __str__(self) -> str:
        """
        Return a human-readable description of the plant.

        Returns:
            A string containing the plant's name, height, and age.
        """
        return f'{self.name} ({self.height}cm, {self.age} days)'


def main() -> None:
    """
    Entry point for the Plant Factory script.

    Creates Plant objects from predefined seed data, prints each
    created plant, and displays the total count.
    """
    print("=== Plant Factory Output ===")

    seeds = [
        ("Rose", 25, 30),
        ("Oak", 200, 365),
        ("Cactus", 5, 90),
        ("Sunflower", 80, 45),
        ("Fern", 15, 120)
    ]

    plants = []

    for seed in seeds:
        new_plant = Plant(seed[0], seed[1], seed[2])
        plants.append(new_plant)
        print(f'Created: {new_plant}')

    print(f'\nTotal plants created: {len(plants)}')


if __name__ == "__main__":
    """
    Run the main function when the script is executed directly.
    """
    main()
