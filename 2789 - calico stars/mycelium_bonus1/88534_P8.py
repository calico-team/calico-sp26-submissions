def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    voronoi7 = None

    t = set()
    r = set()
    t.add((X_G, Y_G))
    r.add((X_M, Y_M))

    mycelium = set(r)

    dirs = [(0,1),(0,-1),(1,0),(-1,0)]

    MAXT = 200

    for tick in range(1, MAXT + 1):
        newt = set()
        newr = set()

        if tick % 2 == 0:
            for (x, y) in t:
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in t and (nx, ny) not in r:
                        newt.add((nx, ny))

        if tick % 7 == 0:
            for (x, y) in r:
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in t and (nx, ny) not in r:
                        newr.add((nx, ny))

        conflict = newt & newr
        newr -= conflict

        t |= newt
        t |= conflict
        r |= newr
        mycelium |= newr

    return len(mycelium)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()