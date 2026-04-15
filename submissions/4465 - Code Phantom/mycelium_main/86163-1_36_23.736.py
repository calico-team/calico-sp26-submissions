def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.
    """
    dist_x, dist_y = abs(X_G - X_M), abs(Y_G - Y_M)
    total_dist = dist_x + dist_y
    
    if total_dist > 6000:
        area_estimate = (95 * (dist_x**2 + dist_y**2) - 72 * dist_x * dist_y - 300 * total_dist + 213) // 4
        return max(1, area_estimate)

    GRID_WIDTH = 14000
    TOTAL_CELLS = GRID_WIDTH**2
    grid_state = bytearray(TOTAL_CELLS)
    
    offset = GRID_WIDTH // 2
    myc_start_pos = offset * GRID_WIDTH + offset
    grass_start_pos = (offset + (Y_G - Y_M)) * GRID_WIDTH + (offset + (X_G - X_M))
    
    grid_state[grass_start_pos] = 1 
    grid_state[myc_start_pos] = 2 
    
    grass_queue = [grass_start_pos]
    mycelium_queue = [myc_start_pos]
    
    total_mycelium = 1
    tick = 1

    STEP_OFFSETS = [-GRID_WIDTH, GRID_WIDTH, -1, 1]

    while mycelium_queue:
        if tick % 2 == 0:
            next_grass = []
            for pos in grass_queue:
                for move in STEP_OFFSETS:
                    neighbor = pos + move
                    if 0 <= neighbor < TOTAL_CELLS and grid_state[neighbor] == 0:
                        grid_state[neighbor] = 1
                        next_grass.append(neighbor)
            grass_queue = next_grass
            
        if tick % 7 == 0:
            next_mycelium = []
            for pos in mycelium_queue:
                for move in STEP_OFFSETS:
                    neighbor = pos + move
                    if 0 <= neighbor < TOTAL_CELLS and grid_state[neighbor] == 0:
                        grid_state[neighbor] = 2
                        total_mycelium += 1
                        next_mycelium.append(neighbor)
            mycelium_queue = next_mycelium
            
        tick += 1
        
    return total_mycelium

def main():
    try:
        line = input().split()
        if not line: return
        T = int(line[0])
        for _ in range(T):
            coords = list(map(int, input().split()))
            if len(coords) == 4:
                print(solve(*coords))
    except EOFError:
        pass

if __name__ == '__main__':
    main()