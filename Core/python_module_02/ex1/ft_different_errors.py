"""
Exercise 1: Different Types of Problems.
Demonstrates handling of specific built-in Python exceptions.
"""


def garden_operations(test_type: str) -> None:
    """
    Simulates various garden operation errors based on input type.

    Args:
        test_type (str): The type of error to trigger.
    """
    try:
        if test_type == "value":
            print("Testing ValueError...")
            # Trigger ValueError
            raise ValueError("invalid literal for int() with base 10: 'abc'")
        elif test_type == "zero":
            print("Testing ZeroDivisionError...")
            # Trigger ZeroDivisionError
            _ = 10 / 0
        elif test_type == "file":
            print("Testing FileNotFoundError...")
            # Trigger FileNotFoundError
            open("missing.txt", "r")
        elif test_type == "key":
            print("Testing KeyError...")
            my_dict = {"rose": "red"}
            # Trigger KeyError
            _ = my_dict["missing_plant"]
        elif test_type == "multi":
            print("Testing multiple errors together...")
            # Trigger an arbitrary error to be caught by generic except
            raise ValueError(
                "invalid literal for int() with base 10: 'invalid'"
            )

    except ValueError as e:
        print(f"Caught ValueError: {e}")
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}")
    except FileNotFoundError as e:
        print(f"Caught FileNotFoundError: {e}")
    except KeyError as e:
        print(f"Caught KeyError: {e}")
    except Exception:
        print("Caught an error, but program continues!")


def test_error_types() -> None:
    """
    Runs a sequence of tests to show robustness against different crashes.
    """
    print("=== Garden Error Types Demo ===")

    garden_operations("value")
    print()
    garden_operations("zero")
    print()
    garden_operations("file")
    print()
    garden_operations("key")
    print()
    garden_operations("multi")

    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
