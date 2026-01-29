
"""
Exercise 1: Import Transmutation.
Demonstrates various import styles.
"""
print("=== Import Transmutation Mastery ===")

try:
    print("Method 1 - Full module import:")
    import alchemy.elements
    print(f"alchemy.elements.create_fire(): {alchemy.elements.create_fire()}")

    print("Method 2 - Specific function import:")
    from alchemy.elements import create_water
    print(f"create_water(): {create_water()}")

    print("Method 3 - Aliased import:")
    from alchemy.potions import healing_potion as heal
    print(f"heal(): {heal()}")

    print("Method 4 - Multiple imports:")
    from alchemy.elements import create_earth, create_fire
    from alchemy.potions import strength_potion
    print(f"create_earth(): {create_earth()}")
    print(f"create_fire(): {create_fire()}")
    # Assuming strength_potion uses these internally, we just call it
    print(f"strength_potion(): {strength_potion()}")

    print("All import transmutation methods mastered!")

except ImportError as e:
    print(f"Import Error: {e}")
except Exception as e:
    print(f"Execution Error: {e}")
