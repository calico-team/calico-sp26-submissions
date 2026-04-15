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
    
    grass_frontier = {(X_G, Y_G)}
    mycelium_frontier = {(X_M, Y_M)}
    
    dist = abs(X_G - X_M) + abs(Y_G - Y_M)
    max_ticks = min(30000, dist * 15)
    
    tick = 0
    no_growth_ticks = 0
    
    while tick < max_ticks and no_growth_ticks < 14:
        tick += 1
        
        if tick % 2 == 0:
            new_grass_frontier = set()
            for x, y in grass_frontier:
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        grass.add((nx, ny))
                        new_grass_frontier.add((nx, ny))
            grass_frontier = new_grass_frontier
        
        if tick % 7 == 0:
            new_mycelium_frontier = set()
            for x, y in mycelium_frontier:
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        mycelium.add((nx, ny))
                        mycelium_ever.add((nx, ny))
                        new_mycelium_frontier.add((nx, ny))
            
            if not new_mycelium_frontier:
                no_growth_ticks += 7
            else:
                no_growth_ticks = 0
            
            mycelium_frontier = new_mycelium_frontier
    
    return len(mycelium_ever)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()