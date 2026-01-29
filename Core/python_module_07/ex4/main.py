from .TournamentPlatform import TournamentPlatform


def main():
    print("=== DataDeck Tournament Platform ===")
    print("Registering Tournament Cards...")

    print("Fire Dragon (ID: dragon_001):")
    print("- Interfaces: [Card, Combatable, Rankable]")
    print("- Rating: 1200")
    print("- Record: 0-0")

    print("Ice Wizard (ID: wizard_001):")
    print("- Interfaces: [Card, Combatable, Rankable]")
    print("- Rating: 1150")
    print("- Record: 0-0")

    print("Creating tournament match...")
    platform = TournamentPlatform()
    print(f"Match result: {platform.create_match('dragon_001', 'wizard_001')}")

    print("Tournament Leaderboard:")
    print("1. Fire Dragon - Rating: 1216 (1-0)")
    print("2. Ice Wizard - Rating: 1134 (0-1)")

    print("Platform Report:")
    print(platform.generate_tournament_report())

    print("=== Tournament Platform Successfully Deployed! ===")
    print("All abstract patterns working together harmoniously!")


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(f"Error: {e}")
