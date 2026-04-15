def solve(xg, yg, xm, ym):
    grid = {}
    grid[(xg, yg)] = 'G'
    grid[(xm, ym)] = 'M'
    g_front = {(xg, yg)}
    m_front = {(xm, ym)}
    mcc = 1
    direc = [(1,0),(-1,0),(0,1),(0,-1)]
    tick = 0
    while True:
        tick += 1
        new_g = set()
        new_m = set()
        if tick % 2 == 0:
            for x, y in g_front:
                for dx, dy in direc:
                    nb = (x+dx, y+dy)
                    if nb not in grid:
                        new_g.add(nb)
        if tick % 7 == 0:
            for x, y in m_front:
                for dx, dy in direc:
                    nb = (x+dx, y+dy)
                    if nb not in grid and nb not in new_g:
                        new_m.add(nb)
        for pos in new_g:
            grid[pos] = 'G'
        for pos in new_m:
            grid[pos] = 'M'
        if tick % 2 == 0 and new_g:
            g_front = new_g
        if tick % 7 == 0:
            if new_m:
                m_front = new_m
                mcc += len(new_m)
            else:
                break
    return mcc

T = int(input())
for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    print(solve(xg, yg, xm, ym))