import sys
import random
import math

def solve() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return
    it = iter(data)
    N = next(it)
    M = next(it)
    D = next(it)

    R = [0] * M
    C = [0] * M
    V = [0] * M
    W = [0] * M
    adj = [[] for _ in range(N)]

    for idx in range(M):
        r = next(it) - 1
        c = next(it) - 1
        v = next(it)
        w = next(it)
        R[idx] = r
        C[idx] = c
        V[idx] = v
        W[idx] = w
        adj[r].append(idx)
        adj[c].append(idx)

    # ---------- find connected components ----------
    comp_id = [-1] * N
    comps = []          # list of list of vertices
    comp_edges = []     # list of list of edge indices
    for i in range(N):
        if comp_id[i] != -1:
            continue
        # BFS
        queue = [i]
        comp_id[i] = len(comps)
        verts = []
        while queue:
            u = queue.pop()
            verts.append(u)
            for idx in adj[u]:
                v = R[idx] if R[idx] != u else C[idx]
                if comp_id[v] == -1:
                    comp_id[v] = comp_id[i]
                    queue.append(v)
        comps.append(verts)
        comp_edges.append([])

    # assign edges to components
    for idx in range(M):
        cid = comp_id[R[idx]]
        comp_edges[cid].append(idx)

    # ---------- helper: weighted median ----------
    def weighted_median(pairs):
        """pairs: list of (value, weight), returns median value"""
        if not pairs:
            return 0.0
        pairs.sort(key=lambda x: x[0])
        total = sum(w for _, w in pairs)
        half = total * 0.5
        cum = 0.0
        for val, w in pairs:
            cum += w
            if cum >= half:
                return val
        return pairs[-1][0]

    # ---------- evaluate a candidate integer array ----------
    def evaluate(a_int):
        penalties = []
        for idx in range(M):
            prod = a_int[R[idx]] * a_int[C[idx]]
            err = abs(prod - V[idx])
            pen = W[idx] * err / V[idx]   # float
            penalties.append((pen, idx))
        penalties.sort(reverse=True, key=lambda x: x[0])
        total = sum(p for p, _ in penalties[D:])
        discarded = [idx + 1 for _, idx in penalties[:D]]   # 1‑based
        return total, discarded

    best_penalty = float('inf')
    best_a = None
    best_discarded = None

    # ---------- random spanning trees ----------
    NUM_TREE_TRIALS = 10
    for _ in range(NUM_TREE_TRIALS):
        a_int = [1] * N   # temporary
        # process each component independently
        for cid, verts in enumerate(comps):
            k = len(verts)
            if k <= 1:
                # isolated vertex: keep value 1
                continue
            edges = comp_edges[cid]
            # build a random spanning tree using union-find
            parent = list(range(N))
            def find(x):
                while parent[x] != x:
                    parent[x] = parent[parent[x]]
                    x = parent[x]
                return x
            def union(x, y):
                rx, ry = find(x), find(y)
                if rx == ry:
                    return False
                parent[ry] = rx
                return True

            shuffled = edges[:]
            random.shuffle(shuffled)
            tree_edges = []
            for idx in shuffled:
                u, v = R[idx], C[idx]
                if union(u, v):
                    tree_edges.append(idx)
                    if len(tree_edges) == k - 1:
                        break
            # build tree adjacency
            tree_adj = [[] for _ in range(N)]
            for idx in tree_edges:
                u, v = R[idx], C[idx]
                val = V[idx]
                tree_adj[u].append((v, val))
                tree_adj[v].append((u, val))
            # DFS to get relative values b (root = first vertex)
            root = verts[0]
            b = [0.0] * N
            b[root] = 1.0
            stack = [root]
            while stack:
                u = stack.pop()
                for v, val in tree_adj[u]:
                    if b[v] == 0.0:
                        b[v] = val / b[u]
                        stack.append(v)
            # compute optimal scaling for this component
            pairs = []
            for idx in edges:
                u = b[R[idx]] * b[C[idx]]
                if u == 0.0:
                    continue
                val = V[idx] / u
                weight = (W[idx] / V[idx]) * u
                pairs.append((val, weight))
            if pairs:
                t_opt = weighted_median(pairs)
                s = math.sqrt(t_opt)
            else:
                s = 1.0
            # round to integers
            for v in verts:
                av = s * b[v]
                a_int[v] = max(1, min(1_000_000_000, int(round(av))))
        # evaluate this candidate
        pen, disc = evaluate(a_int)
        if pen < best_penalty - 1e-9:
            best_penalty = pen
            best_a = a_int[:]
            best_discarded = disc

    # ---------- iterative median (coordinate descent) ----------
    NUM_RESTARTS = 3
    NUM_ITER = 5
    for restart in range(NUM_RESTARTS):
        # random initial values in [0.5, 2.0]
        a_float = [random.uniform(0.5, 2.0) for _ in range(N)]
        for _ in range(NUM_ITER):
            order = list(range(N))
            random.shuffle(order)
            for i in order:
                pairs = []
                for idx in adj[i]:
                    j = R[idx] if R[idx] != i else C[idx]
                    v = V[idx]
                    w = W[idx]
                    aj = a_float[j]
                    cand = v / aj
                    weight = (w / v) * aj
                    pairs.append((cand, weight))
                if not pairs:
                    continue
                # weighted median
                med = weighted_median(pairs)
                a_float[i] = med
        # now compute optimal scaling per component
        b = a_float
        a_int = [1] * N
        for cid, verts in enumerate(comps):
            if len(verts) <= 1:
                continue
            edges = comp_edges[cid]
            pairs = []
            for idx in edges:
                u = b[R[idx]] * b[C[idx]]
                if u == 0.0:
                    continue
                val = V[idx] / u
                weight = (W[idx] / V[idx]) * u
                pairs.append((val, weight))
            if pairs:
                t_opt = weighted_median(pairs)
                s = math.sqrt(t_opt)
            else:
                s = 1.0
            for v in verts:
                av = s * b[v]
                a_int[v] = max(1, min(1_000_000_000, int(round(av))))
        pen, disc = evaluate(a_int)
        if pen < best_penalty - 1e-9:
            best_penalty = pen
            best_a = a_int[:]
            best_discarded = disc

    # ---------- output ----------
    out_lines = []
    out_lines.append(' '.join(str(x) for x in best_a))
    if D == 0:
        out_lines.append('0')
    else:
        out_lines.append(str(len(best_discarded)) + ' ' + ' '.join(str(x) for x in best_discarded))
    sys.stdout.write('\n'.join(out_lines))

if __name__ == "__main__":
    solve()