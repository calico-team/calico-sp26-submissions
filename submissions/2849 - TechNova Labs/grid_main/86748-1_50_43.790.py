import sys


def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    two_heights = [0 for _ in range(N)]

    left = [0 for _ in range(N)]
    right = [0 for _ in range(N)]
    left[0] = A[0]
    right[0] = A[0]

    for i in range(1, N):
        a = A[i]
        prev_ll = left[i - 1]
        prev_rr = right[i - 1]
        if a < prev_ll:
            left[i] = a
            right[i] = prev_ll
        elif a > prev_rr:
            left[i] = prev_rr
            right[i] = a
        else:
            left[i] = a
            right[i] = a

    two_heights[N - 1] = left[N - 1]
    for i in range(N - 2, -1, -1):
        nxt = two_heights[i + 1]
        if nxt < left[i]:
            two_heights[i] = left[i]
        elif nxt > right[i]:
            two_heights[i] = right[i]
        else:
            two_heights[i] = nxt

    return two_heights


def read_input():
    data = [int(tok) for tok in sys.stdin.read().split() if tok.lstrip("-").isdigit()]
    if not data:
        return []

    it1 = iter(data)
    t = int(next(it1))
    cases = []
    for _ in range(t):
        n = int(next(it1))
        a = [int(next(it1)) for _ in range(n)]
        cases.append((n, a))
    return cases


def main():
    cases = read_input()
    out = []
    for n, a in cases:
        result = solve(n, a)
        out.append(' '.join(str(x) for x in result))
    sys.stdout.write('\n'.join(out))


if __name__ == '__main__':
    main()
