from typing import List, Any


class Plant:
    """
    Represents a generic plant with a name and height.

    Attributes:
        name (str): The name of the plant.
        height (int): The height of the plant in centimeters.
    """

    def __init__(self, name: str, height: int) -> None:
        """
        Initialize a Plant instance.

        Args:
            name (str): The name of the plant.
            height (int): The height of the plant in centimeters.
        """
        self.name = name
        self.height = height

    def grow(self, cm: int) -> None:
        """
        Increase the height of the plant.

        Args:
            cm (int): The number of centimeters the plant grows by.

        Prints:
            A message indicating how much the plant grew.
        """
        self.height += cm
        print(f"{self.name} grew {cm}cm")


class FloweringPlant(Plant):
    """
    Represents a flowering plant, which is a subclass of Plant.

    Attributes:
        name (str): The name of the plant.
        height (int): The height of the plant in centimeters.
        color (str): The color of the plant's flowers.
    """

    def __init__(self, name: str, height: int, color: str) -> None:
        """
        Initialize a FloweringPlant instance.

        Args:
            name (str): The name of the plant.
            height (int): The height of the plant in centimeters.
            color (str): The color of the flowers.
        """
        super().__init__(name, height)
        self.color = color


class PrizeFlower(FloweringPlant):
    """
    Represents a prize-winning flower, subclass of FloweringPlant.

    Attributes:
        name (str): The name of the flower.
        height (int): The height of the flower in centimeters.
        color (str): The color of the flower.
        points (int): The prize points awarded to this flower.
    """

    def __init__(self, name: str, h: int, color: str, points: int) -> None:
        """
        Initialize a PrizeFlower instance.

        Args:
            name (str): The name of the flower.
            h (int): The height of the flower in centimeters.
            color (str): The color of the flower.
            points (int): The prize points awarded to this flower.
        """
        super().__init__(name, h, color)
        self.points = points

    def __str__(self) -> str:
        """
        Return a string representation of the PrizeFlower.

        Returns:
            str: A description including name, height, color, and prize points.
        """
        return (f"{self.name}: {self.height}cm, {self.color} flowers "
                f"(blooming), Prize points: {self.points}")


class GardenManager:
    """
    Manages a collection of plants in a garden.

    Attributes:
        total_gardens (int): Class-level count of all gardens created.
        owner (str): Name of the garden owner.
        plants (List[Any]): List of plants in the garden.
        stats (GardenStats): Instance to calculate garden statistics.
    """

    total_gardens = 0

    class GardenStats:
        """
        Provides statistical calculations for a garden.

        Methods:
            calculate_score(plants): Computes a score based
            on plant heights and prize points.
        """

        def calculate_score(self, plants: List[Any]) -> int:
            """
            Calculate the total score for a list of plants.

            Each plant contributes its height to the score. PrizeFlower plants
            contribute additional points multiplied by 10.

            Args:
                plants (List[Any]): List of Plant or FloweringPlant instances.

            Returns:
                int: Total garden score.
            """
            score = 0
            for p in plants:
                score += p.height
                if hasattr(p, 'points'):
                    score += p.points * 10
            return score

    def __init__(self, owner: str) -> None:
        """
        Initialize a GardenManager instance.

        Args:
            owner (str): Name of the garden owner.
        """
        self.owner = owner
        self.plants: List[Any] = []
        self.stats = self.GardenStats()
        GardenManager.total_gardens += 1

    def add_plant(self, plant: Any) -> None:
        """
        Add a plant to the garden.

        Args:
            plant (Any): A Plant, FloweringPlant, or PrizeFlower instance.

        Prints:
            A message confirming the addition of the plant.
        """
        self.plants.append(plant)
        print(f"Added {plant.name} to {self.owner}'s garden")

    def grow_all(self) -> None:
        """
        Grow all plants in the garden by 1 cm.

        Prints:
            Messages indicating that each plant has grown.
        """
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            plant.grow(1)

    def generate_report(self) -> None:
        """
        Generate and print a detailed report of the garden.

        Includes:
            - List of all plants with height and flower info
            - Total number of plants
            - Calculated garden score
        """
        print(f"=== {self.owner}'s Garden Report ===")
        print("Plants in garden:")
        for p in self.plants:
            if isinstance(p, PrizeFlower):
                print(p)
            elif isinstance(p, FloweringPlant):
                print(f"{p.name}: {p.height}cm, {p.color} flowers (blooming)")
            else:
                print(f"{p.name}: {p.height}cm")

        print(f"Plants added: {len(self.plants)}")

        score = self.stats.calculate_score(self.plants)
        print(f"Garden score for {self.owner}: {score}")

    @classmethod
    def create_garden_network(cls, owners: List[str]) -> List['GardenManager']:
        """
        Create a list of GardenManager instances for multiple owners.

        Args:
            owners (List[str]): List of garden owner names.

        Returns:
            List[GardenManager]: List of initialized GardenManager objects.
        """
        return [cls(owner) for owner in owners]

    @staticmethod
    def validate_height(height: int) -> bool:
        """
        Validate that a plant height is non-negative.

        Args:
            height (int): Height value to validate.

        Returns:
            bool: True if height is 0 or greater, False otherwise.
        """
        return height >= 0


def main() -> None:
    """
    Demonstrate usage of the Garden Management System.

    - Creates gardens for owners
    - Adds plants to gardens
    - Grows plants
    - Generates garden reports
    - Validates plant heights
    - Displays garden scores
    """
    print("=== Garden Management System Demo ===\n")

    alice_garden = GardenManager("Alice")

    p1 = Plant("Oak Tree", 100)
    p2 = FloweringPlant("Rose", 25, "red")
    p3 = PrizeFlower("Sunflower", 50, "yellow", 10)

    alice_garden.add_plant(p1)
    alice_garden.add_plant(p2)
    alice_garden.add_plant(p3)

    alice_garden.grow_all()
    alice_garden.generate_report()

    print(f"Height validation test: {GardenManager.validate_height(10)}")

    bob_garden = GardenManager("Bob")
    bob_garden.add_plant(Plant("Bush", 90))
    bob_score = bob_garden.stats.calculate_score(bob_garden.plants)

    print(f"Garden scores Alice: "
          f"{alice_garden.stats.calculate_score(alice_garden.plants)}, "
          f"Bob: {bob_score}")
    print(f"Total gardens managed: {GardenManager.total_gardens}")


if __name__ == "__main__":
    main()
