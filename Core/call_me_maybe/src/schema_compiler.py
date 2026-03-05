from src.dfa import State, build_literal, build_number, build_string
from src.models import FunctionDefinitionList


class SchemaCompiler:
    def __init__(self, function_definitions: FunctionDefinitionList):
        self.functions = function_definitions.functions

    def compile(self) -> State:
        start_state = State()
        # The JSON must always contain the fn_name and args fields.
        prefix = build_literal(start_state, b'{"fn_name":"')

        final_accept_states = []

        for fn in self.functions:
            fn_name = fn.fn_name
            fn_state = build_literal(prefix, fn_name.encode("utf-8"))

            args_prefix = build_literal(fn_state, b'","args":{')
            current_states = [args_prefix]

            args_names = fn.args_names
            args_types = fn.args_types

            for i, arg_name in enumerate(args_names):
                if i > 0:
                    current_states = self._chain_literal(current_states, b",")

                arg_key = f'"{arg_name}":'.encode("utf-8")
                current_states = self._chain_literal(current_states, arg_key)

                arg_type = args_types.get(arg_name)
                current_states = self._chain_type(current_states, arg_type)

            # Close the args object and the main object
            end_states = self._chain_literal(current_states, b"}}")
            final_accept_states.extend(end_states)

        for s in final_accept_states:
            s.is_accept = True

        return start_state

    def _chain_literal(
        self, states: list[State], literal_bytes: bytes
    ) -> list[State]:
        new_states = []
        for s in states:
            new_states.append(build_literal(s, literal_bytes))
        return new_states

    def _chain_type(
        self, states: list[State], arg_type: str | None
    ) -> list[State]:
        new_states = []
        for s in states:
            if arg_type == "float":
                new_states.append(build_number(s, is_float=True))
            elif arg_type == "int":
                new_states.append(build_number(s, is_float=False))
            elif arg_type == "str":
                new_states.append(build_string(s))
            elif arg_type == "bool":
                t_end = build_literal(s, b"true")
                f_end = build_literal(s, b"false")
                new_states.extend([t_end, f_end])
            else:
                raise ValueError(f"Unknown type {arg_type}")
        return new_states
