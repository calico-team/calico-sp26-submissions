from fractions import Fraction

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    # YOUR CODE HERE
    # return (-1, -1)
    DIR = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1),
    }

    def in_bounds(r, c):
        return 0 <= r < N and 0 <= c < M

    def splitter_children(r, c):
        res = []

        nr, nc = r - 1, c
        if in_bounds(nr, nc):
            ch = factory[nr][nc]
            if ch  == 'X' or (ch in DIR and ch != 'v'):
                res.append((nr, nc))

        nr, nc = r + 1, c
        if in_bounds(nr, nc):
            ch = factory[nr][nc]
            if ch  == 'X' or (ch in DIR and ch != '^'):
                res.append((nr, nc))

        nr, nc = r, c - 1
        if in_bounds(nr, nc):
            ch = factory[nr][nc]
            if ch  == 'X' or (ch in DIR and ch != '>'):
                res.append((nr, nc))

        nr, nc = r, c + 1
        if in_bounds(nr, nc):
            ch = factory[nr][nc]
            if ch  == 'X' or (ch in DIR and ch != '<'):
                res.append((nr, nc))

        return res

    def children(r, c):
        ch = factory[r][c]

        if ch  == 'X':
            return []
        if ch in DIR:
            dr, dc = DIR[ch]
            nr, nc = r + dr, c + dc
            if in_bounds(nr, nc):
                return [(nr, nc)]
            return []
        if ch  == 'S':
            return splitter_children(r, c)
        return []

    state = [[0] * M for _ in range(N)]
    dp = [[None] * M for _ in range(N)]

    stack = [(0, 0, 0)]

    while stack:
        r, c, phase = stack.pop()

        if phase  == 0:
            if state[r][c]  == 2:
                continue
            if state[r][c]  == 1:
                continue

            state[r][c] = 1
            stack.append((r, c, 1))

            for nr, nc in children(r, c):
                if state[nr][nc]  == 0:
                    stack.append((nr, nc, 0))
        else:
            ch = factory[r][c]

            if ch  == 'X':
                dp[r][c] = Fraction(0, 1)

            elif ch in DIR:
                dr, dc = DIR[ch]
                nr, nc = r + dr, c + dc
                if in_bounds(nr, nc):
                    dp[r][c] = dp[nr][nc]
                else:
                    dp[r][c] = Fraction(1, 1)

            elif ch  == 'S':
                nxt = splitter_children(r, c)
                total = Fraction(0, 1)
                row = len(nxt)
                for nr, nc in nxt:
                    total += dp[nr][nc]
                dp[r][c] = total / row

            else:
                dp[r][c] = Fraction(0, 1)

            state[r][c] = 2

    ans = dp[0][0]
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
