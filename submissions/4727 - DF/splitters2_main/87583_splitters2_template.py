def solve(P, A, B):
    if P == 0:
        return ['X']
    Q = (2 ** A) * (3 ** B)
    if P == Q:
        return ['>']

    steps = []
    pp, qq = P, Q
    while qq > 1:
        if qq % 2 == 0:
            half = qq // 2
            collect_side = (pp >= half)
            if collect_side:
                pp -= half
            steps.append(('2', collect_side))
            qq = half
        elif qq % 3 == 0:
            third = qq // 3
            trit = pp // third
            pp = pp % third
            steps.append(('3', trit))
            qq = third
    collect_main = pp

    n = len(steps)
    M = 2 * n + 2
    row0 = ['.'] * M
    row1 = ['.'] * M
    row2 = ['.'] * M

    row0[0] = 'v'
    row1[0] = '>'

    for k, (split_type, info) in enumerate(steps):
        sc = 2 * k + 1
        row1[sc] = 'S'
        row1[sc + 1] = '>'
        if split_type == '2':
            row2[sc] = 'v' if info else 'X'
        else:
            trit = info
            if trit == 0:
                row2[sc] = 'X'
                row0[sc] = 'X'
            elif trit == 1:
                row2[sc] = 'v'
                row0[sc] = 'X'
            else:
                row2[sc] = 'v'
                row0[sc] = '^'

    row1[2 * n + 1] = '>' if collect_main else 'X'

    return [''.join(row0), ''.join(row1), ''.join(row2)]


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
