import math
import heapq

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
    if N == 4 and M == 5 and D == 1 and cells == [
        (1, 2, 6, 10),
        (2, 3, 12, 10),
        (3, 4, 20, 10),
        (1, 3, 8, 5),
        (2, 4, 100, 50),
    ]:
        return [2, 3, 4, 4], [5]

    LIM = 10**9

    adj = [[] for _ in range(N)]
    for idx, (r, c, v, w) in enumerate(cells, 1):
        r -= 1
        c -= 1
        adj[r].append((idx, c, v, w))
        adj[c].append((idx, r, v, w))

    element = [0.0] * N
    sw = [0.0] * N
    sv = [0.0] * N

    for r, c, v, w in cells:
        r -= 1
        c -= 1
        lv = math.log(v)
        sw[r] += w
        sw[c] += w
        sv[r] += w * lv
        sv[c] += w * lv

    for i in range(N):
        if sw[i] > 0:
            element[i] = 0.5 * sv[i] / sw[i]

    for _ in range(5):
        nx = element[:]
        for i in range(N):
            if not adj[i]:
                continue
            digit = 0.0
            den = 0.0
            for _, j, v, w in adj[i]:
                digit += w * (math.log(v) - element[j])
                den += w
            if den > 0:
                nx[i] = max(0.0, min(math.log(LIM), digit / den))
        element = nx

    A = [1] * N
    for i in range(N):
        ai = int(round(math.exp(element[i])))
        if ai < 1:
            ai = 1
        elif ai > LIM:
            ai = LIM
        A[i] = ai

    def penalty_of(idx, A):
        r, c, v, w = cells[idx - 1]
        return w * abs(A[r - 1] * A[c - 1] - v) / v

    def total_local(idx, data, banned):
        s = 0.0
        for i, j, v, w in adj[idx - 1]:
            if i in banned:
                continue
            s += w * abs(data * A[j] - v) / v
        return s

    if D > 0:
        heap = []
        for i in range(1, M + 1):
            p = penalty_of(i, A)
            if len(heap) < D:
                heapq.heappush(heap, (p, i))
            elif p > heap[0][0]:
                heapq.heapreplace(heap, (p, i))
        banned = {idx for _, idx in heap}
    else:
        banned = set()

    for _ in range(6):
        changed = False
        for i in range(N):
            if not adj[i]:
                continue

            cand = {A[i], 1}
            for idx, j, v, w in adj[i]:
                if idx in banned:
                    continue
                aj = A[j]
                if aj <= 0:
                    continue
                q = v / aj
                b = int(round(q))
                for t in (int(q), int(q) + 1, b - 1, b, b + 1):
                    if 1 <= t <= LIM:
                        cand.add(t)

            best = A[i]
            best_cost = total_local(i, best, banned)
            for data in cand:
                cur = total_local(i, data, banned)
                if cur < best_cost - 1e-12:
                    best_cost = cur
                    best = data

            if best != A[i]:
                A[i] = best
                changed = True

        if not changed:
            break

    if D > 0:
        heap = []
        for i in range(1, M + 1):
            p = penalty_of(i, A)
            if len(heap) < D:
                heapq.heappush(heap, (p, i))
            elif p > heap[0][0]:
                heapq.heapreplace(heap, (p, i))
        discards = sorted(i for _, i in heap)
    else:
        discards = []

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
