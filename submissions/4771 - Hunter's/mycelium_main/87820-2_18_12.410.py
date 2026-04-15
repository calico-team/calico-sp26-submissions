def solve():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    results = []
    
    for _ in range(t):
        XG = int(data[idx]); idx += 1
        YG = int(data[idx]); idx += 1
        XM = int(data[idx]); idx += 1
        YM = int(data[idx]); idx += 1
        
        D = abs(XG - XM) + abs(YG - YM)
        
        R = (2 * D + 7) // 9
        ans = 2 * R * (R + 1) + 1 - (1 if R == 0 else 0)
        
        results.append(str(ans))
    
    sys.stdout.write("\n".join(results))

def input():
    solve()

if __name__ == "__main__":
    solve()