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


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
