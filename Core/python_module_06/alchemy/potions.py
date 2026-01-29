from .elements import (
    create_fire, create_water, create_earth, create_air
)


def healing_potion():
    try:
        f = create_fire()
        w = create_water()
        return f"Healing potion brewed with {f} and {w}"
    except Exception as e:
        return f"Healing potion failed: {e}"


def strength_potion():
    try:
        e = create_earth()
        f = create_fire()
        return f"Strength potion brewed with {e} and {f}"
    except Exception as e:
        return f"Strength potion failed: {e}"


def invisibility_potion():
    try:
        a = create_air()
        w = create_water()
        return f"Invisibility potion brewed with {a} and {w}"
    except Exception as e:
        return f"Invisibility potion failed: {e}"


def wisdom_potion():
    try:
        f = create_fire()
        w = create_water()
        e = create_earth()
        a = create_air()
        return (f"Wisdom potion brewed with all elements: "
                f"{f}, {w}, {e} and {a}")
    except Exception as e:
        return f"Wisdom potion failed: {e}"
