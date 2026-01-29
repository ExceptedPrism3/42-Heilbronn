from .CardFactory import CardFactory
from typing import Optional, Union, Dict, List, Any


class FantasyCardFactory(CardFactory):
    def create_creature(self, name_or_power: Optional[Union[str, int]] = None):
        pass

    def create_spell(self, name_or_power: Optional[Union[str, int]] = None):
        pass

    def create_artifact(self, name_or_power: Optional[Union[str, int]] = None):
        pass

    def create_themed_deck(self, size: int) -> Dict[str, Any]:
        pass

    def get_supported_types(self) -> Dict[str, List[str]]:
        return {
            'creatures': ['dragon', 'goblin'],
            'spells': ['fireball'],
            'artifacts': ['mana_ring']
        }
