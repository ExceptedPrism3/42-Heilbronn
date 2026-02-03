import functools
import operator
from typing import Dict, Callable, Any

# Exercise 3: Ancient Library

def spell_reducer(spells: list[int], operation: str) -> int:
    """Reduces a list of spell powers using specified operation."""
    ops = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": max,
        "min": min
    }
    if operation not in ops:
        raise ValueError("Unknown operation")

    if not spells:
        raise ValueError("No spells to reduce")

    return functools.reduce(ops[operation], spells)

def partial_enchanter(base_enchantment: Callable) -> Dict[str, Callable]:
    """Creates partial applications of base enchantment."""
    return {
        'fire_enchant': functools.partial(base_enchantment, power=50, element='fire'),
        'ice_enchant': functools.partial(base_enchantment, power=50, element='ice'),
        'lightning_enchant': functools.partial(base_enchantment, power=50, element='lightning')
    }

@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    """Calculates Fibonacci with memoization."""
    if n < 2:
        return n
    return memoized_fibonacci(n-1) + memoized_fibonacci(n-2)

def spell_dispatcher() -> Callable:
    """Create single dispatch system."""
    @functools.singledispatch
    def dispatcher(data: Any) -> str:
        return "Unknown spell type"

    @dispatcher.register
    def _(data: int) -> str:
        return f"Dealing {data} damage"

    @dispatcher.register
    def _(data: str) -> str:
        return f"Enchanting with {data}"

    @dispatcher.register
    def _(data: list) -> str:
        return f"Casting multi-spell on {len(data)} targets"
        
    return dispatcher

if __name__ == "__main__":
    print("Testing spell reducer...")
    nums = [10, 20, 30, 40]
    print(f"Sum: {spell_reducer(nums, 'add')}")
    print(f"Product: {spell_reducer(nums, 'multiply')}")
    print(f"Max: {spell_reducer(nums, 'max')}")
    
    print("\nTesting memoized fibonacci...")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")
