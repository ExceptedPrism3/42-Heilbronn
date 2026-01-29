def record_spell(spell_name: str, ingredients: str) -> str:
    # Late import to avoid circular dependency
    from .validator import validate_ingredients

    validation = validate_ingredients(ingredients)
    if "VALID" in validation and "INVALID" not in validation:
        return f"Spell recorded: {spell_name} ({validation})"
    else:
        return f"Spell rejected: {spell_name} ({validation})"
