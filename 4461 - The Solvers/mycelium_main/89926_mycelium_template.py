def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    # Manhattan distance between starting points
    D = abs(X_G - X_M) + abs(Y_G - Y_M)

    # Number of layers mycelium can expand before grass dominates
    k = (D - 1) // 5

    # Total tiles in diamond region
    return (k + 1) * (k + 1) + k * k


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()