from transformers import AutoTokenizer
import json

tokenizer = AutoTokenizer.from_pretrained('Qwen/Qwen3-0.6B')

with open('vocab.json', 'r') as f:
    vocab = json.load(f)

test_tokens = ["Ġthe", "ĉĊ", "an", "Ġ", "}", "{"]
for tok in test_tokens:
    idx = vocab.get(tok)
    if idx is not None:
        decoded = tokenizer.decode([idx])
        print(f"Token '{tok}' (ID: {idx}) decodes to: {repr(decoded)}")
