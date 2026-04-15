def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    count = 0

    for x in range(-200, 201):
        for y in range(-200, 201):
            dM = abs(x - X_M) + abs(y - Y_M)
            dG = abs(x - X_G) + abs(y - Y_G)
            
            if 7 * dM < 2 * dG:
                count += 1

    return count

def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
