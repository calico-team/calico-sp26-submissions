def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    T = int(data[0])
    idx = 1
    results = []
    
    for _ in range(T):
        XG, YG, XM, YM = map(int, data[idx:idx+4])
        idx += 4
        
        # Maximum distance grass can reach before mycelium catches up
        max_dist = abs(XG - XM) + abs(YG - YM)
        # Mycelium only matters within radius proportional to grass distance
        limit = (2 * max_dist) // 7 + 2
        
        count = 0
        for dx in range(-limit, limit+1):
            for dy in range(-limit, limit+1):
                d_m = abs(dx) + abs(dy)
                if d_m > limit:
                    continue
                x, y = XM + dx, YM + dy
                d_g = abs(x - XG) + abs(y - YG)
                if 7*d_m < 2*d_g:
                    count += 1
        
        results.append(count)
    
    print("\n".join(map(str, results)))


if __name__ == "__main__":
    solve()
