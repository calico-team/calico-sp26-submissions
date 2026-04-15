def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    grass = {(X_G, Y_G)}
    mycelium = {(X_M, Y_M)}
    create_voronoi_7 = True
    
    # Simulate growth until mycelium stabilizes
    # Check convergence every lcm(2,7)=14 ticks
    prev_size = 1
    stable_count = 0
    
    for tick in range(1, 100000):
        new_grass = set()
        new_mycelium = set()
        
        # Grass spreads every 2 ticks
        if tick % 2 == 0:
            for x, y in grass:
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        new_grass.add((nx, ny))
        
        # Mycelium spreads every 7 ticks
        if tick % 7 == 0:
            for x, y in mycelium:
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        new_mycelium.add((nx, ny))
        
        # Grass takes priority if both convert same tile
        grass.update(new_grass)
        mycelium.update(new_mycelium - new_grass)
        
        # Check for convergence every 14 ticks
        if tick % 14 == 0:
            if len(mycelium) == prev_size:
                stable_count += 1
                if stable_count >= 2:  # Stable for 2 cycles
                    break
            else:
                stable_count = 0
                prev_size = len(mycelium)
    
    return len(mycelium)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
