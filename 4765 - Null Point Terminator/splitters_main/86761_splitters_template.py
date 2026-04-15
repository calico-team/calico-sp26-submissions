from fractions import Fraction
from functools import lru_cache

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    # YOUR CODE HERE
    dirs = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1),
    }

    def _inside(r, c):
        return 0 <= r < N and 0 <= c < M

    def _splitter_neighbors(r, c):
        res = []

        nr, nc = r - 1, c
        ch = factory[nr][nc]
        if ch == 'X' or ch in '<>^v' and ch != 'v':
            res.append((nr, nc))

        nr, nc = r + 1, c
        ch = factory[nr][nc]
        if ch == 'X' or ch in '<>^v' and ch != '^':
            res.append((nr, nc))

        nr, nc = r, c - 1
        ch = factory[nr][nc]
        if ch == 'X' or ch in '<>^v' and ch != '>':
            res.append((nr, nc))

        nr, nc = r, c + 1
        ch = factory[nr][nc]
        if ch == 'X' or ch in '<>^v' and ch != '<':
            res.append((nr, nc))

        return res

    @lru_cache(None)
    def dp(r, c):
        ch = factory[r][c]

        if ch == 'X':
            return Fraction(0, 1)

        if ch in '<>^v':
            dr, dc = dirs[ch]
            nr, nc = r + dr, c + dc
            if not _inside(nr, nc):
                return Fraction(1, 1)
            return dp(nr, nc)

        if ch == 'S':
            nxt = _splitter_neighbors(r, c)
            total = Fraction(0, 1)
            for nr, nc in nxt:
                total += dp(nr, nc)
            return total / len(nxt)

        return Fraction(0, 1)

    res = dp(0, 0)
    return (res.numerator, res.denominator)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
