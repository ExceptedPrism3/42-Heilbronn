from .GameStrategy import GameStrategy
from typing import List, Dict, Any


class AggressiveStrategy(GameStrategy):
    def execute_turn(self, hand: List[Any],
                     battlefield: List[Any]) -> Dict[str, Any]:
        return {
            "cards_played": ["Goblin Warrior", "Lightning Bolt"],
            "mana_used": 5,
            "targets_attacked": ["Enemy Player"],
            "damage_dealt": 8
        }

    def get_strategy_name(self) -> str:
        return "AggressiveStrategy"

    def prioritize_targets(self, available_targets: List[Any]) -> List[Any]:
        return available_targets
