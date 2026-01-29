
"""
Exercise 2: Pathway Debate.
Demonstrates absolute vs relative imports.
"""
from alchemy.transmutation.basic import lead_to_gold, stone_to_gem
from alchemy.transmutation.advanced import philosophers_stone, elixir_of_life
import alchemy.transmutation

print("=== Pathway Debate Mastery ===")

print("Testing Absolute Imports (from basic.py):")
print(f"lead_to_gold(): {lead_to_gold()}")
print(f"stone_to_gem(): {stone_to_gem()}")

print("Testing Relative Imports (from advanced.py):")
print(f"philosophers_stone(): {philosophers_stone()}")
print(f"elixir_of_life(): {elixir_of_life()}")

print("Testing Package Access:")
print(f"alchemy.transmutation.lead_to_gold(): "
      f"{alchemy.transmutation.lead_to_gold()}")
try:
    print(f"alchemy.transmutation.philosophers_stone(): "
          f"{alchemy.transmutation.philosophers_stone()}")
except AttributeError as e:
    print(f"Error accessing package level: {e}")

print("Both pathways work! Absolute: clear, Relative: concise")
