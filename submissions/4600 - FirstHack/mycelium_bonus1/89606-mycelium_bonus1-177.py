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
    grid[(X_M, Y_M)] = MYC

    dirs = [(0,1),(0,-1),(1,0),(-1,0)]
    seen = set()
    seen.add((X_M, Y_M))

    # only track frontier (tiles that have empty neighbors)
    grass_frontier = deque([(X_G, Y_G)])
    myc_frontier = deque([(X_M, Y_M)])

    def neighbors(x, y):
        for dx, dy in dirs:
            yield x+dx, y+dy

    for tick in range(1, 20001):
        if tick % 2 == 0:
            for _ in range(len(grass_frontier)):
                x, y = grass_frontier.popleft()
                if grid.get((x,y)) != GRASS:
                    continue
                for nx, ny in neighbors(x, y):
                    if (nx, ny) not in grid:
                        grid[(nx, ny)] = GRASS
                        grass_frontier.append((nx, ny))

        if tick % 7 == 0:
            new_myc = []
            for _ in range(len(myc_frontier)):
                x, y = myc_frontier.popleft()
                if grid.get((x,y)) != MYC:
                    continue
                for nx, ny in neighbors(x, y):
                    if (nx, ny) not in grid:
                        new_myc.append((nx, ny))

            for pos in new_myc:
                if pos not in grid:  # grass might have just filled it
                    grid[pos] = MYC
                    seen.add(pos)
                    myc_frontier.append(pos)

        if not myc_frontier:
            break

    return len(seen)

def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
