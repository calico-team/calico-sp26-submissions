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
    
    grass_active = {(X_G, Y_G)}
    mycelium_active = {(X_M, Y_M)}
    
    dist = abs(X_G - X_M) + abs(Y_G - Y_M)
    max_ticks = min(200000, dist * 30)
    
    for tick in range(1, max_ticks + 1):
        new_grass_active = set()
        new_mycelium_active = set()
        
        if tick % 2 == 0:
            for x, y in grass_active:
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        grass.add((nx, ny))
                        new_grass_active.add((nx, ny))
            grass_active = new_grass_active
        
        if tick % 7 == 0:
            for x, y in mycelium_active:
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        mycelium.add((nx, ny))
                        mycelium_ever.add((nx, ny))
                        new_mycelium_active.add((nx, ny))
            
            mycelium_active = new_mycelium_active
            if not new_mycelium_active:
                break
    
    return len(mycelium_ever)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()