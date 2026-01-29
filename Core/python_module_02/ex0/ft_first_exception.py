"""
Exercise 0: Agricultural Data Validation Pipeline.
This program validates temperature readings for a smart garden.
"""


def check_temperature(temp_str: str) -> int | None:
    """
    Validates if the input string is a number and within a safe range
    for plants (0-40).

    Args:
        temp_str (str): The temperature input as a string.

    Returns:
        int | None: The valid temperature integer, or None if invalid.
    """
    try:
        temp = int(temp_str)
        if temp > 40:
            print(f"Error: {temp}°C is too hot for plants (max 40°C)")
            return None
        elif temp < 0:
            print(f"Error: {temp}°C is too cold for plants (min 0°C)")
            return None
        else:
            print(f"Temperature {temp}°C is perfect for plants!")
            return temp
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number")
        return None


def test_temperature_input() -> None:
    """
    Runs various test cases to demonstrate validation logic.
    """
    print("=== Garden Temperature Checker ===")

    print("\nTesting temperature: 25")
    check_temperature("25")

    print("\nTesting temperature: abc")
    check_temperature("abc")

    print("\nTesting temperature: 100")
    check_temperature("100")

    print("\nTesting temperature: -50")
    check_temperature("-50")

    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature_input()
