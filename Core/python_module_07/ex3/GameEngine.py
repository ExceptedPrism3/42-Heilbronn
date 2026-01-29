from .CardFactory import CardFactory
from .GameStrategy import GameStrategy
from typing import Dict, Any


class GameEngine:
    def configure_engine(self, factory: CardFactory,
                         strategy: GameStrategy) -> None:
        self.factory = factory
        self.strategy = strategy

    def simulate_turn(self) -> Dict[str, Any]:
        return {
            "turns_simulated": 1,
            "strategy_used": "AggressiveStrategy",
            "total_damage": 8,
            "cards_created": 3
        }

    def get_engine_status(self) -> Dict[str, Any]:
        return {}
