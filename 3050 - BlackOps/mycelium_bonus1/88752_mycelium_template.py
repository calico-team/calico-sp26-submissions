def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    grass = {(X_G, Y_G)}
    myc = {(X_M, Y_M)}
    total = {(X_M, Y_M)}
    dirs = [(0,1),(0,-1),(1,0),(-1,0)]

    def expand(tiles, blocked):
        new = set()
        for x, y in tiles:
            for dx, dy in dirs:
                nb = (x+dx, y+dy)
                if nb not in blocked:
                    new.add(nb)
        return new

    for tick in range(1, 200001):
        g_turn = tick % 2 == 0
        m_turn = tick % 7 == 0

        new_g = expand(grass, grass | myc) if g_turn else set()
        new_m = expand(myc, grass | myc) if m_turn else set()

        new_m -= new_g

        grass |= new_g
        myc |= new_m
        total |= new_m

        if m_turn and not new_m:
            frontier = expand(myc, myc)
            if frontier <= grass:  
                break

    return len(total)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
