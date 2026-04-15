def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    mappin = {"#":1,".":0}
    rv2 = []
    rv1 = []
    grid1 = []
    mx = 0
    mn = 0

    for i in S2:
        rv2.append(sum([*map(mappin.get, list(i))]))
    for i in S1:
        rv1.append(sum([*map(mappin.get, list(i))]))
        grid1.append([*map(mappin.get, list(i))])
    for row_index, row in enumerate(grid1):
        for item in row:
            mx += (item * rv2[row_index])
        mn += min(rv1[row_index], rv2[row_index])

    # YOUR CODE HERE
    return mx, mn


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
