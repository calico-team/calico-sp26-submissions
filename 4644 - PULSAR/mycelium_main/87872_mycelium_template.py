def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    tile = 2
    grass = set()
    grass.add((X_G, Y_G))
    mycelium = set()
    mycelium.add((X_M, Y_M))
    distance = abs(X_M - X_G) + abs(Y_M - Y_G)
    for _ in range(distance*10):
        if tile%2 == 0: # grass expand
            for i in range((-tile//2), (tile//2)+1):
                if (X_G + i, Y_G + (tile//2) - i) not in mycelium:
                    grass.add((X_G + i, Y_G + (tile//2) - i))
            for i in range((-tile//2), (tile//2)+1):
                if (X_G + i, Y_G - (tile//2) - i) not in mycelium:
                    grass.add((X_G + i, Y_G - (tile//2) - i))
            for i in range(0, (tile//2)+1):
                if (X_G - i, Y_G - i + (tile//2)) not in mycelium:
                    grass.add((X_G - i, Y_G - i + (tile//2)))
            for i in range(0, (tile//2)+1):
                if (X_G + i, Y_G + i - (tile//2)) not in mycelium:
                    grass.add((X_G + i, Y_G + i - (tile//2)))
        if tile%7 == 0:
            for i in range((-tile//7), (tile//7)+1):
                if (X_M + i, Y_M + (tile//7) - i) not in grass:
                    mycelium.add((X_M + i, Y_M + (tile//7) - i))
            for i in range((-tile//7), (tile//7)+1):
                if (X_M + i, Y_M - (tile//7) - i) not in grass:
                    mycelium.add((X_M + i, Y_M - (tile//7) - i))
            for i in range(0, (tile//7)+1):
                if (X_M - i, Y_M - i + (tile//7)) not in grass:
                    mycelium.add((X_M - i, Y_M - i + (tile//7)))
            for i in range(0, (tile//7)+1):
                if (X_M + i, Y_M + i - (tile//7)) not in grass:
                    mycelium.add((X_M + i, Y_M + i - (tile//7)))
        tile += 1
    return len(mycelium)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
