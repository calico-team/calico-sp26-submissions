def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # The maximum distance between G and M is 800 (from -200 to 200 in both axes).
    # Grass speed is 1 tile / 2 ticks. Mycelium speed is 1 tile / 7 ticks.
    # Grass closes the distance at a relative speed of 5/14 tiles per tick.
    # It takes a maximum of ~2240 ticks for Grass to completely overtake Mycelium.
    # In 2240 ticks, Grass will expand by a radius of 1120 tiles.
    # A grid spanning +/- 1500 from the center is more than enough to prevent any bounds violations.
    OFFSET = 1500
    GRID_SIZE = 3000
    
    # Using a 1D bytearray for the grid provides maximum speed and minimal memory overhead (~9MB).
    # States -> 0: empty, 1: Grass, 2: Mycelium
    grid = bytearray(GRID_SIZE * GRID_SIZE)
    
    # Calculate initial 1D array positions
    g_pos = (X_G + OFFSET) * GRID_SIZE + (Y_G + OFFSET)
    m_pos = (X_M + OFFSET) * GRID_SIZE + (Y_M + OFFSET)
    
    grid[g_pos] = 1
    grid[m_pos] = 2
    
    g_front = [g_pos]
    m_front = [m_pos]
    
    m_count = 1
    tick = 1
    
    # 1D movement offsets corresponding to (0, -1), (0, 1), (-1, 0), (1, 0)
    up = -GRID_SIZE
    down = GRID_SIZE
    left = -1
    right = 1
    
    # Simulation runs until Mycelium has no empty adjacent tiles left to expand into.
    # Because Grass expands 3.5x faster, it is mathematically guaranteed to engulf Mycelium.
    while m_front:
        is_g_tick = (tick % 2 == 0)
        is_m_tick = (tick % 7 == 0)
        
        # Apply Grass expansion first to naturally handle the tie-breaking rule:
        # "If both grass and mycelium convert the same tile on the same tick, it converts to grass"
        if is_g_tick:
            new_g_front = []
            append_g = new_g_front.append
            for pos in g_front:
                # Check all 4 adjacent neighbors
                for nxt_pos in (pos + up, pos + down, pos + left, pos + right):
                    if grid[nxt_pos] == 0:
                        grid[nxt_pos] = 1
                        append_g(nxt_pos)
            g_front = new_g_front
            
        if is_m_tick:
            new_m_front = []
            append_m = new_m_front.append
            for pos in m_front:
                for nxt_pos in (pos + up, pos + down, pos + left, pos + right):
                    if grid[nxt_pos] == 0:
                        grid[nxt_pos] = 2
                        append_m(nxt_pos)
                        m_count += 1
            m_front = new_m_front
            
        tick += 1
        
    return m_count


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()