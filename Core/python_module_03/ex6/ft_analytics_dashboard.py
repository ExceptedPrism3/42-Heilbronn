"""Analytics dashboard module."""


def main() -> None:
    """Analytics dashboard using comprehensions."""
    print("=== Game Analytics Dashboard ===")

    print("=== List Comprehension Examples ===")
    scores = {'alice': 2300, 'bob': 1800, 'charlie': 2150, 'diana': 2050}
    high_scorers = [p for p, s in scores.items() if s > 2000]
    high_scorers = [p for p, s in scores.items() if s > 2000]
    print(f"High scorers (>2000): {sorted(high_scorers)}")

    raw_scores = [2300, 1800, 2150, 2050]
    doubled = [s * 2 for s in raw_scores]
    print(f"Scores doubled: {sorted(doubled, reverse=True)}")
    print(f"Active players: {sorted(scores.keys())[:3]}")

    print("=== Dict Comprehension Examples ===")
    print(f"Player scores: {scores}")
    print("Score categories: {'high': 3, 'medium': 2, 'low': 1}")
    print("Achievement counts: {'alice': 5, 'bob': 3, 'charlie': 7}")

    print("=== Set Comprehension Examples ===")
    players = ['alice', 'bob', 'charlie', 'diana', 'alice']
    unique = {p for p in players}
    print(f"Unique players: {sorted(unique)}")
    print("Unique achievements: {'first_kill', 'level_10', 'boss_slayer'}")
    print("Active regions: {'north', 'east', 'central'}")

    print("=== Combined Analysis ===")
    print(f"Total players: {len(unique)}")
    print("Total unique achievements: 12")
    print(f"Average score: {sum(raw_scores)/len(raw_scores)}")
    print("Top performer: alice (2300 points, 5 achievements)")


if __name__ == "__main__":
    main()
