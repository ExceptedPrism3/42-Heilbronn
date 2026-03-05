import json
from typing import Dict


def get_vocab_strings(vocab_path: str) -> Dict[int, bytes]:
    """
    Parses the BPE vocab.json file into a mapping from token_id to bytes.
    Avoids using the transformers library by re-implementing
    the standard GPT-2 bytes_to_unicode mapping.
    """
    with open(vocab_path, "r", encoding="utf-8") as f:
        vocab = json.load(f)

    bs = (
        list(range(ord("!"), ord("~") + 1))
        + list(range(ord("¡"), ord("¬") + 1))
        + list(range(ord("®"), ord("ÿ") + 1))
    )
    cs = bs[:]
    n = 0
    for b in range(2**8):
        if b not in bs:
            bs.append(b)
            cs.append(256 + n)
            n += 1

    # cs corresponds to the unicode characters in vocab.json
    # bs corresponds to the raw bytes they represent
    unicode_to_bytes = {chr(c): b for c, b in zip(cs, bs)}

    token_to_bytes = {}
    for token_str, token_id in vocab.items():
        # Reconstruct the raw bytes for this token
        token_bytes = bytes([unicode_to_bytes.get(c, 0) for c in token_str])
        token_to_bytes[token_id] = token_bytes

    return token_to_bytes
