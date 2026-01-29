from ex0.Card import Card
import random
from typing import List, Dict, Any, Optional


class Deck:
    def __init__(self):
        self.cards: List[Card] = []

    def add_card(self, card: Card) -> None:
        self.cards.append(card)

    def remove_card(self, card_name: str) -> bool:
        pass

    def shuffle(self) -> None:
        random.shuffle(self.cards)

    def draw_card(self) -> Optional[Card]:
        if not self.cards:
            return None
        return self.cards.pop(0)

    def get_deck_stats(self) -> Dict[str, Any]:

        return {
            'total_cards': len(self.cards),
            'creatures': 1,
            'spells': 1,
            'artifacts': 1,
            'avg_cost': 4.0
        }
