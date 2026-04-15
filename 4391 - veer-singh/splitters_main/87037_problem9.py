from fractions import Fraction

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """

    def go(r, c):
        ch = factory[r][c]

        if ch == 'X':
            return 0.0
        if ch == '^':
            return 1.0 if r == 0 else go(r - 1, c)
        if ch == 'v':
            return 1.0 if r == N - 1 else go(r + 1, c)
        if ch == '<':
            return 1.0 if c == 0 else go(r, c - 1)
        if ch == '>':
            return 1.0 if c == M - 1 else go(r, c + 1)

        vals = []

        if r > 0:
            ch2 = factory[r - 1][c]
            if ch2 == 'X':
                vals.append(0.0)

            elif ch2 != '.' and ch2 != 'v':
                vals.append(go(r - 1, c))

        if r < N - 1:
            ch2 = factory[r + 1][c]
            if ch2 == 'X':
                vals.append(0.0)

            elif ch2 != '.' and ch2 != '^':
                vals.append(go(r + 1, c))

        if c > 0:
            ch2 = factory[r][c - 1]
            if ch2 == 'X':
                vals.append(0.0)

            elif ch2 != '.' and ch2 != '>':
                vals.append(go(r, c - 1))

        if c < M - 1:
            ch2 = factory[r][c + 1]
            if ch2 == 'X':
                vals.append(0.0)

            elif ch2 != '.' and ch2 != '<':
                vals.append(go(r, c + 1))

        return sum(vals)/len(vals)

    frac = Fraction(go(0, 0)).limit_denominator(1000000)

    return (frac.numerator, frac.denominator)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()