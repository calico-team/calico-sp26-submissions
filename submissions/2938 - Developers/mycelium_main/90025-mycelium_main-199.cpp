import sys
input = sys.stdin.readline

def solve():
    XG, YG, XM, YM = map(int, input().split())
    
    dirs = [(0,1),(0,-1),(1,0),(-1,0)]
    grid = {}
    grid[(XG,YG)] = 'G'
    grid[(XM,YM)] = 'M'
    
    g_front = {(XG,YG)}
    m_front = {(XM,YM)}
    
    tick = 0
    while m_front:
        tick += 1
        do_g = (tick % 2 == 0)
        do_m = (tick % 7 == 0)
        if not do_g and not do_m:
            continue
        
        g_new = set()
        m_new = set()
        
        if do_g:
            for (x,y) in g_front:
                for dx,dy in dirs:
                    p = (x+dx, y+dy)
                    if p not in grid:
                        g_new.add(p)
        
        if do_m:
            for (x,y) in m_front:
                for dx,dy in dirs:
                    p = (x+dx, y+dy)
                    if p not in grid:
                        m_new.add(p)
        
        m_new -= g_new  # ties go to grass
        
        for p in g_new:  grid[p] = 'G'
        for p in m_new:  grid[p] = 'M'
        
        def has_empty_neighbor(p):
            x,y = p
            return any((x+dx,y+dy) not in grid for dx,dy in dirs)
        
        g_front = {p for p in (g_front | g_new) if has_empty_neighbor(p)}
        m_front = {p for p in (m_front | m_new) if has_empty_neighbor(p)}
    
    print(sum(1 for v in grid.values() if v == 'M'))

T = int(input())
for _ in range(T):
    solve()