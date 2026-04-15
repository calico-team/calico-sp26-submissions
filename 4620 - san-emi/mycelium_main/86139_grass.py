def solve(xg, yg, xm, ym):
    grid = {}
    grid[(xg, yg)] = 'G'
    grid[(xm, ym)] = 'M'   
    mcc = 1
    st = 0
    tick = 0  
    while True:
        tick += 1
        new_g = set()
        new_m = set()      
        if tick % 2 == 0:
            for (x, y), t in list(grid.items()):
                if t == 'G':
                    for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                        nb = (x+dx, y+dy)
                        if nb not in grid:
                            new_g.add(nb)       
        if tick % 7 == 0:
            for (x, y), t in list(grid.items()):
                if t == 'M':
                    for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                        nb = (x+dx, y+dy)
                        if nb not in grid and nb not in new_g:
                            new_m.add(nb)       
        for pos in new_g:
            grid[pos] = 'G'
        for pos in new_m:
            grid[pos] = 'M'      
        if new_m:
            mcc += len(new_m)
            st = 0
        else:
            st += 1
            if st >= 14:
                break
    
    return mcc

T = int(input())
for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    print(solve(xg, yg, xm, ym))