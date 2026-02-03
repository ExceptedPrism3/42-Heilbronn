from typing import Callable, Dict

# Exercise 2: Memory Depths

def mage_counter() -> Callable[[], int]:
    """Counts how many times it has been called."""
    count = 0
    def counter() -> int:
        nonlocal count
        count += 1
        return count
    return counter

def spell_accumulator(initial_power: int) -> Callable[[int], int]:
    """Accumulates power over multiple calls."""
    total_power = initial_power
    def add_power(power: int) -> int:
        nonlocal total_power
        total_power += power
        return total_power
    return add_power

def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:
    """Creates specific enchantment functions."""
    def enchant(item_name: str) -> str:
        return f"{enchantment_type} {item_name}"
    return enchant

def memory_vault() -> Dict[str, Callable]:
    """Secure memory storage using closures."""
    memory = {}
    
    def store(key: str, value: str) -> None:
        memory[key] = value
        
    def recall(key: str) -> str:
        return memory.get(key, "Memory not found")
        
    return {'store': store, 'recall': recall}

if __name__ == "__main__":
    print("Testing mage counter...")
    c = mage_counter()
    print(f"Call 1: {c()}")
    print(f"Call 2: {c()}")
    print(f"Call 3: {c()}")
    
    print("\nTesting enchantment factory...")
    fire = enchantment_factory("Flaming")
    ice = enchantment_factory("Frozen")
    print(fire("Sword"))
    print(ice("Shield"))
