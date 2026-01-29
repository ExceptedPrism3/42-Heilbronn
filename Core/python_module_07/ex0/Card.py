from abc import ABC, abstractmethod
from typing import Dict, Any


class Card(ABC):
    def __init__(self, name: str, cost: int, rarity: str):
        try:
            self.name = name
            self.cost = cost
            self.rarity = rarity
        except Exception:
            pass

    @abstractmethod
    def play(self, game_state: Dict[str, Any]) -> Dict[str, Any]:
        pass

    def get_card_info(self) -> Dict[str, Any]:
        return {
            "name": self.name,
            "cost": self.cost,
            "rarity": self.rarity
        }

    def is_playable(self, available_mana: int) -> bool:
        return self.cost <= available_mana
