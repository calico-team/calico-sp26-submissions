def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    # YOUR CODE HERE
    factors = [2] * A + [3] * B

    gadgets = []
    cur = P
    a = A
    b = B

    for d in factors:
        if d == 2:
            a -= 1
        else:
            b -= 1

        denom_rest = (1 << a) * (3 ** b)
        q, rem = divmod(cur, denom_rest)

        collect = q
        cont = 1 if rem > 0 else 0
        destroy = d - collect - cont

        gadgets.append((d, collect, cont, destroy))
        cur = rem

        if cur == 0:
            break

    M = 5
    N = 2 * len(gadgets) + 3
    grid = [['.' for _ in range(M)] for _ in range(N)]

    grid[0][0] = '>'
    grid[0][1] = '>'
    grid[0][2] = 'v'
    grid[1][2] = 'v'

    for counter, (d, collect, cont, destroy) in enumerate(gadgets):
        r = 2 * counter + 2
        grid[r][2] = 'S'

        if d == 2:

            if cont:

                grid[r + 1][2] = 'v'

                if collect == 1:
                    grid[r][1] = '<'
                    grid[r][0] = '<'
                else:
                    grid[r][1] = 'X'
            else:

                if collect >= 1:
                    grid[r][1] = '<'
                    grid[r][0] = '<'
                else:
                    grid[r][1] = 'X'

                grid[r][3] = 'X'

        else:

            if collect >= 1:
                grid[r][1] = '<'
                grid[r][0] = '<'
            else:
                grid[r][1] = 'X'

            if collect >= 2:
                grid[r][3] = '>'
                grid[r][4] = '>'
            else:
                grid[r][3] = 'X'

            if cont:
                grid[r + 1][2] = 'v'
            else:
                grid[r + 1][2] = 'X'

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
