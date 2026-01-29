from alchemy.elements import create_fire, create_earth


def lead_to_gold():
    try:
        f = create_fire()
        return f"Lead transmuted to gold using {f}"
    except Exception as e:
        return f"Lead transmutation failed: {e}"


def stone_to_gem():
    try:
        e = create_earth()
        return f"Stone transmuted to gem using {e}"
    except Exception as e:
        return f"Stone transmutation failed: {e}"
