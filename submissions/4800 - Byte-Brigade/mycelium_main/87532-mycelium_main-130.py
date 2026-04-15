def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    grass = {(X_G, Y_G)}
    mycelium = {(X_M, Y_M)}
    total_mycelium = set(mycelium)

    direction = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    for tic in range(1, 10000):
        occupied = grass | mycelium

        new_grass = set()
        if tic %2 == 0:
            for (x, y) in grass:
                for dx, dy in direction:
                    nb = (x + dx, y + dy)
                    if nb not in occupied:
                        new_grass.add(nb)

        new_mycelium = set()
        if tic % 7 ==0:
            for (x, y) in mycelium:
                for dx, dy in direction:
                    nb = (x + dx, y + dy)
                    if nb not in occupied and nb not in new_grass:
                        new_mycelium.add(nb)

        grass = grass | new_grass
        mycelium = mycelium | new_mycelium
        total_mycelium = total_mycelium | new_mycelium

        if not new_mycelium and tic %7 == 0:
            break

    return len(total_mycelium)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
