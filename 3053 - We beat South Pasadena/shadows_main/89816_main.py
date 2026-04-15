def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    # YOUR CODE HERE
    maximum = 0
    minimum = 0
    for layer in range(N): ## each layer, vertically
        for letter in range(N): ## along S1
            if S1[layer][letter] == "#":
                maximum += S2[layer].count("#")
        minimum += max(S1[layer].count("#"), S2[layer].count("#"))
    return maximum, minimum


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
