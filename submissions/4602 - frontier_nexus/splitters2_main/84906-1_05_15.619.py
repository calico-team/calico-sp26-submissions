import sys
from fractions import Fraction

input = sys.stdin.readline


def build_factory(P, A, B):
    K = A + B

    if K == 0:
        return ["^"]

    stage_types = [2] * A + [3] * B

    D = (2 ** A) * (3 ** B)
    shares = D
    remaining = P - 1
    decisions = []

    for st in stage_types:
        branch = shares // st
        if st == 2:
            if remaining >= branch:
                collect = 1
                remaining -= branch
            else:
                collect = 0
            decisions.append(('2', collect))
        else:
            max_collect = min(2, remaining // branch)
            collect = max_collect
            remaining -= collect * branch
            decisions.append(('3', collect))
        shares = shares // st

    M = 2 * K + 2
    N = 3

    row0 = ['.'] * M
    row1 = ['.'] * M
    row2 = ['.'] * M

    row0[0] = 'v'
    row1[0] = '>'
    row1[1] = '>'

    for i, (st, collect) in enumerate(decisions):
        c = 2 + 2 * i
        row1[c] = 'S'
        if c + 1 < M:
            row1[c + 1] = '>'

        if st == '2':
            if collect == 1:
                row0[c] = '^'
                row2[c] = '.'
            else:
                row0[c] = '.'
                row2[c] = 'X'
        else:
            if collect == 0:
                row0[c] = '<'
                row0[c - 1] = 'X'
                row2[c] = 'X'
            elif collect == 1:
                row0[c] = '^'
                row2[c] = 'X'
            else:
                row0[c] = '^'
                row2[c] = 'v'

    grid = [''.join(row0), ''.join(row1), ''.join(row2)]
    return grid


def solve():
    P, A, B = map(int, input().split())
    grid = build_factory(P, A, B)
    N = len(grid)
    M = len(grid[0])
    print(N, M)
    for row in grid:
        print(row)


def main():
    T = int(input())
    for _ in range(T):
        solve()


def destroy_the_tiles():
    pass


def read_your_input():
    pass


main()