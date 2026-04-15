from collections import deque

def solve(X_G, Y_G, X_M, Y_M):
    def get_grass_tick(x, y):
        return 2 * (abs(x - X_G) + abs(y - Y_G))

    def get_mycelium_tick(x, y):
        # Manhattan distance from starting mycelium
        return 7 * (abs(x - X_M) + abs(y - Y_M))

    # Starting tile is always occupied by mycelium 
    q = deque([(X_M, Y_M)])
    vis = set([(X_M, Y_M)])
    count = 0

    while q:
        cx, cy = q.popleft()
        count += 1
        
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = cx + dx, cy + dy
            if (nx, ny) not in vis:
                # Mycelium spreads to neighbor ONLY if it gets there strictly 
                # before grass. If ticks are equal, grass wins[cite: 481].
                if get_mycelium_tick(nx, ny) < get_grass_tick(nx, ny):
                    vis.add((nx, ny))
                    q.append((nx, ny))
    return count