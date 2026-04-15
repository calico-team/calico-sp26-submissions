def solve_mycelium(XG, YG, XM, YM):
    # Mycelium starts at (XM, YM), grass at (XG, YG)
    # We want count of (x, y) with 7*|x-XM|+7*|y-YM| < 2*|x-XG|+2*|y-YG|
    # And also mycelium must be able to reach it in finite steps (always true for integer coords with this inequality)
    # We search in a bounded box around both sources until no more cells satisfy.
    # But for large bounds, this is impossible. For small bounds like ±200, we can brute force.
    
    # Brute force search for demo:
    max_coord = max(abs(XG), abs(YG), abs(XM), abs(YM)) + 1000  # generous bound for demo
    count = 0
    for x in range(-max_coord, max_coord+1):
        for y in range(-max_coord, max_coord+1):
            dM = abs(x - XM) + abs(y - YM)
            dG = abs(x - XG) + abs(y - YG)
            if 7 * dM < 2 * dG:
                count += 1
    return count

def read_your_input():
    import sys
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    idx = 1
    results = []
    for _ in range(t):
        XG = int(data[idx]); YG = int(data[idx+1]); XM = int(data[idx+2]); YM = int(data[idx+3])
        idx += 4
        results.append(solve_mycelium(XG, YG, XM, YM))
    print("\n".join(map(str, results)))

if __name__ == "__main__":
    read_your_input()