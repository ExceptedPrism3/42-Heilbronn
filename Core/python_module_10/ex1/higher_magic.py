from typing import Callable, List, Tuple, Any

# Exercise 1: Higher Realm

def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    """Combines two spells into one that returns a tuple of results."""
    def combined(*args: Any, **kwargs: Any) -> Tuple[Any, Any]:
        return spell1(*args, **kwargs), spell2(*args, **kwargs)
    return combined

def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    """Amplifies the numeric result of a spell."""
    def amplified(*args: Any, **kwargs: Any) -> int:
        return base_spell(*args, **kwargs) * multiplier
    return amplified

def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    """Casts spell only if condition is met."""
    def cast(*args: Any, **kwargs: Any) -> Any:
        if condition(*args, **kwargs):
            return spell(*args, **kwargs)
        return "Spell fizzled"
    return cast

def spell_sequence(spells: List[Callable]) -> Callable:
    """Executes a sequence of spells."""
    def sequence(*args: Any, **kwargs: Any) -> List[Any]:
        return [spell(*args, **kwargs) for spell in spells]
    return sequence

if __name__ == "__main__":
    print("Testing spell combiner...")
    def fireball(target: str) -> str: return f"Fireball hits {target}"
    def heal(target: str) -> str: return f"Heals {target}"
    
    combo = spell_combiner(fireball, heal)
    print(f"Combined spell result: {combo('Dragon')}")
    
    print("\nTesting power amplifier...")
    def damage(x: Any) -> int: return 10
    mega = power_amplifier(damage, 3)
    print(f"Original: {damage(None)}, Amplified: {mega(None)}")
