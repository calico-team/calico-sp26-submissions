def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    D = abs(X_M - X_G) + abs(Y_M - Y_G)
    if D == 0:
        return 0
    
    dirs = [(0,1),(0,-1),(1,0),(-1,0)]
    prune_dist = D + 10
    
    claimed = set()
    grass_frontier = [(X_G, Y_G)]
    mycelium_frontier = [(X_M, Y_M)]
    claimed.add((X_G, Y_G))
    claimed.add((X_M, Y_M))
    mycelium_count = 1
    g_layer = 0
    m_layer = 0
    
    while mycelium_frontier:
        g_time = 2 * (g_layer + 1)
        m_time = 7 * (m_layer + 1)
        
        if g_time <= m_time:
            new_frontier = []
            for (gx, gy) in grass_frontier:
                for dx, dy in dirs:
                    nx, ny = gx + dx, gy + dy
                    if (nx, ny) not in claimed:
                        claimed.add((nx, ny))
                        if abs(nx - X_M) + abs(ny - Y_M) <= prune_dist:
                            new_frontier.append((nx, ny))
            grass_frontier = new_frontier
            g_layer += 1
            
            if g_time == m_time:
                new_m_frontier = []
                for (mx, my) in mycelium_frontier:
                    for dx, dy in dirs:
                        nx, ny = mx + dx, my + dy
                        if (nx, ny) not in claimed:
                            claimed.add((nx, ny))
                            mycelium_count += 1
                            new_m_frontier.append((nx, ny))
                mycelium_frontier = new_m_frontier
                m_layer += 1
        else:
            new_m_frontier = []
            for (mx, my) in mycelium_frontier:
                for dx, dy in dirs:
                    nx, ny = mx + dx, my + dy
                    if (nx, ny) not in claimed:
                        claimed.add((nx, ny))
                        mycelium_count += 1
                        new_m_frontier.append((nx, ny))
            mycelium_frontier = new_m_frontier
            m_layer += 1
    
    return mycelium_count


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()