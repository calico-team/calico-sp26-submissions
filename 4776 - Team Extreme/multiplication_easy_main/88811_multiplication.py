import sys
from math import log, exp
from collections import defaultdict

def solve(N, M, D, cells):
    """
    Return a tuple (A, discards) where:
      A: list of N integers in [1, 10^9]
      discards: list of at most D distinct 1-indexed cell indices to discard

    The discards output line will begin with t, the number of discarded
    cells, followed by those t indices; t is computed and written for
    you in main().

    N: length of the array A
    M: number of cells
    D: maximum number of cells you may discard
    cells: list of M tuples (R, C, V, W); for cell k (1-indexed), the product
           A[R] * A[C] should be close to the target V, with weight W
    """
    gr = defaultdict(list)
    for R, C, V, W in cells:
        ev = log(V)
        gr[R].append((C, ev, W))
        gr[C].append((R, ev, W))

    la = [0.0] * (N + 1)

    for _ in range(50):
        nt = [0.0] * (N + 1)
        tw = [0.0] * (N + 1)
        for i in range(1, N + 1):
            for j, ev, w in gr[i]:
                nt[i] += w * (ev - la[j])
                tw[i] += w
        for i in range(1, N + 1):
            if tw[i] > 0:
                la[i] = nt[i] / tw[i]

    arr = [0] + [max(1, min(10**9, round(exp(la[i])))) for i in range(1, N + 1)]

    sc = []
    for i, (R, C, V, W) in enumerate(cells):
        sc.append((W * abs(arr[R] * arr[C] - V) / V, i + 1))
    sc.sort(reverse=True)

    better_than_me = arr[1:]
    drop = [sc[i][1] for i in range(D)]

    return better_than_me, drop


def main():
    N, M, D = map(int, input().split())
    cells = []
    for _ in range(M):
        R, C, V, W = map(int, input().split())
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))


def read_your_input():
    pass


if __name__ == '__main__':
    main()