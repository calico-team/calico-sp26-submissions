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
    sys.setrecursionlimit(1000000)

    dirs = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1)
    }

    memo = {}
    visiting = set()

    def go(i, j):
        if i < 0 or i >= N or j < 0 or j >= M:
            return Fraction(1, 1)

        if factory[i][j] == 'X':
            return Fraction(0, 1)

        if (i, j) in memo:
            return memo[(i, j)]

        if (i, j) in visiting:
            return Fraction(0, 1)

        visiting.add((i, j))

        cell = factory[i][j]

        # conveyor
        if cell in dirs:
            di, dj = dirs[cell]
            res = go(i + di, j + dj)

        # splitter
        elif cell == 'S':
            total = Fraction(0, 1)
            count = 0

            for di, dj in dirs.values():
                ni, nj = i + di, j + dj

                if 0 <= ni < N and 0 <= nj < M:
                    nxt = factory[ni][nj]
                    if nxt == 'X' or nxt in dirs or nxt == 'S':
                        total += go(ni, nj)
                        count += 1

            if count == 0:
                res = Fraction(0, 1)
            else:
                res = total / count

        else:
            res = Fraction(0, 1)

        visiting.remove((i, j))
        memo[(i, j)] = res
        return res

    ans = go(0, 0)

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
