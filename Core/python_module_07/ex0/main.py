from .CreatureCard import CreatureCard


def main():
    print("=== DataDeck Card Foundation ===")
    print("Testing Abstract Base Class Design:")

    dragon = CreatureCard("Fire Dragon", 5, "Legendary", 7, 5)

    print("CreatureCard Info:")
    print(dragon.get_card_info())

    mana = 6
    print(f"Playing Fire Dragon with {mana} mana available:")
    print(f"Playable: {dragon.is_playable(mana)}")
    print(f"Play result: {dragon.play({})}")

    print("Fire Dragon attacks Goblin Warrior:")
    print(f"Attack result: {dragon.attack_target('Goblin Warrior')}")

    mana = 3
    print(f"Testing insufficient mana ({mana} available):")
    print(f"Playable: {dragon.is_playable(mana)}")
    print("Abstract pattern successfully demonstrated!")


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(f"Error: {e}")
