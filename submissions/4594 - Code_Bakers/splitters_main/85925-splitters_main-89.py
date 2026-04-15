def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    # YOUR CODE HERE

  
    from fractions import Fraction
    import sys
    sys.setrecursionlimit(10**7)

    dirs = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1)
    }

    memo = {}

    def inside(i, j):
        return 0 <= i < N and 0 <= j < M

    def dfs(i, j):
        if not inside(i, j):
            return Fraction(1, 1)

        cell = factory[i][j]

        if cell == 'X':
            return Fraction(0, 1)

        if cell == '.':
            return Fraction(0, 1)

        if (i, j) in memo:
            return memo[(i, j)]

        memo[(i, j)] = Fraction(0, 1)  # prevent recursion crash

        # conveyor
        if cell in dirs:
            di, dj = dirs[cell]
            memo[(i, j)] = dfs(i + di, j + dj)
            return memo[(i, j)]

        # splitter
        if cell == 'S':
            total = Fraction(0, 1)
            cnt = 0

            for di, dj in dirs.values():
                ni, nj = i + di, j + dj

                if inside(ni, nj):
                    nxt = factory[ni][nj]
                    if nxt != '.':
                        total += dfs(ni, nj)
                        cnt += 1

            if cnt == 0:
                memo[(i, j)] = Fraction(0, 1)
            else:
                memo[(i, j)] = total / cnt

            return memo[(i, j)]

        return Fraction(0, 1)

    ans = dfs(0, 0)
    return ans.numerator, ans.denominator

def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
