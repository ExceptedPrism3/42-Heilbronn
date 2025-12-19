def ft_seed_inventory(vegetable_seed: str, amount: int, unit: str):
    if unit == "packets":
        print(f'{vegetable_seed.capitalize()} seeds:'
              f' {amount} packets available')
    elif unit == "grams":
        print(f'{vegetable_seed.capitalize()} seeds: {amount} grams total')
    elif unit == "area":
        name = vegetable_seed.capitalize()
        print(f'{name} seeds: covers {amount} square meters')
    else:
        print('Unknown unit type')
