"""
Demonstrates inheritance with different types of plants.

Defines a base Plant class and three subclasses (Flower, Tree, Vegetable),
each with specialized attributes and behaviors. The script creates examples
of each type and prints their details to the console.
"""


class Plant:
    """
    Base class representing a generic plant.

    Stores basic plant information such as name, height, and age.
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

    def get_desc(self) -> str:
        """
        Return a short description of the plant.

        Returns:
            A string with the plant's name, height, and age.
        """
        return f"{self.name}: {self.height}cm, {self.age} days"


class Flower(Plant):
    """
    Represents a flower, subclass of Plant.

    Adds color and blooming behavior to the base Plant class.
    """

    def __init__(self, name: str, h: int, a: int, color: str) -> None:
        """
        Initialize a Flower instance.

        Args:
            name: The name of the flower.
            h: Height in centimeters.
            a: Age in days.
            color: Flower color.
        """
        super().__init__(name, h, a)
        self.color = color

    def bloom(self) -> None:
        """
        Print a message indicating that the flower is blooming.
        """
        print(f"{self.name} is blooming beautifully!\n")

    def __str__(self) -> str:
        """
        Return a detailed description of the flower.

        Returns:
            A string including the name, type, height, age, and color.
        """
        return (f"{self.name} (Flower): {self.height}cm, {self.age}"
                f" days, {self.color} color")


class Tree(Plant):
    """
    Represents a tree, subclass of Plant.

    Adds trunk diameter and shade production to the base Plant class.
    """

    def __init__(self, name: str, h: int, a: int, trunk: int) -> None:
        """
        Initialize a Tree instance.

        Args:
            name: The name of the tree.
            h: Height in centimeters.
            a: Age in days.
            trunk: Trunk diameter in centimeters.
        """
        super().__init__(name, h, a)
        self.trunk_diameter = trunk

    def produce_shade(self) -> int:
        """
        Calculate the amount of shade the tree provides.

        Returns:
            An integer representing the approximate shade area.
        """
        return int(self.height * 0.10 + self.trunk_diameter)

    def __str__(self) -> str:
        """
        Return a detailed description of the tree.

        Returns:
            A string including the name, type, height, age, and trunk diameter.
        """
        return (f"{self.name} (Tree): {self.height}cm, {self.age} days, "
                f"{self.trunk_diameter}cm diameter")


class Vegetable(Plant):
    """
    Represents a vegetable, subclass of Plant.

    Adds harvest season and nutritional value to the base Plant class.
    """

    def __init__(self, name: str, h: int, a: int, season: str) -> None:
        """
        Initialize a Vegetable instance.

        Args:
            name: The name of the vegetable.
            h: Height in centimeters.
            a: Age in days.
            season: Harvest season.
        """
        super().__init__(name, h, a)
        self.harvest_season = season
        self.nutritional_value = "Vitamin C"

    def __str__(self) -> str:
        """
        Return a detailed description of the vegetable.

        Returns:
            A string including the name, type, height, age, and harvest season.
        """
        return (f"{self.name} (Vegetable): {self.height}cm, {self.age} days, "
                f"{self.harvest_season} harvest")


def main() -> None:
    """
    Entry point for the garden demonstration.

    Creates examples of Flower, Tree, and Vegetable, prints their
    descriptions, and demonstrates class-specific behaviors.
    """
    print("=== Garden Plant Types ===\n")

    rose = Flower("Rose", 25, 30, "red")
    print(rose)
    rose.bloom()

    oak = Tree("Oak", 500, 1825, 50)
    print(oak)
    print(f"{oak.name} provide {oak.produce_shade()} square meters of shade\n")

    tomato = Vegetable("Tomato", 80, 90, "summer")
    print(tomato)
    print(f"{tomato.name} is rich in {tomato.nutritional_value}")


if __name__ == "__main__":
    """
    Run the garden demonstration when executed as a script.
    """
    main()
