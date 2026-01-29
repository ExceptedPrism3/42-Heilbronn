from .EliteCard import EliteCard


def main():
    print("=== DataDeck Ability System ===")
    print("EliteCard capabilities:")

    print("- Card: ['play','get_card_info','is_playable']")
    print("- Combatable: ['attack','defend','get_combat_stats']")
    print("- Magical: ['cast_spell','channel_mana','get_magic_stats']")

    card = EliteCard("Arcane Warrior", 5, "Rare")
    print("Playing Arcane Warrior (Elite Card):")

    print("Combat phase:")
    print(f"Attack result: {card.attack('Enemy')}")
    print(f"Defense result: {card.defend(5)}")

    print("Magic phase:")
    print(f"Spell cast: {card.cast_spell('Fireball', ['Enemy1', 'Enemy2'])}")
    print(f"Mana channel: {card.channel_mana(3)}")

    print("Multiple interface implementation successful!")


if __name__ == "__main__":
    main()
