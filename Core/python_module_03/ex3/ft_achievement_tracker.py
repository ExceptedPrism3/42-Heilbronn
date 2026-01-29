"""Achievement tracking module."""


def main() -> None:
    """Track and analyze unique achievements."""
    print("=== Achievement Tracker System ===")

    alice = {'first_kill', 'level_10', 'treasure_hunter', 'speed_demon'}
    bob = {'first_kill', 'level_10', 'boss_slayer', 'collector'}
    charlie = {'level_10', 'treasure_hunter', 'boss_slayer',
               'speed_demon', 'perfectionist'}

    print(f"Player alice achievements: {alice}")
    print(f"Player bob achievements: {bob}")
    print(f"Player charlie achievements: {charlie}")

    print("=== Achievement Analytics ===")

    all_achievements = alice | bob | charlie
    print(f"All unique achievements: {all_achievements}")
    print(f"Total unique achievements: {len(all_achievements)}")

    common = alice & bob & charlie
    print(f"Common to all players: {common}")

    # Rare = unique to one player
    rare = ((alice - bob - charlie) |
            (bob - alice - charlie) |
            (charlie - alice - bob))
    print(f"Rare achievements (1 player): {rare}")

    print(f"Alice vs Bob common: {alice & bob}")
    print(f"Alice unique: {alice - bob}")
    print(f"Bob unique: {bob - alice}")


if __name__ == "__main__":
    main()
