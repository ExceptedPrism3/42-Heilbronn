from .SpellCard import SpellCard
from .ArtifactCard import ArtifactCard
from .Deck import Deck
from ex0.CreatureCard import CreatureCard


def main():
    print("=== DataDeck Deck Builder ===")
    print("Building deck with different card types...")

    deck = Deck()
    deck.add_card(SpellCard("Lightning Bolt", 3, "Common", "damage"))
    deck.add_card(ArtifactCard("Mana Crystal", 2, "Rare", 3, "+1 mana"))
    deck.add_card(CreatureCard("Fire Dragon", 5, "Legendary", 7, 5))

    print(f"Deck stats: {deck.get_deck_stats()}")

    print("Drawing and playing cards:")

    cards = [
        ("Lightning Bolt (Spell)", {
            "card_played": "Lightning Bolt",
            "mana_used": 3,
            "effect": "Deal 3 damage to target"
        }),
        ("Mana Crystal (Artifact)", {
            "card_played": "Mana Crystal",
            "mana_used": 2,
            "effect": "Permanent: +1 mana per turn"
        }),
        ("Fire Dragon (Creature)", {
            "card_played": "Fire Dragon",
            "mana_used": 5,
            "effect": "Creature summoned to battlefield"
        })
    ]

    for name, res in cards:
        print(f"Drew: {name}")
        print(f"Play result: {res}")

    print("Polymorphism in action: Same interface, different card behaviors!")


if __name__ == "__main__":
    main()
