class State:
    def __init__(self) -> None:
        self.transitions: dict[int, list["State"]] = {}
        self.default_transitions: list[tuple["State", set[int]]] = []
        self.is_accept: bool = False

    def add_transition(self, byte_val: int, next_state: "State") -> None:
        if byte_val not in self.transitions:
            self.transitions[byte_val] = []
        self.transitions[byte_val].append(next_state)

    def add_default_transition(
        self, next_state: "State", exclude_bytes: set[int] | None = None
    ) -> None:
        exclude_set = set(exclude_bytes) if exclude_bytes else set()
        self.default_transitions.append((next_state, exclude_set))


_CONSUME_CACHE: dict[tuple[frozenset["State"], int], frozenset["State"]] = {}


def consume_byte(
    states: frozenset["State"], b: int
) -> frozenset["State"]:
    key = (states, b)
    if key in _CONSUME_CACHE:
        return _CONSUME_CACHE[key]

    next_states = set()
    for state in states:
        if b in state.transitions:
            for nxt in state.transitions[b]:
                next_states.add(nxt)
        for nxt, excluded_bytes in state.default_transitions:
            if b not in excluded_bytes:
                next_states.add(nxt)

    result = frozenset(next_states)
    _CONSUME_CACHE[key] = result
    return result


def consume_bytes(
    states: frozenset["State"], byte_seq: bytes
) -> frozenset["State"]:
    current_states = states
    for b in byte_seq:
        current_states = consume_byte(current_states, b)
        if not current_states:
            break
    return current_states


def build_literal(state: "State", literal_bytes: bytes) -> "State":
    current = state
    for b in literal_bytes:
        nxt = State()
        current.add_transition(b, nxt)
        current = nxt
    return current


def build_number(state: "State", is_float: bool = False) -> "State":
    # Optional minus sign
    first_digit = State()
    state.add_transition(ord("-"), first_digit)

    digit_loop = State()
    for i in range(10):
        b = ord("0") + i
        state.add_transition(b, digit_loop)
        first_digit.add_transition(b, digit_loop)
        digit_loop.add_transition(b, digit_loop)

    if not is_float:
        return digit_loop

    dot_state = State()
    digit_loop.add_transition(ord("."), dot_state)

    float_loop = State()
    for i in range(10):
        b = ord("0") + i
        dot_state.add_transition(b, float_loop)
        float_loop.add_transition(b, float_loop)

    return float_loop


def build_string(state: "State") -> "State":
    in_str = State()
    state.add_transition(ord('"'), in_str)

    # From within the string, a quote ends it
    end_state = State()
    in_str.add_transition(ord('"'), end_state)

    # We can stay in the string for any byte except a quote OR a backslash
    in_str.add_default_transition(in_str, {ord('"'), ord("\\")})

    # If we hit a backslash, we MUST enter an escape state
    escape_state = State()
    in_str.add_transition(ord("\\"), escape_state)

    # From the escape state, only valid JSON escapes are allowed:
    # ", \, /, b, f, n, r, t, and u (simplified)
    # For robust string capturing, after a backslash we'll allow almost
    # anything because the LLM might try to escape \d as \\d.
    # Wait, if we allow ANYTHING after \, then \d becomes valid!
    # If the LLM generates \d, we are at in_str.
    # Then we see \ -> transition to escape_state.
    # Then we see d -> transition back to in_str.
    # So `\d` would be valid JSON! Wait, standard json.loads allows
    # \", \\, \/, \b, \f, \n, \r, \t. It does NOT allow \d.
    # So we MUST strictly enforce standard JSON escapes.
    valid_escapes = {
        ord('"'),
        ord("\\"),
        ord("/"),
        ord("b"),
        ord("f"),
        ord("n"),
        ord("r"),
        ord("t"),
        ord("u"),
    }
    for esc in valid_escapes:
        escape_state.add_transition(esc, in_str)

    # For \u, we need 4 hex digits, but to keep the NFA simple, we'll
    # just loop back to in_str. This isn't perfect for \u but prevents
    # the invalid \escape crash.

    return end_state
