import sys
import math
import heapq
from collections import deque
from itertools import chain
from array import array

SMALL_THRESHOLD = 180000


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


def strong_solve(N, M, D, cells):
    if M == 0:
        return [1] * N, []
    R = [c[0] - 1 for c in cells]
    C = [c[1] - 1 for c in cells]
    V = [float(c[2]) for c in cells]
    W = [float(c[3]) for c in cells]
    logV = [math.log(v) for v in V]
    if M > 300000:
        n_ord = 1; k_cands = 3; cd_rounds = 0
    elif M > 80000:
        n_ord = 2; k_cands = 7; cd_rounds = 2
    else:
        n_ord = 2; k_cands = 15; cd_rounds = 8
    buckets = [[] for _ in range(1001)]
    for i in range(M):
        buckets[int(W[i])].append(i)
    all_orders = [list(chain.from_iterable(buckets)), list(chain.from_iterable(reversed(buckets)))][:n_ord]

    def build_spanning_tree(edge_order):
        parent = list(range(N)); rank = [0] * N

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def union(a, b):
            a, b = find(a), find(b)
            if a == b:
                return False
            if rank[a] < rank[b]:
                a, b = b, a
            parent[b] = a
            if rank[a] == rank[b]:
                rank[a] += 1
            return True

        tree = []; nontree = []
        for i in edge_order:
            (tree if union(R[i], C[i]) else nontree).append(i)
        return tree, nontree

    def bfs_assign(tree_edges):
        adj = [[] for _ in range(N)]
        for i in tree_edges:
            adj[R[i]].append((C[i], i))
            adj[C[i]].append((R[i], i))
        x = [None] * N; color = [None] * N
        for start in range(N):
            if x[start] is None:
                x[start] = 0.0; color[start] = 0; q = deque([start])
                while q:
                    node = q.popleft()
                    for nb, ei in adj[node]:
                        if x[nb] is None:
                            x[nb] = logV[ei] - x[node]
                            color[nb] = 1 - color[node]
                            q.append(nb)
        for i in range(N):
            if x[i] is None:
                x[i] = 0.0
            if color[i] is None:
                color[i] = 0
        return x, color

    def eval_tc(A, B, t):
        exp = math.exp
        sz = min(500, M); step = max(1, M // sz)
        sample_bt = sorted(logV[i * step] - A[i * step] - B[i * step] * t for i in range(sz))
        c = sample_bt[len(sample_bt) // 2] / 2
        pens = [W[i] * abs(exp(min(max(A[i] + B[i] * t + 2 * c, -40.0), 40.0)) - V[i]) / V[i] for i in range(M)]
        if D <= 0:
            return sum(pens), pens, c
        d = min(D, M)
        if d >= M:
            return 0.0, pens, c
        top = heapq.nlargest(d, pens)
        return sum(pens) - sum(top), pens, c

    def coord_descent(x_init, active, rounds):
        x = x_init[:]
        nc = [[] for _ in range(N)]
        for i in active:
            nc[R[i]].append(i)
            nc[C[i]].append(i)
        for _ in range(rounds):
            for node in range(N):
                cons = nc[node]
                if not cons:
                    continue
                tgts = [(logV[ci] - x[C[ci] if R[ci] == node else R[ci]], W[ci]) for ci in cons]
                tgts.sort()
                tw = sum(w for _, w in tgts); cw = 0.0
                for tv, wv in tgts:
                    cw += wv
                    if cw * 2 >= tw:
                        x[node] = tv
                        break
        return x

    def final_from_x(x):
        a = [max(1, min(10**9, round(math.exp(min(max(xi, 0.0), 20.7))))) for xi in x]
        pens = [(W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i], i) for i in range(M)]
        pens.sort(reverse=True)
        d = min(D, M)
        discards = sorted(pens[j][1] + 1 for j in range(d)) if d > 0 else []
        return a, discards, sum(p for p, _ in pens[d:])

    def spanning_tree_solve(edge_order):
        tree, nontree = build_spanning_tree(edge_order)
        x, color = bfs_assign(tree)
        s = [1.0 if color[i] == 0 else -1.0 for i in range(N)]
        A = [x[R[i]] + x[C[i]] for i in range(M)]
        B = [s[R[i]] + s[C[i]] for i in range(M)]
        t_cands = [0.0]; t_tgts = []; w_tgts = []
        for i in nontree:
            coeff = s[R[i]] + s[C[i]]
            if coeff != 0.0:
                t_tgts.append((logV[i] - x[R[i]] - x[C[i]]) / coeff)
                w_tgts.append(W[i])
        if t_tgts:
            k = min(k_cands, len(t_tgts))
            for _, tv in heapq.nlargest(k, zip(w_tgts, t_tgts)):
                t_cands.append(tv)
            sz = min(500, len(t_tgts)); step = max(1, len(t_tgts) // sz)
            t_s = sorted((t_tgts[i * step], w_tgts[i * step]) for i in range(sz))
            tw = sum(w for _, w in t_s); cw = 0.0
            for tv, wv in t_s:
                cw += wv
                if cw * 2 >= tw:
                    t_cands.append(tv)
                    break
            t_cands.append(t_s[len(t_s) // 2][0])
        best_pen = float('inf'); best_t = 0.0; best_c = 0.0; best_pens = None
        for t in set(t_cands):
            pen, pens, c = eval_tc(A, B, t)
            if pen < best_pen:
                best_pen = pen; best_t = t; best_c = c; best_pens = pens
        x_final = [x[i] + s[i] * best_t + best_c for i in range(N)]
        if cd_rounds > 0:
            if D > 0 and best_pens:
                d = min(D, M)
                top_idx = set(i for i, _ in heapq.nlargest(d, enumerate(best_pens), key=lambda e: e[1]))
                active = [i for i in range(M) if i not in top_idx]
            else:
                active = list(range(M))
            x_final = coord_descent(x_final, active, cd_rounds)
        return final_from_x(x_final)

    best_a = [1] * N; best_discards = []; best_total = float('inf')
    for order in all_orders:
        a, discards, total = spanning_tree_solve(order)
        if total < best_total:
            best_total = total; best_a, best_discards = a, discards
    return best_a, best_discards


def light_solve(N, M, D, edges):
    if M == 0:
        return [1] * N, []

    R, C, V, W, logV, nxt, head = edges
    d = min(D, M)

    def build_tree(descending=True):
        parent = list(range(N))
        rank = [0] * N

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def union(a, b):
            a = find(a); b = find(b)
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
        rng = range(1000, 0, -1) if descending else range(1, 1001)
        for w in rng:
            i = head[w]
            while i != -1:
                r = R[i]; c = C[i]
                if union(r, c):
                    is_tree[i] = 1
                    adj[r].append((c, i))
                    adj[c].append((r, i))
                i = nxt[i]
        return is_tree, adj

    def bfs(adj):
        x = [0.0] * N
        color = [-1] * N
        for start in range(N):
            if color[start] != -1:
                continue
            color[start] = 0
            q = deque([start])
            while q:
                u = q.popleft()
                xu = x[u]
                for v, ei in adj[u]:
                    if color[v] == -1:
                        x[v] = logV[ei] - xu
                        color[v] = color[u] ^ 1
                        q.append(v)
        return x, color

    def candidate_ts(x, s, is_tree):
        k = 7 if M <= 700000 else 4
        top_targets = []
        sample = []
        step = max(1, M // 700)
        for i in range(M):
            if not is_tree[i]:
                coeff = s[R[i]] + s[C[i]]
                if coeff != 0.0:
                    target = (logV[i] - x[R[i]] - x[C[i]]) / coeff
                    if len(top_targets) < k:
                        heapq.heappush(top_targets, (W[i], target))
                    elif W[i] > top_targets[0][0]:
                        heapq.heapreplace(top_targets, (W[i], target))
                    if i % step == 0:
                        sample.append((target, W[i]))
        ts = [0.0]
        ts.extend(t for _, t in top_targets)
        if sample:
            sample.sort()
            tw = sum(w for _, w in sample)
            cw = 0
            for t, w in sample:
                cw += w
                if cw * 2 >= tw:
                    ts.append(t)
                    break
            ts.append(sample[len(sample) // 2][0])
        seen = set(); out = []
        for t in ts:
            key = round(t, 12)
            if key not in seen:
                seen.add(key)
                out.append(t)
        return out

    def estimate_c(x, s, t):
        step = max(1, M // 600)
        vals = []
        for i in range(0, M, step):
            vals.append(logV[i] - x[R[i]] - x[C[i]] - (s[R[i]] + s[C[i]]) * t)
        vals.sort()
        return vals[len(vals) // 2] / 2.0 if vals else 0.0

    def score_solution(x, s, t):
        c = estimate_c(x, s, t)
        if d == 0:
            total = 0.0
            pens = None
            for i in range(M):
                y = x[R[i]] + x[C[i]] + (s[R[i]] + s[C[i]]) * t + 2.0 * c
                est = math.exp(min(40.0, max(-40.0, y)))
                total += W[i] * abs(est - V[i]) / V[i]
            return total, c, pens
        if d >= M:
            return 0.0, c, [0.0] * M
        total = 0.0
        largest = []
        pens = [] if M <= 250000 else None
        for i in range(M):
            y = x[R[i]] + x[C[i]] + (s[R[i]] + s[C[i]]) * t + 2.0 * c
            est = math.exp(min(40.0, max(-40.0, y)))
            pen = W[i] * abs(est - V[i]) / V[i]
            total += pen
            if pens is not None:
                pens.append(pen)
            if len(largest) < d:
                heapq.heappush(largest, pen)
            elif pen > largest[0]:
                heapq.heapreplace(largest, pen)
        return total - sum(largest), c, pens

    def coord_descent(a_log, active_edges, rounds):
        x = a_log[:]
        inc = [[] for _ in range(N)]
        for ei in active_edges:
            inc[R[ei]].append(ei)
            inc[C[ei]].append(ei)
        for _ in range(rounds):
            for node in range(N):
                cons = inc[node]
                if not cons:
                    continue
                tgts = []
                for ei in cons:
                    other = C[ei] if R[ei] == node else R[ei]
                    tgts.append((logV[ei] - x[other], W[ei]))
                tgts.sort()
                tw = sum(w for _, w in tgts)
                cw = 0.0
                for tv, wv in tgts:
                    cw += wv
                    if cw * 2 >= tw:
                        x[node] = tv
                        break
        return x

    def finalize(x):
        a = [0] * N
        for i in range(N):
            xi = x[i]
            if xi <= 0.0:
                a[i] = 1
            elif xi >= 20.7:
                a[i] = 10 ** 9
            else:
                a[i] = max(1, min(10 ** 9, round(math.exp(xi))))
        if d == 0:
            return a, []
        pens = []
        for i in range(M):
            pens.append((W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i], i + 1))
        pens.sort(reverse=True)
        return a, sorted(idx for _, idx in pens[:d])

    best_a, best_discards = [1] * N, []
    best_score = float('inf')
    for descending in (True, False):
        is_tree, adj = build_tree(descending)
        x, color = bfs(adj)
        s = [1.0 if c == 0 else -1.0 for c in color]
        best_t, best_c, best_pens = 0.0, 0.0, None
        local_best = float('inf')
        for t in candidate_ts(x, s, is_tree):
            sc, c, pens = score_solution(x, s, t)
            if sc < local_best:
                local_best, best_t, best_c, best_pens = sc, t, c, pens
        x_final = [x[i] + s[i] * best_t + best_c for i in range(N)]
        if M <= 120000:
            rounds = 4 if M <= 50000 else 2
            if d > 0 and best_pens is not None:
                top_idx = set(i for i, _ in heapq.nlargest(d, enumerate(best_pens), key=lambda e: e[1]))
                active = [i for i in range(M) if i not in top_idx]
            else:
                active = list(range(M))
            x_final = coord_descent(x_final, active, rounds)
        a, discards = finalize(x_final)
        total = 0.0
        discard_set = set(discards)
        for i in range(M):
            if i + 1 not in discard_set:
                total += W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
        if total < best_score:
            best_score = total
            best_a, best_discards = a, discards
    return best_a, best_discards


def main():
    it = iter(read_ints())
    N = next(it)
    M = next(it)
    D = next(it)

    if M <= SMALL_THRESHOLD:
        cells = []
        for _ in range(M):
            cells.append((next(it), next(it), next(it), next(it)))
        A, discards = strong_solve(N, M, D, cells)
    else:
        R = array('I')
        C = array('I')
        V = array('I')
        W = array('I')
        logV = array('d')
        nxt = array('i', [-1]) * M
        head = [-1] * 1001
        for idx in range(M):
            r = next(it) - 1
            c = next(it) - 1
            v = next(it)
            w = next(it)
            R.append(r); C.append(c); V.append(v); W.append(w); logV.append(math.log(v))
            nxt[idx] = head[w]
            head[w] = idx
        A, discards = light_solve(N, M, D, (R, C, V, W, logV, nxt, head))

    out = [' '.join(map(str, A))]
    if discards:
        out.append(str(len(discards)) + ' ' + ' '.join(map(str, discards)))
    else:
        out.append('0')
    sys.stdout.write('\n'.join(out))


if __name__ == '__main__':
    main()
