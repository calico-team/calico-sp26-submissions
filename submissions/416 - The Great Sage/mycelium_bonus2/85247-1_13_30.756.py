def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    grass = {(X_G, Y_G)}
    mycelium = {(X_M, Y_M)}

    grass_edge = {(X_G, Y_G)}
    myc_edge = {(X_M, Y_M)}

    d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    t = 0

    while True:
        t += 1
        add_grass = set()
        add_myc = set()

        if t % 2 == 0:
            for x, y in grass_edge:
                for dx, dy in d:
                    nx = x + dx
                    ny = y + dy
                    p = (nx, ny)
                    if p not in grass and p not in mycelium:
                        add_grass.add(p)

        if t % 7 == 0:
            for x, y in myc_edge:
                for dx, dy in d:
                    nx = x + dx
                    ny = y + dy
                    p = (nx, ny)
                    if p not in grass and p not in mycelium and p not in add_grass:
                        add_myc.add(p)

        if add_grass:
            grass |= add_grass
            grass_edge = add_grass
        elif t % 2 == 0:
            grass_edge = set()

        if add_myc:
            mycelium |= add_myc
            myc_edge = add_myc
        elif t % 7 == 0:
            return len(mycelium)

    return -1


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
