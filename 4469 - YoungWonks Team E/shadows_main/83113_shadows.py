def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    
    minvol = 0
    maxvol = 0

    for z in range(N):
        c1 = S1[z].count("#")
        c2 = S2[z].count("#")

        if c1 > 0 and c2 > 0:
            minvol += max(c1, c2)
            maxvol += c1*c2

    return maxvol, minvol


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
