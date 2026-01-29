
"""
Exercise 3: Circular Curse.
Demonstrates circular dependency avoidance.
"""
print("=== Circular Curse Breaking ===")
print("Testing ingredient validation:")

from alchemy.grimoire.validator import validate_ingredients  # noqa: E402
print(f'validate_ingredients("fire air"): '
      f'{validate_ingredients("fire air")}')
print(f'validate_ingredients("dragon scales"): '
      f'{validate_ingredients("dragon scales")}')

print("Testing spell recording with validation:")
from alchemy.grimoire.spellbook import record_spell  # noqa: E402

print(f'record_spell("Fireball", "fire air"): '
      f'{record_spell("Fireball", "fire air")}')
print(f'record_spell("Dark Magic", "shadow"): '
      f'{record_spell("Dark Magic", "shadow")}')

print("Testing late import technique:")
print(f'record_spell("Lightning", "air"): '
      f'{record_spell("Lightning", "air")}')

print("Circular dependency curse avoided using late imports!")
print("All spells processed safely!")
