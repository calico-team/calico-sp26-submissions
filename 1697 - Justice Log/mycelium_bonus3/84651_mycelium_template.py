def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    grass = set([(X_G, Y_G)])
    mycelium = set([(X_M, Y_M)])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    maxTick = 100000000000

    tick = 0

    while tick < maxTick:

        tick += 1

        new_grass = set()

        if tick % 2 == 0:

            for x, y in grass:

                for dx, dy in directions:

                    nx, ny = x + dx, y + dy

                    if (nx, ny) not in grass and (nx, ny) not in mycelium:

                        new_grass.add((nx, ny))

            grass.update(new_grass)

        if tick % 7 == 0:

            newMycelium = set()

            for x, y in mycelium:

                for dx, dy in directions:

                    nx, ny = x + dx, y + dy

                    if (nx, ny) not in grass and (nx, ny) not in mycelium:

                        newMycelium.add((nx, ny))

            mycelium.update(newMycelium)

            if not newMycelium:

                break

    return len(mycelium)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
