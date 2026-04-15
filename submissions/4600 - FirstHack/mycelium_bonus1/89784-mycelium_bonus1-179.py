from collections import deque

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """

    GRASS, MYC = 1, 2
    grid = {}
    grid[(X_G, Y_G)] = GRASS
    if (X_M, Y_M) != (X_G, Y_G):
        grid[(X_M, Y_M)] = MYC

    dirs = [(0,1),(0,-1),(1,0),(-1,0)]
    seen = set()
    if grid.get((X_M, Y_M)) == MYC:
        seen.add((X_M, Y_M))

    grass_frontier = set([(X_G, Y_G)])
    myc_frontier = set([(X_M, Y_M)]) if grid.get((X_M, Y_M)) == MYC else set()

    for tick in range(1, 20001):
        if tick % 2 == 0:
            next_grass = set()
            for x, y in grass_frontier:
                for dx, dy in dirs:
                    nx, ny = x+dx, y+dy
                    if (nx, ny) not in grid:
                        grid[(nx, ny)] = GRASS
                        next_grass.add((nx, ny))
            grass_frontier = next_grass

        if tick % 7 == 0:
            next_myc = set()
            for x, y in myc_frontier:
                for dx, dy in dirs:
                    nx, ny = x+dx, y+dy
                    if (nx, ny) not in grid:
                        grid[(nx, ny)] = MYC
                        seen.add((nx, ny))
                        next_myc.add((nx, ny))
            myc_frontier = next_myc

        if not myc_frontier and tick % 7 == 0:
            break

    return len(seen)

def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
