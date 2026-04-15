import sys
input = sys.stdin.readline

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    DIRS = [(0,1),(0,-1),(1,0),(-1,0)]
    GRASS, MYC = 1, 2

    grid = {(X_G,Y_G): GRASS, (X_M,Y_M): MYC}
    myc_count = 1

    # candidate sets: empty tiles adjacent to each type, ready to be claimed next spread
    g_cands = set()
    m_cands = set()

    for dx,dy in DIRS:
        n = (X_G+dx, Y_G+dy)
        if n not in grid: g_cands.add(n)
    for dx,dy in DIRS:
        n = (X_M+dx, Y_M+dy)
        if n not in grid: m_cands.add(n)

    def expand_grass(g_cands, m_cands):
        if not g_cands: return g_cands
        new_cands = set()
        for tile in g_cands:
            if tile in grid: continue  # already claimed by mycelium this round
            grid[tile] = GRASS
            m_cands.discard(tile)
            x, y = tile
            for dx,dy in DIRS:
                n = (x+dx, y+dy)
                if n not in grid:
                    new_cands.add(n)
        return new_cands

    def expand_myc(m_cands, g_cands, myc_count):
        if not m_cands: return m_cands, myc_count
        new_cands = set()
        for tile in m_cands:
            if tile in grid: continue
            grid[tile] = MYC
            g_cands.discard(tile)
            myc_count += 1
            x, y = tile
            for dx,dy in DIRS:
                n = (x+dx, y+dy)
                if n not in grid:
                    new_cands.add(n)
        return new_cands, myc_count

    # Simulate in 14-tick blocks (LCM of 2 and 7).
    # Within each block:
    # Ticks 2,4,6  -> grass spreads (3 times)
    # Tick  7      -> mycelium spreads (1 time)
    # Ticks 8,10,12-> grass spreads (3 more times)
    # Tick  14     -> grass AND mycelium spread simultaneously; grass wins conflicts

    while True:
        if not m_cands:
            break

        # Ticks 2, 4, 6: grass x3
        g_cands = expand_grass(g_cands, m_cands)
        g_cands = expand_grass(g_cands, m_cands)
        g_cands = expand_grass(g_cands, m_cands)

        # Tick 7: mycelium x1
        m_cands, myc_count = expand_myc(m_cands, g_cands, myc_count)

        # Ticks 8, 10, 12: grass x3
        g_cands = expand_grass(g_cands, m_cands)
        g_cands = expand_grass(g_cands, m_cands)
        g_cands = expand_grass(g_cands, m_cands)

        # Tick 14: simultaneous spread - grass wins conflicts
        new_g = {tile for tile in g_cands if tile not in grid}
        new_m = {tile for tile in m_cands if tile not in grid and tile not in new_g}

        next_g = set()
        for tile in new_g:
            grid[tile] = GRASS
            m_cands.discard(tile)
            x, y = tile
            for dx,dy in DIRS:
                n = (x+dx, y+dy)
                if n not in grid: next_g.add(n)

        next_m = set()
        for tile in new_m:
            grid[tile] = MYC
            g_cands.discard(tile)
            myc_count += 1
            x, y = tile
            for dx,dy in DIRS:
                n = (x+dx, y+dy)
                if n not in grid: next_m.add(n)

        g_cands = next_g
        m_cands = next_m - next_g  # grass wins any overlap in next round too

    return myc_count


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()