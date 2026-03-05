import torch


def test():
    valid_tokens = [1, 5, 10]
    next_token_logits = torch.randn(100)

    mask = torch.full_like(next_token_logits, float("-inf"))
    mask[valid_tokens] = next_token_logits[valid_tokens]

    idx = int(torch.argmax(mask).item())
    print("Argmax passed:", idx)


test()
