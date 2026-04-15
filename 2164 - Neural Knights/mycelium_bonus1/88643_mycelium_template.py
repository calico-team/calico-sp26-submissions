from collections import deque

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    create_voronoi_7 = True
    
    # For large coordinates, use optimized Voronoi approach
    max_coord = max(abs(X_G), abs(Y_G), abs(X_M), abs(Y_M))
    
    if max_coord > 500:
        return solve_voronoi_optimized(X_G, Y_G, X_M, Y_M)
    
    # Simulation for small coordinates
    grass = {(X_G, Y_G)}
    mycelium = {(X_M, Y_M)}
    all_tiles = grass | mycelium
    
    prev_myc_size = 1
    stable_rounds = 0
    
    for round_num in range(10000):
        for tick_offset in range(1, 15):
            tick = round_num * 14 + tick_offset
            
            new_grass = set()
            new_mycelium = set()
            
            if tick % 2 == 0:
                for x, y in grass:
                    for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in all_tiles:
                            new_grass.add((nx, ny))
            
            if tick % 7 == 0:
                for x, y in mycelium:
                    for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in all_tiles:
                            new_mycelium.add((nx, ny))
            
            grass.update(new_grass)
            mycelium.update(new_mycelium - new_grass)
            all_tiles.update(new_grass)
            all_tiles.update(new_mycelium - new_grass)
        
        if len(mycelium) == prev_myc_size:
            stable_rounds += 1
            if stable_rounds >= 3:
                break
        else:
            stable_rounds = 0
            prev_myc_size = len(mycelium)
    
    return len(mycelium)


def solve_voronoi_optimized(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """Solve using optimized Voronoi approach for large coordinates."""
    # Mycelium occupies tile (x,y) if: 7*Manhattan(x,y->M) < 2*Manhattan(x,y->G)
    # Use BFS limited by max distance from mycelium start
    
    count = 0
    visited = set()
    queue = deque([(X_M, Y_M, 0)])
    visited.add((X_M, Y_M))
    
    # Bound search by the initial distance plus margin
    max_search = abs(X_G - X_M) + abs(Y_G - Y_M) + 500
    
    while queue:
        x, y, d_m = queue.popleft()
        d_g = abs(x - X_G) + abs(y - Y_G)
        
        if 7 * d_m < 2 * d_g:
            count += 1
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if (nx, ny) not in visited and abs(nx - X_M) + abs(ny - Y_M) <= max_search:
                    visited.add((nx, ny))
                    queue.append((nx, ny, d_m + 1))
    
    return count


def read_your_input():
    """Helper function to read input."""
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
