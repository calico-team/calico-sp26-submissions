import sys
import random
import math

# ------------------------------------------------------------
# Helper: weighted median (L1 minimizer)
def weighted_median(pairs):
    """pairs: list of (value, weight) -> return weighted median (float)"""
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

# ------------------------------------------------------------
def solve():
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return
    it = iter(data)
    N = next(it)
    M = next(it)
    D = next(it)

    # quick win: discard everything
    if D >= M:
        # any valid a[] works, penalty = 0
        out_a = ' '.join('1' for _ in range(N))
        print(out_a)
        print(f"{M} " + ' '.join(str(i+1) for i in range(M)))
        return

    # read constraints
    R = [0] * M
    C = [0] * M
    V = [0] * M
    W = [0] * M
    adj = [[] for _ in range(N)]   # list of edge indices per node

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

    # --------------------------------------------------------
    # find connected components (undirected graph of nodes)
    comp_id = [-1] * N
    comp_nodes = []      # list of list of vertices
    comp_edges = []      # list of list of edge indices
    for i in range(N):
        if comp_id[i] != -1:
            continue
        # BFS
        queue = [i]
        comp_id[i] = len(comp_nodes)
        verts = []
        edges = []
        while queue:
            u = queue.pop()
            verts.append(u)
            for eidx in adj[u]:
                edges.append(eidx)
                v = R[eidx] if R[eidx] != u else C[eidx]
                if comp_id[v] == -1:
                    comp_id[v] = comp_id[i]
                    queue.append(v)
        # remove duplicate edges (set)
        edges = list(set(edges))
        comp_nodes.append(verts)
        comp_edges.append(edges)

    # --------------------------------------------------------
    # Evaluate a given integer array a[] (list of length N)
    # returns (total_penalty, list_of_discarded_indices_1based)
    def evaluate(a_int):
        penalties = []
        for idx in range(M):
            prod = a_int[R[idx]] * a_int[C[idx]]
            err = abs(prod - V[idx])
            pen = W[idx] * err / V[idx]   # float
            penalties.append((pen, idx))
        penalties.sort(reverse=True, key=lambda x: x[0])
        total = sum(p for p, _ in penalties[D:])
        discarded = [idx+1 for _, idx in penalties[:D]]
        return total, discarded

    # --------------------------------------------------------
    # Local search: try to improve integer a[] by small changes
    def local_search(a_int, cur_penalty, cur_discarded):
        # We'll not use the discarding during local search;
        # we just try to reduce the full penalty (including all constraints).
        # But we can use the fact that discarding is done after.
        # Simpler: try to reduce total penalty before discarding.
        # However the final penalty uses discarding, so we should use the same
        # evaluation function.
        improved = True
        passes = 0
        while improved and passes < 3:
            improved = False
            for node in range(N):
                best_val = a_int[node]
                best_penalty = cur_penalty   # but we need to recompute? costly.
                # Actually we need to evaluate after each change, which is O(M).
                # Instead compute delta only for edges incident to this node.
                # We'll compute current penalty contribution of all edges.
                # But since discarding changes, it's messy.
                # For simplicity, we skip local search for now.
                pass
        return a_int, cur_penalty, cur_discarded

    # --------------------------------------------------------
    # Core optimization for one component
    # Returns (a_int for nodes in this component, and the penalty of its edges)
    # We'll run this for each component separately, but discarding is global.
    # Actually we can optimize component independently because no cross edges.
    # We'll compute a_float per component, then later combine.
    # We'll also keep a list of all edges to compute global penalty.

    # We'll run several restarts and keep the best overall.
    best_overall_penalty = float('inf')
    best_a = None
    best_discarded = None

    # Number of restarts
    NUM_RESTARTS = 5
    for restart in range(NUM_RESTARTS):
        # random seed for reproducibility? not needed.
        # initialise a_float for all nodes
        a_float = [1.0] * N
        # Process each component separately
        for cid, nodes in enumerate(comp_nodes):
            if len(nodes) <= 1:
                # isolated node: keep 1.0
                continue
            edges = comp_edges[cid]
            # ---- initial guess from a random spanning tree ----
            # Build union-find to pick a tree
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

            # random shuffle edges to get a random tree
            shuffled = edges[:]
            random.shuffle(shuffled)
            tree_edges = []
            for eidx in shuffled:
                u, v = R[eidx], C[eidx]
                if union(u, v):
                    tree_edges.append(eidx)
                    if len(tree_edges) == len(nodes) - 1:
                        break
            # build tree adjacency
            tree_adj = [[] for _ in range(N)]
            for eidx in tree_edges:
                u, v = R[eidx], C[eidx]
                val = V[eidx]
                tree_adj[u].append((v, val))
                tree_adj[v].append((u, val))
            # DFS to get relative b (root = nodes[0])
            root = nodes[0]
            b = [0.0] * N
            b[root] = 1.0
            stack = [root]
            while stack:
                u = stack.pop()
                for v, val in tree_adj[u]:
                    if b[v] == 0.0:
                        b[v] = val / b[u]
                        stack.append(v)
            # compute optimal scaling for this component using all edges
            pairs = []
            for eidx in edges:
                u, v = R[eidx], C[eidx]
                B = b[u] * b[v]
                if B == 0.0:
                    continue
                target = V[eidx] / B
                weight = (W[eidx] / V[eidx]) * B
                pairs.append((target, weight))
            if pairs:
                t_opt = weighted_median(pairs)
                s = math.sqrt(t_opt)
            else:
                s = 1.0
            for v in nodes:
                a_float[v] = s * b[v]

        # ---- coordinate descent (L1 minimization) ----
        # We'll run several iterations over all nodes
        for _ in range(20):
            # random order of nodes
            order = list(range(N))
            random.shuffle(order)
            for node in order:
                # collect incident edges
                pairs = []
                for eidx in adj[node]:
                    j = R[eidx] if R[eidx] != node else C[eidx]
                    aj = a_float[j]
                    if aj == 0.0:
                        continue
                    target = V[eidx] / aj
                    weight = (W[eidx] / V[eidx]) * aj
                    pairs.append((target, weight))
                if pairs:
                    med = weighted_median(pairs)
                    a_float[node] = med
                # else keep current

        # ---- global scaling per component again ----
        for cid, nodes in enumerate(comp_nodes):
            if len(nodes) <= 1:
                continue
            edges = comp_edges[cid]
            pairs = []
            for eidx in edges:
                u, v = R[eidx], C[eidx]
                B = a_float[u] * a_float[v]
                if B == 0.0:
                    continue
                target = V[eidx] / B
                weight = (W[eidx] / V[eidx]) * B
                pairs.append((target, weight))
            if pairs:
                t_opt = weighted_median(pairs)
                s = math.sqrt(t_opt)
                for v in nodes:
                    a_float[v] *= s

        # ---- convert to integers ----
        a_int = [0] * N
        for i in range(N):
            val = a_float[i]
            if val < 1:
                val = 1.0
            if val > 1e9:
                val = 1e9
            a_int[i] = int(round(val))
            # clamp
            if a_int[i] < 1:
                a_int[i] = 1
            if a_int[i] > 1_000_000_000:
                a_int[i] = 1_000_000_000

        # ---- evaluate ----
        pen, disc = evaluate(a_int)
        if pen < best_overall_penalty - 1e-9:
            best_overall_penalty = pen
            best_a = a_int[:]
            best_discarded = disc

    # --------------------------------------------------------
    # Output
    out_lines = []
    out_lines.append(' '.join(str(x) for x in best_a))
    if D == 0:
        out_lines.append('0')
    else:
        out_lines.append(str(len(best_discarded)) + ' ' + ' '.join(str(x) for x in best_discarded))
    sys.stdout.write('\n'.join(out_lines))

# ------------------------------------------------------------
if __name__ == "__main__":
    solve()