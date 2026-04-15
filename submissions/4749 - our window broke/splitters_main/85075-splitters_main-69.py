from fractions import Fraction

def solve(N, M, factory):
    grid = [list(row) for row in factory]
    memo = [[None] * M for _ in range(N)]

    def dfs(r, c):
        if memo[r][c] is not None:
            return memo[r][c]
        ch = grid[r][c]

        if ch == 'X':
            res = Fraction(0, 1)

        elif ch in '^<>v':
            dirs = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}
            dr, dc = dirs[ch]
            nr, nc = r + dr, c + dc
            if nr < 0 or nr >= N or nc < 0 or nc >= M:
                res = Fraction(1, 1)
            else:
                res = dfs(nr, nc)

        elif ch == 'S':
            neighbors = []
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M:
                    nch = grid[nr][nc]
                    if nch == 'X':
                        neighbors.append((nr, nc))
                    elif nch in '^<>v':
                        ndir = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}[nch]
                        if (nr + ndir[0], nc + ndir[1]) != (r, c):
                            neighbors.append((nr, nc))
            total = Fraction(0, 1)
            for nr, nc in neighbors:
                total += dfs(nr, nc)
            res = total / len(neighbors)

        else:
            res = Fraction(0, 1)

        memo[r][c] = res
        return res

    prob = dfs(0, 0)
    return prob.numerator, prob.denominator

def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input().strip() for _ in range(N)]
        p, q = solve(N, M, factory)
        print(p, q)


if __name__ == '__main__':
    main()