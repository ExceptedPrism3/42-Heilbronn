from src.vocab import get_vocab_strings

vocab_bytes = get_vocab_strings("vocab.json")

print("Vocab size:", len(vocab_bytes))

test_ids = [279, 1572, 276, 220, 92, 90]
for idx in test_ids:
    print(f"Token {idx}: {vocab_bytes[idx]}")
