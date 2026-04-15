from collections import deque

def solve_one(XG, YG, XM, YM):
    # For large coordinates, use formula
    if abs(XG) > 2000 or abs(YG) > 2000 or abs(XM) > 2000 or abs(YM) > 2000:
        # Count tiles where 7*|x-XM|+7*|y-YM| < 2*|x-XG|+2*|y-YG|
        # This is a diamond-shaped region
        count = 1  # initial mycelium tile
        # Need to count all integer points satisfying inequality
        # This is complex, but for large coordinates we can bound
        # The region is finite because grass expands faster
        max_d = 1000000  # heuristic bound
        for dx in range(-max_d, max_d+1):
            for dy in range(-max_d, max_d+1):
                x, y = XM + dx, YM + dy
                dM = abs(dx) + abs(dy)
                dG = abs(x - XG) + abs(y - YG)
                if 7*dM < 2*dG:
                    count += 1
        return count
    
    # For smaller coordinates, BFS simulation
    # We simulate until no more changes
    grass = {(XG, YG)}
    mycelium = {(XM, YM)}
    occupied = grass | mycelium
    
    tick = 0
    changed = True
    
    while changed and tick < 10000:  # safety bound
        tick += 1
        changed = False
        new_grass = set()
        new_mycelium = set()
        
        if tick % 2 == 0:  # grass spreads
            for x, y in list(grass):
                for nx, ny in [(x+1,y), (x-1,y), (x,y+1), (x,y-1)]:
                    if (nx, ny) not in occupied:
                        new_grass.add((nx, ny))
        
        if tick % 7 == 0:  # mycelium spreads
            for x, y in list(mycelium):
                for nx, ny in [(x+1,y), (x-1,y), (x,y+1), (x,y-1)]:
                    if (nx, ny) not in occupied and (nx, ny) not in new_grass:
                        new_mycelium.add((nx, ny))
        
        if new_grass:
            grass.update(new_grass)
            occupied.update(new_grass)
            changed = True
        
        if new_mycelium:
            mycelium.update(new_mycelium)
            occupied.update(new_mycelium)
            changed = True
    
    return len(mycelium)

def read_your_input():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return []
    T = int(data[0])
    cases = []
    idx = 1
    for _ in range(T):
        XG = int(data[idx]); YG = int(data[idx+1])
        XM = int(data[idx+2]); YM = int(data[idx+3])
        idx += 4
        cases.append((XG, YG, XM, YM))
    return cases

if __name__ == "__main__":
    test_cases = read_your_input()
    for XG, YG, XM, YM in test_cases:
        print(solve_one(XG, YG, XM, YM))