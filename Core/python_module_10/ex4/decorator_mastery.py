import functools
from datetime import datetime
from typing import Callable, Any

# Exercise 4: Master's Tower

def spell_timer(func: Callable) -> Callable:
    """Decorator to time spell broadcasting."""
    @functools.wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")
        start = datetime.now()
        result = func(*args, **kwargs)
        end = datetime.now()
        duration = (end - start).total_seconds()
        print(f"Spell completed in {duration:.3f} seconds")
        return result
    return wrapper

def power_validator(min_power: int) -> Callable:
    """Decorator factory to validate power level."""
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            power = kwargs.get('power')
            if power is None:
                # Heuristic: Find first int argument
                for arg in args:
                    if isinstance(arg, int):
                        power = arg
                        break
            
            if power is not None and power < min_power:
                return "Insufficient power for this spell"
            return func(*args, **kwargs)
        return wrapper
    return decorator

def retry_spell(max_attempts: int) -> Callable:
    """Decorator to retry failed spells."""
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for i in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    print(f"Spell failed, retrying... (attempt {i}/{max_attempts})")
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator

class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return len(name) >= 3 and name.replace(" ", "").isalpha()

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with power {power}"

if __name__ == "__main__":
    print("Testing spell timer...")
    @spell_timer
    def fireball() -> str:
        # Simulate work
        _ = [i*i for i in range(100000)]
        return "Fireball cast!"
    
    print(f"Result: {fireball()}")
    
    print("\nTesting MageGuild...")
    print(MageGuild.validate_mage_name("Gandalf"))
    print(MageGuild.validate_mage_name("A"))
    
    guild = MageGuild()
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Lightning", 5))
