import shutil
from huggingface_hub import hf_hub_download

vocab_path = hf_hub_download(repo_id="Qwen/Qwen3-0.6B", filename="vocab.json")
print("Vocab Path:", vocab_path)
shutil.copy(vocab_path, "vocab.json")

print("Saved local copy of vocab.json")
