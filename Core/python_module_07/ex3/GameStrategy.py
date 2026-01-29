from abc import ABC, abstractmethod
from typing import List, Dict, Any


class GameStrategy(ABC):
    @abstractmethod
    def execute_turn(self, hand: List[Any],
                     battlefield: List[Any]) -> Dict[str, Any]:
        pass

    @abstractmethod
    def get_strategy_name(self) -> str:
        pass

    @abstractmethod
    def prioritize_targets(self, available_targets: List[Any]) -> List[Any]:
        pass
