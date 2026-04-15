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
        
        # The inequality: 7*d_m < 2*d_g
        # d_m = |x - XM| + |y - YM|
        # d_g = |x - XG| + |y - YG|
        
        # Bound: mycelium distance must be small enough
        # Max d_m occurs when 7*d_m < 2*d_g, so d_m <= (2/7)*d_g
        # We can safely restrict search to a diamond around XM
        
        # Compute maximum radius to check
        max_dist = abs(XG - XM) + abs(YG - YM)
        # Grass reaches XM at time 2*max_dist
        # Mycelium spreads outward, so only tiles within radius (2/7)*max_dist matter
        limit = (2 * max_dist) // 7 + 2  # small buffer
        
        count = 0
        for dx in range(-limit, limit+1):
            for dy in range(-limit, limit+1):
                x, y = XM + dx, YM + dy
                d_m = abs(dx) + abs(dy)
                d_g = abs(x - XG) + abs(y - YG)
                if 7*d_m < 2*d_g:
                    count += 1
        
        results.append(count)
    
    print("\n".join(map(str, results)))


if __name__ == "__main__":
    solve()
