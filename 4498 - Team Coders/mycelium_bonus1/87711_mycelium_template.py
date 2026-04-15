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
    
    tick = 0
    no_mycelium_growth_count = 0
    
    while no_mycelium_growth_count < 14:
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
                no_mycelium_growth_count += 7
            else:
                no_mycelium_growth_count = 0
            
            mycelium_frontier = new_mycelium_frontier
        
        if tick > 100000:
            break
    
    return len(mycelium_ever)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()