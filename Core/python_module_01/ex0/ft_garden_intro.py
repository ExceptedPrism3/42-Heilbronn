"""
Simple script to display basic information about a single plant.

Prints the plant's name, height, and age to the console.
"""


def main():
    """Display the plant details in a simple garden report."""
    plant_name: str = "Rose"
    plant_height: int = 25
    plant_age: int = 30

    print("=== Welcome to My Garden ===")
    print(f'Plant: {plant_name}')
    print(f'Height: {plant_height}cm')
    print(f'Age: {plant_age} days')

    print("\n=== End of Program ===")


if __name__ == "__main__":
    main()
