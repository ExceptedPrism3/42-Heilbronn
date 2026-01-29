from .Card import Card
from typing import Dict, Any


class CreatureCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, attack: int,
                 health: int):
        try:
            super().__init__(name, cost, rarity)
            self.attack_stats = attack
            self.health = health
        except Exception:
            pass

    def play(self, game_state: Dict[str, Any]) -> Dict[str, Any]:
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Creature summoned to battlefield"
        }

    def attack_target(self, target: str) -> Dict[str, Any]:
        return {
            "attacker": self.name,
            "target": target,
            "damage_dealt": self.attack_stats,
            "combat_resolved": True
        }

    def get_card_info(self) -> Dict[str, Any]:
        info = super().get_card_info()
        info.update({
            "type": "Creature",
            "attack": self.attack_stats,
            "health": self.health
        })
        return info
