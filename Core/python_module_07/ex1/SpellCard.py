from ex0.Card import Card
from typing import Dict, Any, List


class SpellCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, effect_type: str):
        super().__init__(name, cost, rarity)
        self.effect_type = effect_type

    def play(self, game_state: Dict[str, Any]) -> Dict[str, Any]:
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Deal 3 damage to target"
        }

    def resolve_effect(self, targets: List[str]) -> Dict[str, Any]:
        return {"resolved": True}
