def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    max_vol = 0
    min_vol = 0

    for z in range(N):
        row1 = S1[z]  # x-axis shadow
        row2 = S2[z]  # y-axis shadow

        cols1 = [x for x in range(N) if row1[x] == '#']
        cols2 = [y for y in range(N) if row2[y] == '#']

        # max:- fill every valid (x,y) intersection
        max_vol += len(cols1) * len(cols2)

        # min:- cover all x's in cols1 and all y's in cols2
        min_vol += max(len(cols1), len(cols2))

    return max_vol, min_vol


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
