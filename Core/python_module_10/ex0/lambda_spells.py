from typing import List, Dict

# Exercise 0: Lambda Sanctum

def artifact_sorter(artifacts: List[Dict]) -> List[Dict]:
    """Sorts artifacts by power (descending)."""
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)

def power_filter(mages: List[Dict], min_power: int) -> List[Dict]:
    """Filters mages by minimum power."""
    return list(filter(lambda x: x['power'] >= min_power, mages))

def spell_transformer(spells: List[str]) -> List[str]:
    """Transforms spells with prefix/suffix."""
    return list(map(lambda x: f"* {x} *", spells))

def mage_stats(mages: List[Dict]) -> Dict:
    """Calculates mage statistics using functional reductions."""
    if not mages:
        return {'max_power': 0, 'min_power': 0, 'avg_power': 0.0}
    
    powers = list(map(lambda x: x['power'], mages))
    return {
        'max_power': max(powers),
        'min_power': min(powers),
        'avg_power': round(sum(powers) / len(powers), 2)
    }

if __name__ == "__main__":
    # Test cases
    print("Testing artifact sorter...")
    arts = [
        {'name': 'Crystal Orb', 'power': 85, 'type': 'Orb'},
        {'name': 'Fire Staff', 'power': 92, 'type': 'Staff'}
    ]
    sorted_arts = artifact_sorter(arts)
    for a in sorted_arts:
        print(f"{a['name']} ({a['power']} power)")
        
    print("\nTesting spell transformer...")
    sp = spell_transformer(["fireball", "heal", "shield"])
    print(" ".join(sp))
