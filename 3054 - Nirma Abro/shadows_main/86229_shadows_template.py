def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)

    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    # YOUR CODE HERE
    max_volume = 0
    min_volume = 0

    for z in range(N):

        count1 = S1[z].count("#")
        count2 = S2[z].count("#")

        if count1 > 0 and count2 > 0:
            max_volume += count1 * count2
            min_volume += max(count1, count2)

    return max_volume, min_volume


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == "__main__":
    main()
