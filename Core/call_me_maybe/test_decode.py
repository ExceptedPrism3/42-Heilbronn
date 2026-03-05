from llm_sdk import Small_LLM_Model
import json

with open('vocab.json', 'r') as f:
    vocab = json.load(f)

model = Small_LLM_Model()

test_tokens = ["Ġthe", "ĉĊ", "an", "Ġ"]
for tok in test_tokens:
    idx = vocab.get(tok)
    if idx is not None:
        decoded = model.decode([idx])
        print(f"Token '{tok}' (ID: {idx}) decodes to: {repr(decoded)}")
