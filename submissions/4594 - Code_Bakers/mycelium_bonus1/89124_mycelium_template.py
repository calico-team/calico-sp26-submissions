import sys
input = sys.stdin.readline

def solve(X_G, Y_G, X_M, Y_M):
    DIRS = [(0,1),(0,-1),(1,0),(-1,0)]
    GRASS, MYC = 1, 2
    grid = {(X_G,Y_G): GRASS, (X_M,Y_M): MYC}
    myc_count = 1
    g_cands = set()
    m_cands = set()
    for dx,dy in DIRS:
        n=(X_G+dx,Y_G+dy)
        if n not in grid: g_cands.add(n)
    for dx,dy in DIRS:
        n=(X_M+dx,Y_M+dy)
        if n not in grid: m_cands.add(n)

    def expand_grass(g_cands, m_cands):
        if not g_cands: return g_cands
        new_cands = set()
        for tile in g_cands:
            if tile in grid: continue
            grid[tile] = GRASS
            m_cands.discard(tile)
            x,y = tile
            for dx,dy in DIRS:
                n=(x+dx,y+dy)
                if n not in grid: new_cands.add(n)
        return new_cands

    def expand_myc(m_cands, g_cands, myc_count):
        if not m_cands: return m_cands, myc_count
        new_cands = set()
        for tile in m_cands:
            if tile in grid: continue
            grid[tile] = MYC
            g_cands.discard(tile)
            myc_count += 1
            x,y = tile
            for dx,dy in DIRS:
                n=(x+dx,y+dy)
                if n not in grid: new_cands.add(n)
        return new_cands, myc_count

    prev_myc_count = 0
    no_change_streak = 0

    while True:
        if not m_cands: break

        g_cands = expand_grass(g_cands, m_cands)
        g_cands = expand_grass(g_cands, m_cands)
        g_cands = expand_grass(g_cands, m_cands)
        m_cands, myc_count = expand_myc(m_cands, g_cands, myc_count)
        g_cands = expand_grass(g_cands, m_cands)
        g_cands = expand_grass(g_cands, m_cands)
        g_cands = expand_grass(g_cands, m_cands)

        new_g = {t for t in g_cands if t not in grid}
        new_m = {t for t in m_cands if t not in grid and t not in new_g}

        next_g = set()
        for tile in new_g:
            grid[tile] = GRASS
            m_cands.discard(tile)
            x,y = tile
            for dx,dy in DIRS:
                n=(x+dx,y+dy)
                if n not in grid: next_g.add(n)

        next_m = set()
        for tile in new_m:
            grid[tile] = MYC
            g_cands.discard(tile)
            myc_count += 1
            x,y = tile
            for dx,dy in DIRS:
                n=(x+dx,y+dy)
                if n not in grid: next_m.add(n)

        g_cands = next_g
        m_cands = next_m - next_g

        # Early termination: if mycelium stopped growing, we're done
        if myc_count == prev_myc_count:
            no_change_streak += 1
            if no_change_streak >= 3:
                break
        else:
            no_change_streak = 0
        prev_myc_count = myc_count

    return myc_count

def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))

if __name__ == '__main__':
    main()