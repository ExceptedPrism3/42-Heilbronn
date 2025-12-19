"""
Demonstrates a Plant class with basic validation and controlled access
to internal state.

This script defines a SecurePlant class that enforces simple constraints
on plant attributes and logs invalid update attempts. A small test
routine exercises the class behavior.
"""


class SecurePlant:
    """
    Represents a plant with validated attributes.

    Height and age are stored as protected attributes and can only be
    modified through setter methods that enforce basic rules.
    """

    def __init__(self, name: str, height: int, age: int) -> None:
        """
        Initialize a SecurePlant instance.

        Sets the plant name and attempts to assign validated height
        and age values using setter methods.

        Args:
            name: The name of the plant.
            height: Initial height in centimeters.
            age: Initial age in days.
        """
        self.name = name
        self._height = 0
        self._age = 0

        self.set_height(height)
        self.set_age(age)
        print(f"Plant created: {self.name}")

    def set_height(self, height: int) -> None:
        """
        Update the plant's height.

        Rejects negative values and logs the failed attempt.

        Args:
            height: New height in centimeters.
        """
        if height < 0:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self._height = height

    def get_height(self) -> int:
        """
        Return the current height of the plant.

        Returns:
            The plant height in centimeters.
        """
        return self._height

    def set_age(self, age: int) -> None:
        """
        Update the plant's age.

        Rejects negative values.

        Args:
            age: New age in days.
        """
        if age < 0:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
        else:
            self._age = age

    def get_age(self) -> int:
        """
        Return the current age of the plant.

        Returns:
            The plant age in days.
        """
        return self._age

    def __str__(self) -> str:
        """
        Return a readable description of the plant.

        Returns:
            A string containing the plant's name, height, and age.
        """
        return f"{self.name} ({self._height}cm, {self._age} days)"


def main() -> None:
    """
    Entry point for the garden security demonstration.

    Creates a SecurePlant instance, performs valid and invalid updates,
    and displays the resulting state.
    """
    print("=== Garden Security System ===")

    rose = SecurePlant("Rose", 25, 30)
    print(f"Height updated: {rose.get_height()}cm [OK]")
    print(f"Age updated: {rose.get_age()} days [OK]")

    rose.set_height(-5)

    print(f"Current plant: {rose}")


if __name__ == "__main__":
    """
    Execute the demonstration when run as a script.
    """
    main()
