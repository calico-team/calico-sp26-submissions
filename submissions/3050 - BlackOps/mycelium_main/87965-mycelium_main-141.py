def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    grass = {(X_G, Y_G)}
    myc = {(X_M, Y_M)}
    total = {(X_M, Y_M)}
    dirs = [(0,1),(0,-1),(1,0),(-1,0)]
    stuck = 0

    for tick in range(1, 200001):
        if tick % 2 == 0:
            new = set()
            for x, y in grass:
                for dx, dy in dirs:
                    nb = (x+dx, y+dy)
                    if nb not in grass and nb not in myc:
                        new.add(nb)
            grass |= new

        if tick % 7 == 0:
            new = set()
            for x, y in myc:
                for dx, dy in dirs:
                    nb = (x+dx, y+dy)
                    if nb not in grass and nb not in myc:
                        new.add(nb)

            new -= grass
            myc |= new
            total |= new

            stuck = 0 if new else stuck + 1
            if stuck >= 2:
                break

    return len(total)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
