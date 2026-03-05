import torch

from typing import Any
from src.dfa import State, consume_bytes


class ConstraintMasker:
    def __init__(
        self, start_state: State, vocab_bytes: dict[int, bytes]
    ) -> None:
        self.current_states: frozenset[State] = frozenset({start_state})
        self.vocab_bytes = vocab_bytes
        self.vocab_size = len(vocab_bytes)
        # Precompute token byte lists for faster evaluation
        self.tokens_bytes: list[bytes] = [
            vocab_bytes.get(i, b"") for i in range(self.vocab_size)
        ]
        self._valid_tokens_cache: dict[frozenset[State], list[int]] = {}

    def get_valid_tokens(self) -> list[int]:
        if self.current_states in self._valid_tokens_cache:
            return self._valid_tokens_cache[self.current_states]

        valid_ids = []
        for token_id, token_bytes in enumerate(self.tokens_bytes):
            if not token_bytes:
                continue

            # Can we consume this token's bytes from our current states?
            next_states = consume_bytes(self.current_states, token_bytes)
            if next_states:
                # Yes, this token is a valid continuation
                valid_ids.append(token_id)

        self._valid_tokens_cache[self.current_states] = valid_ids
        return valid_ids

    def advance(self, token_id: int) -> None:
        token_bytes = self.vocab_bytes.get(token_id, b"")
        if token_bytes:
            self.current_states = consume_bytes(
                self.current_states, token_bytes
            )

    def is_finished(self) -> bool:
        return any(state.is_accept for state in self.current_states)


def generate_constrained(
    model: Any,
    prompt_text: str,
    schema_start_state: State,
    vocab_bytes: dict[int, bytes],
    max_tokens: int = 100,
) -> str:
    input_ids = model.encode(prompt_text)

    # We want the LLM to start outputting the JSON object immediately,
    # but the prompt might need formatting.
    # We just pass the prompt as is, or wrap it if necessary.
    # The constraints will force the output to be JSON.

    masker = ConstraintMasker(schema_start_state, vocab_bytes)

    generated_ids: list[int] = []

    for _ in range(max_tokens):
        if masker.is_finished():
            break

        # Get logits
        current_input = input_ids + generated_ids
        logits = model.get_logits_from_input_ids(current_input)

        # The SDK returns a 1D list of logits for the next token
        next_token_logits = torch.tensor(logits)

        # Mask invalid tokens
        valid_tokens = masker.get_valid_tokens()

        if not valid_tokens:
            err_bytes = bytes(
                [b for idx in generated_ids for b in vocab_bytes.get(idx, b"")]
            )
            raise RuntimeError(
                f"Dead end reached! Generated so far: {err_bytes!r}"
            )

        # Set all logits to -inf
        mask = torch.full_like(next_token_logits, float("-inf"))
        mask[valid_tokens] = next_token_logits[valid_tokens]

        # Greedy decoding (argmax)
        next_token_id = int(torch.argmax(mask).item())

        # Advance the state machine with the chosen token
        masker.advance(next_token_id)
        generated_ids.append(next_token_id)

        # Print debug text (optional)
        token_repr = vocab_bytes.get(next_token_id, b"").decode(
            "utf-8", errors="replace"
        )
        print(token_repr, end="", flush=True)

    res = str(model.decode(generated_ids))
    return res
