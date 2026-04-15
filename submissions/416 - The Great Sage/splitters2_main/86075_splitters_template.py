from fractions import Fraction

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    # YOUR CODE HERE
    directons = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1),
    }

    back = {
        '^': 'v',
        'v': '^',
        '<': '>',
        '>': '<',
    }

    memo = {}

    def dfs(r, c):
        if (r, c) in memo:
            return memo[(r, c)]

        tile = factory[r][c]

        if tile == 'X':
            memo[(r, c)] = Fraction(0, 1)
            return memo[(r, c)]

        if tile in directons:
            dr, dc = directons[tile]
            nr, nc = r + dr, c + dc

            if not (0 <= nr < N and 0 <= nc < M):
                memo[(r, c)] = Fraction(1, 1)
            else:
                memo[(r, c)] = dfs(nr, nc)
            return memo[(r, c)]

        if tile == 'S':
            nxt = []
            for ch, (dr, dc) in directons.items():
                nr, nc = r + dr, c + dc
                if not (0 <= nr < N and 0 <= nc < M):
                    continue

                t = factory[nr][nc]
                if t == 'X':
                    nxt.append((nr, nc))
                elif t in directons and t != back[ch]:
                    nxt.append((nr, nc))

            total = Fraction(0, 1)
            for nr, nc in nxt:
                total += dfs(nr, nc)

            memo[(r, c)] = total / len(nxt)
            return memo[(r, c)]

        memo[(r, c)] = Fraction(0, 1)
        return memo[(r, c)]

    ans = dfs(0, 0)
    return (ans.numerator, ans.denominator)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
