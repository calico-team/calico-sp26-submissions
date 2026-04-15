def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    occ = {}
    occ[(X_G, Y_G)] = 'g'
    occ[(X_M, Y_M)] = 'm'

    gf = [(X_G, Y_G)]
    mf = [(X_M, Y_M)]
    gs = 0
    ms = 0
    ans = 1

    dr = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    while mf:
        gt = 2 * (gs + 1)
        mt = 7 * (ms + 1)

        if gt < mt:
            nf = []
            for x, y in gf:
                for dx, dy in dr:
                    p = (x + dx, y + dy)
                    if p not in occ:
                        occ[p] = 'g'
                        nf.append(p)
            gf = nf
            gs += 1

        elif gt > mt:
            nf = []
            for x, y in mf:
                for dx, dy in dr:
                    p = (x + dx, y + dy)
                    if p not in occ:
                        occ[p] = 'm'
                        nf.append(p)
                        ans += 1
            mf = nf
            ms += 1

        else:
            ng = set()
            nm = set()

            for x, y in gf:
                for dx, dy in dr:
                    p = (x + dx, y + dy)
                    if p not in occ:
                        ng.add(p)

            for x, y in mf:
                for dx, dy in dr:
                    p = (x + dx, y + dy)
                    if p not in occ:
                        nm.add(p)

            nm -= ng

            for p in ng:
                occ[p] = 'g'
            for p in nm:
                occ[p] = 'm'
                ans += 1

            gf = list(ng)
            mf = list(nm)
            gs += 1
            ms += 1

    return ans


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
