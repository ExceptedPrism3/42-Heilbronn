from pydantic import BaseModel
from typing import Dict, List, Literal


class FunctionDefinition(BaseModel):
    fn_name: str
    args_names: List[str]
    args_types: Dict[str, Literal["float", "int", "str", "bool"]]
    return_type: str


class FunctionDefinitionList(BaseModel):
    functions: List[FunctionDefinition]
