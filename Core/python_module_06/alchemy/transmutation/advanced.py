from .basic import lead_to_gold
from ..potions import healing_potion


def philosophers_stone():
    try:
        gold_res = lead_to_gold()
        heal_res = healing_potion()
        return (f"Philosopher's stone created using {gold_res} "
                f"and {heal_res}")
    except Exception as e:
        return f"Philosopher's stone failed: {e}"


def elixir_of_life():
    return "Elixir of life: eternal youth achieved!"
