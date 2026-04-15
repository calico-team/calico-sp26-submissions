import sys
input = sys.stdin.readline

def solve(xg, yg, xm, ym):
    # Simulate: tile is grass if reachable by grass before mycelium claims it
    # grass radius at tick t = t // 2, mycelium radius = t // 7
    # A point (x,y) is claimed by mycelium at the earliest tick t where:
    #   t % 7 == 0 and manhattan(xm,ym,x,y) <= t//7
    #   AND at that tick, grass hasn't claimed it yet (manhattan(xg,yg,x,y) > t//2)
    # 
    # Mycelium reaches (x,y) at tick = 7 * dm where dm = manhattan dist to mycelium
    # Grass reaches (x,y) at tick = 2 * dg where dg = manhattan dist to grass
    # (x,y) is mycelium if 7*dm <= 2*dg (mycelium gets there first or same tick -> grass wins)
    # Wait: if same tick grass wins, so mycelium wins only if 7*dm < 2*dg
    # But also need to check: at tick 7*dm, has grass already claimed it?
    # grass claims at tick 2*dg, so mycelium wins if 7*dm < 2*dg
    
    # The mycelium region is finite because grass is faster (ratio 2 vs 7)
    # We simulate over a bounding box
    
    # Max possible mycelium radius: mycelium can only reach tiles where 7*dm < 2*dg
    # As dm grows, 7*dm grows faster than 2*dm, so eventually grass wins everywhere far
    # The boundary is roughly where the two fronts meet
    
    # For main test set, just simulate with BFS up to large enough ticks
    
    EMPTY, GRASS, MYCELIUM = 0, 1, 2
    
    # Use dict for infinite grid
    grid = {}
    grid[(xg, yg)] = GRASS
    grid[(xm, ym)] = MYCELIUM
    
    mycelium_count = 1
    
    # Simulate enough ticks - grass spreads fast so mycelium stops eventually
    # Max ticks needed: when mycelium is fully surrounded
    # For coords up to 10, simulate 200 ticks to be safe
    
    MAX_TICKS = 500
    
    grass_tiles = {(xg, yg)}
    myc_tiles = {(xm, ym)}
    
    prev_myc_count = -1
    stable = 0
    
    for tick in range(1, MAX_TICKS + 1):
        new_grass = set()
        new_myc = set()
        
        if tick % 2 == 0:
            for (x, y) in grass_tiles:
                for dx, dy in [(0,1),(0,-1),(1,0),(-1,0)]:
                    nx, ny = x+dx, y+dy
                    if (nx, ny) not in grid:
                        new_grass.add((nx, ny))
        
        if tick % 7 == 0:
            for (x, y) in myc_tiles:
                for dx, dy in [(0,1),(0,-1),(1,0),(-1,0)]:
                    nx, ny = x+dx, y+dy
                    if (nx, ny) not in grid:
                        new_myc.add((nx, ny))
        
        # grass wins conflicts
        contested = new_grass & new_myc
        new_myc -= contested
        
        for pos in new_grass | contested:
            grid[pos] = GRASS
            grass_tiles.add(pos)
        
        for pos in new_myc:
            grid[pos] = MYCELIUM
            myc_tiles.add(pos)
        
        if len(myc_tiles) == prev_myc_count:
            stable += 1
            if stable >= 14:  # stable for 14 ticks (2 full mycelium cycles)
                break
        else:
            stable = 0
        prev_myc_count = len(myc_tiles)
    
    return len(myc_tiles)

T = int(input())
for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    print(solve(xg, yg, xm, ym))