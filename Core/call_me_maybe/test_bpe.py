def bytes_to_unicode():
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
    cs = [chr(n) for n in cs]
    return dict(zip(bs, cs))


mapping = bytes_to_unicode()
reverse_mapping = {v: k for k, v in mapping.items()}

print("Space ' ' mapped to:", chr(reverse_mapping.get(' ', 32)))


print("ord(' ') is mapped to:", mapping[ord(' ')])
print("ord('\\n') is mapped to:", mapping[ord('\\n')])
print("ord('\\t') is mapped to:", mapping[ord('\\t')])
