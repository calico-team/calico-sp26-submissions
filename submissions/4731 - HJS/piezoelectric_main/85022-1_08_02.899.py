def solve(L, W, E, R):
    triangle_area = 2 * (L + W)
    power_per_lap = triangle_area * R
    lapsNeed = E // power_per_lap
    return lapsNeed

def read_your_input():
    import sys
    data = sys.stdin.read().split()
    if not data:
        return
        
    t_cases = int(data[0])
    curr = 1
    
    for _ in range(t_cases):
        l = int(data[curr])
        wid = int(data[curr + 1])
        energy = int(data[curr + 2])
        regen = int(data[curr + 3])
        
        result = solve(l, wid, energy, regen)
        print(result)
        
        curr += 4

if __name__ == "__main__":
    read_your_input()