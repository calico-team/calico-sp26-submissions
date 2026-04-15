def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """

    EMPTY, GRASS, MYC = 0, 1, 2
    grid = {}
    grid[(X_G, Y_G)] = GRASS
    grid[(X_M, Y_M)] = MYC

    dirs = [(0,1),(0,-1),(1,0),(-1,0)]
    seen = set()
    seen.add((X_M, Y_M))

    def get(x, y):
        return grid.get((x, y), EMPTY)

    for tick in range(1, 2001):
        grass_expand = set()
        myc_expand = set()

        if tick % 2 == 0:
            for (x, y), t in list(grid.items()):
                if t == GRASS:
                    for dx, dy in dirs:
                        nx, ny = x+dx, y+dy
                        if get(nx, ny) == EMPTY:
                            grass_expand.add((nx, ny))

        if tick % 7 == 0:
            for (x, y), t in list(grid.items()):
                if t == MYC:
                    for dx, dy in dirs:
                        nx, ny = x+dx, y+dy
                        if get(nx, ny) == EMPTY:
                            myc_expand.add((nx, ny))

        # grass wins ties
        myc_expand -= grass_expand

        for pos in grass_expand:
            grid[pos] = GRASS
        for pos in myc_expand:
            grid[pos] = MYC
            seen.add(pos)

        # check if mycelium is fully enclosed
        stuck = True
        for (x, y), t in grid.items():
            if t == MYC:
                for dx, dy in dirs:
                    if get(x+dx, y+dy) == EMPTY:
                        stuck = False
                        break
            if not stuck:
                break
        if stuck:
            break

    return len(seen)

def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
