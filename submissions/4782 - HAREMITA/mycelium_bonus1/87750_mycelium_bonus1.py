import sys
input = sys.stdin.readline

def solve():
    line = input().split()
    if not line: return
    xg, yg, xm, ym = map(int, line)
    
    # Manhattan distance between G and M
    dist_gm = abs(xg - xm) + abs(yg - ym)
    
    # The mycelium region is relatively small because it spreads 3.5x slower.
    # We search a generous area around the mycelium starting point.
    search_range = dist_gm + 5 
    
    count = 0
    for x in range(xm - search_range, xm + search_range + 1):
        for y in range(ym - search_range, ym + search_range + 1):
            # dm = ticks for mycelium to reach (x,y)
            # dg = ticks for grass to reach (x,y)
            dm = 7 * (abs(x - xm) + abs(y - ym))
            dg = 2 * (abs(x - xg) + abs(y - yg))
            
            # Mycelium occupies the tile if it arrives strictly first
            if dm < dg:
                count += 1
    print(count)

line = input().split()
if line:
    T = int(line[0])
    for _ in range(T):
        solve()