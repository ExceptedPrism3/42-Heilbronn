"""
Exercise 0: Scared Scroll.
Demonstrates package exposure via __init__.py.
"""
import alchemy
import alchemy.elements

print("=== Sacred Scroll Mastery ===")
print("Testing direct module access:")
print(f"alchemy.elements.create_fire(): {alchemy.elements.create_fire()}")
print(f"alchemy.elements.create_water(): {alchemy.elements.create_water()}")
print(f"alchemy.elements.create_earth(): {alchemy.elements.create_earth()}")
print(f"alchemy.elements.create_air(): {alchemy.elements.create_air()}")

print("Testing package-level access (controlled by __init__.py):")
try:
    print(f"alchemy.create_fire(): {alchemy.create_fire()}")
except AttributeError as e:
    print(f"alchemy.create_fire(): AttributeError - {e}")

try:
    print(f"alchemy.create_water(): {alchemy.create_water()}")
except AttributeError as e:
    print(f"alchemy.create_water(): AttributeError - {e}")

try:
    print(f"alchemy.create_earth(): {alchemy.create_earth()}")
except AttributeError:
    print("alchemy.create_earth(): AttributeError - not exposed")

try:
    print(f"alchemy.create_air(): {alchemy.create_air()}")
except AttributeError:
    print("alchemy.create_air(): AttributeError - not exposed")

print("Package metadata:")
print(f"Version: {alchemy.__version__}")
print(f"Author: {alchemy.__author__}")
