import sys
import math
import heapq
from collections import deque
from array import array


def read_ints():
    data = sys.stdin.buffer.read()
    n = len(data)
    i = 0
    while i < n:
        while i < n and data[i] <= 32:
            i += 1
        if i >= n:
            break
        num = 0
        while i < n and data[i] > 32:
            num = num * 10 + (data[i] - 48)
            i += 1
        yield num


def solve(N, M, D, it):
    if M == 0:
        return [1] * N, []

    # Edge storage in compact arrays.
    R = array('I')
    C = array('I')
    V = array('I')
    W = array('I')
    nxt = array('i', [-1]) * M
    head = [-1] * 1001

    for idx in range(M):
        r = next(it) - 1
        c = next(it) - 1
        v = next(it)
        w = next(it)
        R.append(r)
        C.append(c)
        V.append(v)
        W.append(w)
        nxt[idx] = head[w]
        head[w] = idx

    parent = list(range(N))
    rank = [0] * N

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(a, b):
        a = find(a)
        b = find(b)
        if a == b:
            return False
        if rank[a] < rank[b]:
            a, b = b, a
        parent[b] = a
        if rank[a] == rank[b]:
            rank[a] += 1
        return True

    is_tree = bytearray(M)
    adj = [[] for _ in range(N)]

    # One high-weight-first Kruskal order, memory-light.
    for w in range(1000, 0, -1):
        i = head[w]
        while i != -1:
            r = R[i]
            c = C[i]
            if union(r, c):
                is_tree[i] = 1
                adj[r].append((c, i))
                adj[c].append((r, i))
            i = nxt[i]

    x = [0.0] * N
    color = [-1] * N
    for start in range(N):
        if color[start] != -1:
            continue
        color[start] = 0
        q = deque([start])
        while q:
            node = q.popleft()
            base = x[node]
            for nb, ei in adj[node]:
                if color[nb] == -1:
                    x[nb] = math.log(V[ei]) - base
                    color[nb] = color[node] ^ 1
                    q.append(nb)

    s = [1.0 if c == 0 else -1.0 for c in color]

    # Collect a few promising t candidates from heavy non-tree edges only.
    top_targets = []  # min-heap of (weight, target)
    k_cands = 7 if M <= 400000 else 4
    for w in range(1000, 0, -1):
        i = head[w]
        while i != -1:
            if not is_tree[i]:
                coeff = s[R[i]] + s[C[i]]
                if coeff != 0.0:
                    target = (math.log(V[i]) - x[R[i]] - x[C[i]]) / coeff
                    if len(top_targets) < k_cands:
                        heapq.heappush(top_targets, (W[i], target))
                    elif W[i] > top_targets[0][0]:
                        heapq.heapreplace(top_targets, (W[i], target))
            i = nxt[i]

    t_candidates = [0.0]
    t_candidates.extend(t for _, t in top_targets)
    # Deduplicate while preserving order-ish.
    seen = set()
    uniq_t = []
    for t in t_candidates:
        key = round(t, 12)
        if key not in seen:
            seen.add(key)
            uniq_t.append(t)
    t_candidates = uniq_t

    d = min(D, M)

    def estimate_c(t):
        step = max(1, M // 512)
        vals = []
        for i in range(0, M, step):
            vals.append(math.log(V[i]) - x[R[i]] - x[C[i]] - (s[R[i]] + s[C[i]]) * t)
        vals.sort()
        return vals[len(vals) // 2] / 2.0 if vals else 0.0

    def score_t(t):
        c = estimate_c(t)
        if d == 0:
            total = 0.0
            for i in range(M):
                y = x[R[i]] + x[C[i]] + (s[R[i]] + s[C[i]]) * t + 2.0 * c
                est = math.exp(min(40.0, max(-40.0, y)))
                total += W[i] * abs(est - V[i]) / V[i]
            return total, c
        if d >= M:
            return 0.0, c
        total = 0.0
        largest = []
        for i in range(M):
            y = x[R[i]] + x[C[i]] + (s[R[i]] + s[C[i]]) * t + 2.0 * c
            est = math.exp(min(40.0, max(-40.0, y)))
            pen = W[i] * abs(est - V[i]) / V[i]
            total += pen
            if len(largest) < d:
                heapq.heappush(largest, pen)
            elif pen > largest[0]:
                heapq.heapreplace(largest, pen)
        return total - sum(largest), c

    best_t = 0.0
    best_c = 0.0
    best_score = float('inf')
    for t in t_candidates:
        sc, c = score_t(t)
        if sc < best_score:
            best_score = sc
            best_t = t
            best_c = c

    a = [0] * N
    for i in range(N):
        xi = x[i] + s[i] * best_t + best_c
        if xi <= 0.0:
            a[i] = 1
        elif xi >= 20.7:
            a[i] = 10**9
        else:
            a[i] = max(1, min(10**9, round(math.exp(xi))))

    if d == 0:
        return a, []
    if d >= M:
        return a, list(range(1, M + 1))

    top = []  # min-heap of (pen, idx)
    for i in range(M):
        pen = W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
        item = (pen, i + 1)
        if len(top) < d:
            heapq.heappush(top, item)
        elif item[0] > top[0][0]:
            heapq.heapreplace(top, item)
    discards = sorted(idx for _, idx in top)
    return a, discards


def main():
    it = iter(read_ints())
    N = next(it)
    M = next(it)
    D = next(it)
    A, discards = solve(N, M, D, it)
    out = []
    out.append(' '.join(map(str, A)))
    if discards:
        out.append(str(len(discards)) + ' ' + ' '.join(map(str, discards)))
    else:
        out.append('0')
    sys.stdout.write('\n'.join(out))


if __name__ == '__main__':
    main()
