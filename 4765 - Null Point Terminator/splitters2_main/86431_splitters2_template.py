def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    # YOUR CODE HERE
    def _capped_pow(a, b, limit):
        x = 1
        for _ in range(a):
            if x > limit // 2:
                return limit + 1
            x *= 2
        for _ in range(b):
            if x > limit // 3:
                return limit + 1
            x *= 3
        return x

    steps = []

    while True:
        if A > 0:
            d = _capped_pow(A - 1, B, P)
            take = 1 if d <= P else 0
            nxt = P - (d if take else 0)
            nA, nB = A - 1, B

            if nxt == 0:
                down = 'D'
            elif nA == 0 and nB == 0 and nxt == 1:
                down = 'C'
            else:
                down = 'R'

            steps.append((2, take, down))

            if down != 'R':
                break

            P, A, B = nxt, nA, nB
        else:
            d = _capped_pow(A, B - 1, P)
            take = 0 if d > P else P // d
            if take > 2:
                take = 2
            nxt = P - take * d
            nA, nB = A, B - 1

            if nxt == 0:
                down = 'D'
            elif nA == 0 and nB == 0 and nxt == 1:
                down = 'C'
            else:
                down = 'R'

            steps.append((3, take, down))

            if down != 'R':
                break

            P, A, B = nxt, nA, nB

    N = 2 * len(steps) + 1
    M = 3
    grid = [['.'] * M for _ in range(N)]

    grid[0][0] = '>'
    grid[0][1] = 'v'

    for i, (typ, val, down) in enumerate(steps):
        r = 2 * i + 1
        grid[r][1] = 'S'

        if typ == 2:
            grid[r][2] = '>' if val == 1 else 'X'
        else:
            if val == 0:
                grid[r][0] = 'X'
                grid[r][2] = 'X'
            elif val == 1:
                grid[r][0] = '<'
                grid[r][2] = 'X'
            else:
                grid[r][0] = '<'
                grid[r][2] = '>'

        grid[r + 1][1] = 'X' if down == 'D' else 'v'

    return [''.join(row) for row in grid]

def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()
