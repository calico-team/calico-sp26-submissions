import sys
import math

def solve(N, M, D, cells):
    adj = [[] for _ in range(N)]
    edges = []
    for idx, (r, c, v, w) in enumerate(cells):
        u = r - 1
        vv = c - 1
        edges.append((u, vv, v, w, idx + 1))
        adj[u].append((vv, v, w, idx + 1))
        adj[vv].append((u, v, w, idx + 1))
    init_vals = {1}
    for v in range(2, 11):
        init_vals.add(v)
    for (_, V, _, _) in adj[0]:
        for d in range(1, int(math.isqrt(V)) + 1):
            if V % d == 0:
                if d <= 10 ** 9:
                    init_vals.add(d)
                if V // d <= 10 ** 9:
                    init_vals.add(V // d)
    init_vals = list(init_vals)[:200]

    best_penalty = float('inf')
    best_a = None
    best_discards = None

    for init in init_vals:
        a = [None] * N
        a[0] = init
        queue = [0]
        qptr = 0
        while qptr < len(queue):
            u = queue[qptr]
            qptr += 1
            for v, V, _, _ in adj[u]:
                if a[u] is None:
                    continue
                if a[v] is None:
                    if V % a[u] == 0:
                        target = V // a[u]
                        if 1 <= target <= 10 ** 9:
                            a[v] = target
                            queue.append(v)
        for i in range(N):
            if a[i] is None:
                a[i] = 1
        errors = []
        for u, v, V, W, idx in edges:
            prod = a[u] * a[v]
            err = W * abs(prod - V) / V
            errors.append((err, idx))
        errors.sort(reverse=True)
        discard_cnt = min(D, len(errors))
        penalty = sum(e for e, _ in errors) - sum(errors[i][0] for i in range(discard_cnt))

        if penalty < best_penalty - 1e-9:
            best_penalty = penalty
            best_a = a[:]
            best_discards = [idx for _, idx in errors[:discard_cnt]]

    if best_a is None:
        best_a = [1] * N
        best_discards = []
    return best_a, best_discards


def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    N = int(next(it))
    M = int(next(it))
    D = int(next(it))
    cells = []
    for _ in range(M):
        R = int(next(it))
        C = int(next(it))
        V = int(next(it))
        W = int(next(it))
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + discards))


if __name__ == '__main__':
    main()