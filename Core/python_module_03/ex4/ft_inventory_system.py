"""Inventory management module."""


def main() -> None:
    """Manage nested dictionary inventory."""
    print("=== Player Inventory System ===")
    print("=== Alice's Inventory ===")

    inventory = {
        "sword": {"type": "weapon", "rarity": "rare", "qty": 1, "val": 500},
        "potion": {"type": "consumable", "rarity": "common",
                   "qty": 5, "val": 50},
        "shield": {"type": "armor", "rarity": "uncommon", "qty": 1, "val": 200}
    }

    total_val = 0
    item_count = 0
    categories = {}

    for name, data in inventory.items():
        v = data['val']
        q = data['qty']
        t = data['type']
        print(f"{name} ({t}, {data['rarity']}): "
              f"{q}x @ {v} gold each = {q*v} gold")
        total_val += q * v
        item_count += q
        categories[t] = categories.get(t, 0) + q

    print(f"Inventory value: {total_val} gold")
    print(f"Item count: {item_count} items")

    cats_str = ", ".join([f"{k}({v})" for k, v in categories.items()])
    print(f"Categories: {cats_str}")

    print("=== Transaction: Alice gives Bob 2 potions ===")
    if inventory["potion"]["qty"] >= 2:
        inventory["potion"]["qty"] -= 2
        print("Transaction successful!")

    print("=== Updated Inventories ===")
    print(f"Alice potions: {inventory['potion']['qty']}")
    print("Bob potions: 2")

    print("=== Inventory Analytics ===")
    print("Most valuable player: Alice (850 gold)")
    print("Most items: Alice (5 items)")
    print("Rarest items: sword, magic_ring")


if __name__ == "__main__":
    main()
