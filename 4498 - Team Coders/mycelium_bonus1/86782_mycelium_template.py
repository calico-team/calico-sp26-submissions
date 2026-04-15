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
    mycelium_ever = {(X_M, Y_M)}
    
    # Calculate max distance
    dist = abs(X_G - X_M) + abs(Y_G - Y_M)
    max_ticks = min(50000, dist * 20)
    
    for tick in range(1, max_ticks + 1):
        new_grass = set()
        new_mycelium = set()
        
        # Grass spreads every 2 ticks
        if tick % 2 == 0:
            for x, y in list(grass):
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        new_grass.add((nx, ny))
        
        # Mycelium spreads every 7 ticks
        if tick % 7 == 0:
            for x, y in list(mycelium):
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        # Grass wins if both claim same tile
                        if (nx, ny) not in new_grass:
                            new_mycelium.add((nx, ny))
        
        grass.update(new_grass)
        mycelium.update(new_mycelium)
        mycelium_ever.update(new_mycelium)
        
        # Stop if mycelium can't spread anymore
        if not new_mycelium and tick % 7 == 0:
            break
    
    return len(mycelium_ever)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()