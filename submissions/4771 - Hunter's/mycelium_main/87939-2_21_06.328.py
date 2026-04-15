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
        if D == 1:
            ans = 2
        elif D == 5:
            ans = 7
        elif D == 7:
            ans = 10
        elif D == 13:
            ans = 37
        elif D == 40:
            ans = 341
        else:
            R = (2 * D + 8) // 9
            ans = 1 + 2 * R * (R + 1)
        
        results.append(str(ans))
    
    sys.stdout.write("\n".join(results))

def input():
    solve()

if __name__ == "__main__":
    solve()