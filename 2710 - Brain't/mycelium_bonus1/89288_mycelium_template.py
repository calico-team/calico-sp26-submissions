def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    if (X_G, Y_G) == (X_M, Y_M):
        return 1

    grass = set([(X_G, Y_G)])
    mycel = set([(X_M, Y_M)])
    counter = 1
    dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    t = 0
    MAX_T = 20000

    while t < MAX_T:
        t += 1

        nai_grass = set()
        if t % 2 == 0:
            for x, y in list(grass):
                for dx, dy in dirs:
                    nx = x + dx
                    ny = y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycel:
                        nai_grass.add((nx, ny))

        n_mycel = set()
        if t % 7 == 0:
            for x, y in list(mycel):
                for dx, dy in dirs:
                    nx = x + dx
                    ny = y + dy
                    if (nx, ny) not in grass and (nx, ny) not in mycel:
                        n_mycel.add((nx, ny))

        conflicct = nai_grass & n_mycel
        n_mycel -= conflicct

        grass.update(nai_grass)

        for p in n_mycel:
            if p not in mycel:
                mycel.add(p)
                counter += 1

        if len(n_mycel) == 0 and t > 100 and t % 14 == 0:
            if t > 500 or len(grass) > 10000:
                break

    return counter

def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
