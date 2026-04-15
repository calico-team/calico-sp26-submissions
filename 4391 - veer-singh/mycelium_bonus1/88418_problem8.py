def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """

    o = {}
    o[(X_G, Y_G)] = 1
    o[(X_M, Y_M)] = 2

    gFr = {(X_G, Y_G)}
    mFr = {(X_M, Y_M)}
    mCnt = 1
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    def nF(f, add):
        poss = f | add
        result = set()

        for x, y in poss:
            for dx, dy in directions:
                nx = x + dx
                ny = y + dy
                if (nx, ny) not in o:
                    result.add((x, y))
                    break
        return result

    t = 1

    debug = False

    while True:
        gAdd = set()
        mAdd = set()

        if t % 2 == 0:
            for x, y in gFr:
                for dx, dy in directions:
                    nx = x + dx
                    ny = y + dy
                    if (nx, ny) not in o:
                        gAdd.add((nx, ny))

        if t % 7 == 0:
            for x, y in mFr:
                for dx, dy in directions:
                    nx = x + dx
                    ny = y + dy
                    if (nx, ny) not in o:
                        mAdd.add((nx, ny))

        if gAdd and mAdd:
            mAdd -= gAdd

        for x, y in gAdd:
            o[(x, y)] = 1

        for x, y in mAdd:
            o[(x, y)] = 2

        mCnt += len(mAdd)

        gFr = nF(gFr, gAdd)
        mFr = nF(mFr, mAdd)

        if t % 7 == 0 and len(mAdd) == 0:
            return mCnt

        t += 1


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()