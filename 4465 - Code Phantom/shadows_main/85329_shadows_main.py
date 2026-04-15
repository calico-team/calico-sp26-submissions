def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)

    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    rows = min(N, len(S1), len(S2))
    R1 = [row.count('#') for row in S1[:rows]]
    R2 = [row.count('#') for row in S2[:rows]]

    max_volume = sum(r1 * r2 for r1, r2 in zip(R1, R2))
    min_volume = sum(max(r1, r2) for r1, r2 in zip(R1, R2))

    return max_volume, min_volume


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input().strip() for _ in range(N)]
        S2 = [input().strip() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
