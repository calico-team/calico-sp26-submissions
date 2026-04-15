import sys
input = sys.stdin.readline

def solve():
    line = input().split()
    if not line: return
    xg, yg, xm, ym = map(int, line)
    
    # For Bonus 1 (coords up to 200), a search range of 500 is 
    # mathematically sufficient to cover the entire mycelium territory.
    limit = 500 
    count = 0
    
    # Iterate through a safe bounding box around the mycelium start
    for x in range(xm - limit, xm + limit + 1):
        for y in range(ym - limit, ym + limit + 1):
            # Arrival ticks: Mycelium every 7, Grass every 2
            dm = 7 * (abs(x - xm) + abs(y - ym))
            dg = 2 * (abs(x - xg) + abs(y - yg))
            
            # Tile belongs to mycelium ONLY if it arrives strictly first
            # If dm == dg, it converts to grass (as per rules).
            if dm < dg:
                count += 1
    print(count)

line_input = input().strip()
if line_input:
    T = int(line_input)
    for _ in range(T):
        solve()