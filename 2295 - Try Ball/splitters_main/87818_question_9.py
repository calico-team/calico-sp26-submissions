from fractions import Fraction

dir = {
    '^': (-1, 0),
    'v': (1, 0),
    '<': (0, -1),
    '>': (0, 1)
}

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    grid = [list(row) for row in factory]
    dp = [[None] * M for _ in range(N)]
    vis = [[0] * M for _ in range(N)]

    def dfs(i, j):
        if dp[i][j] is not None:
            return dp[i][j]

        if vis[i][j] == 1:
            return Fraction(0, 1)

        vis[i][j] = 1
        tile = grid[i][j]

        if tile == 'X':
            dp[i][j] = Fraction(0, 1)
        elif tile in dir:
            di, dj = dir[tile]
            ni, nj = i + di, j + dj
            if not (0 <= ni < N and 0 <= nj < M):
                dp[i][j] = Fraction(1, 1)
            else:
                dp[i][j] = dfs(ni, nj)
        elif tile == 'S':
            neighbors = []

            for di, dj in dir.values():
                ni, nj = i + di, j + dj

                if not (0 <= ni < N and 0 <= nj < M):
                    continue

                ntile = grid[ni][nj]

                if ntile == '.':
                    continue

                if ntile in dir:
                    rdi, rdj = dir[ntile]
                    if ni + rdi == i and nj + rdj == j:
                        continue

                neighbors.append((ni, nj))

            if not neighbors:
                dp[i][j] = Fraction(0, 1)
            else:
                total = Fraction(0, 1)
                for ni, nj in neighbors:
                    total += dfs(ni, nj)

                dp[i][j] = total / len(neighbors)

        else:
            dp[i][j] = Fraction(0, 1)

        vis[i][j] = 2
        return dp[i][j]

    result = dfs(0, 0)
    return result.numerator, result.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
