from .FantasyCardFactory import FantasyCardFactory
from .AggressiveStrategy import AggressiveStrategy
from .GameEngine import GameEngine


def main():
    print("=== DataDeck Game Engine ===")
    print("Configuring Fantasy Card Game...")

    factory = FantasyCardFactory()
    strategy = AggressiveStrategy()
    engine = GameEngine()
    engine.configure_engine(factory, strategy)

    print("Factory: FantasyCardFactory")
    print("Strategy: AggressiveStrategy")
    print(f"Available types: {factory.get_supported_types()}")

    print("Simulating aggressive turn...")
    print("Hand: [Fire Dragon (5), Goblin Warrior (2), Lightning Bolt (3)]")

    turn_result = strategy.execute_turn([], [])
    print("Turn execution:")
    print(f"Strategy: {strategy.get_strategy_name()}")
    print(f"Actions: {turn_result}")

    print("Game Report:")
    print(engine.simulate_turn())

    print("Abstract Factory + Strategy Pattern: Maximum flexibility achieved!")


if __name__ == "__main__":
    main()
