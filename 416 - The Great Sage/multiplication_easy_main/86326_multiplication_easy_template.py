import math

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
    # YOUR CODE HERE
    u = [True] * M
    d = [0] * N
    s = [0] * N

    for i, (r, c, v, w) in enumerate(cells):
        val = w * v
        s[r - 1] += val
        s[c - 1] += val
        d[r - 1] += w
        d[c - 1] += w

    logs = [0.0] * N
    for i in range(N):
        if d[i]:
            logs[i] = math.log(max(1, s[i] // d[i])) / 2.0

    for _ in range(2):
        next = [0.0] * N
        count = [0] * N
        for i, (r, c, v, w) in enumerate(cells):
            if not u[i]:
                continue
            r -= 1
            c -= 1
            need = math.log(v)
            next[r] += (need - logs[c]) * w
            next[c] += (need - logs[r]) * w
            count[r] += w
            count[c] += w
        for i in range(N):
            if count[i]:
                logs[i] = next[i] / count[i]

    A = [1] * N
    LIM = 10**9
    for i in range(N):
        x = int(round(math.exp(logs[i])))
        if x < 1:
            x = 1
        if x > LIM:
            x = LIM
        A[i] = x

    bed = []
    for i, (r, c, v, w) in enumerate(cells, 1):
        got = A[r - 1] * A[c - 1]
        cur = w * abs(got - v) / v
        bed.append((cur, i))

    bed.sort(reverse=True)
    discards = []
    for i in range(min(D, M)):
        discards.append(bed[i][1])

    return A, discards


def main():
    N, M, D = map(int, input().split())
    cells = []
    for _ in range(M):
        R, C, V, W = map(int, input().split())
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))


if __name__ == '__main__':
    main()
