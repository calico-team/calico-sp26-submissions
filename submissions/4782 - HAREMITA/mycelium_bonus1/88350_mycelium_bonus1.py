import sys

def solve():
    # Read all input at once for speed
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    ptr = 1
    
    for _ in range(T):
        xg, yg, xm, ym = map(int, input_data[ptr:ptr+4])
        ptr += 4
        
        count = 0
        # A range of 400 is mathematically sufficient for Bonus 1 constraints
        # as it covers the area where 7*dm < 2*dg
        limit = 400 
        
        # Iterate through the potential territory
        for x in range(xm - limit, xm + limit + 1):
            for y in range(ym - limit, ym + limit + 1):
                # Manhattan distances
                dm_dist = abs(x - xm) + abs(y - ym)
                dg_dist = abs(x - xg) + abs(y - yg)
                
                # Ticks: Mycelium every 7, Grass every 2
                tm_tick = 7 * dm_dist
                tg_tick = 2 * dg_dist
                
                # Mycelium occupies if it is strictly faster than grass
                if tm_tick < tg_tick:
                    count += 1
        
        sys.stdout.write(str(count) + '\n')

if __name__ == "__main__":
    solve()