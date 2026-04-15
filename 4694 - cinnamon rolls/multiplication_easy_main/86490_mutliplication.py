import numpy as np
from collections import deque


def solve(N, M, D, cells):
    if M == 0:
        return [1]*N, []

    R = np.array([c[0]-1 for c in cells], dtype=np.int32)
    C = np.array([c[1]-1 for c in cells], dtype=np.int32)
    V = np.array([c[2] for c in cells], dtype=np.float64)
    W = np.array([c[3] for c in cells], dtype=np.float64)
    logV = np.log(V)

    def build_spanning_tree(edge_order):
        parent = list(range(N)); rank = [0]*N
        def find(x):
            while parent[x] != x: parent[x] = parent[parent[x]]; x = parent[x]
            return x
        def union(a, b):
            a, b = find(a), find(b)
            if a == b: return False
            if rank[a] < rank[b]: a, b = b, a
            parent[b] = a
            if rank[a] == rank[b]: rank[a] += 1
            return True
        tree = []; nontree = []
        for i in edge_order:
            (tree if union(int(R[i]), int(C[i])) else nontree).append(i)
        return tree, nontree

    def bfs_assign(tree_edges):
        adj = [[] for _ in range(N)]
        for i in tree_edges:
            ri, ci = int(R[i]), int(C[i])
            adj[ri].append((ci, i)); adj[ci].append((ri, i))
        x = np.full(N, np.nan); color = np.full(N, -1, dtype=int)
        for start in range(N):
            if np.isnan(x[start]):
                x[start] = 0.0; color[start] = 0; q = deque([start])
                while q:
                    node = q.popleft()
                    for nb, ei in adj[node]:
                        if np.isnan(x[nb]):
                            x[nb] = float(logV[ei]) - x[node]
                            color[nb] = 1 - color[node]; q.append(nb)
        return np.where(np.isnan(x), 0.0, x), np.where(color < 0, 0, color)

    def eval_t(x, s, t):
        prod = np.exp(np.clip(x[R] + s[R]*t + x[C] + s[C]*t, -40, 40))
        pen = W * np.abs(prod - V) / V
        if D > 0:
            top = np.argpartition(pen, -D)[-D:]
            return float(np.sum(pen)) - float(np.sum(pen[top]))
        return float(np.sum(pen))

    def final_output(x, s, t):
        x_f = x + s * t
        a = np.clip(np.round(np.exp(np.clip(x_f, 0, 20.7))), 1, 10**9).astype(np.int64)
        prod = (a[R] * a[C]).astype(np.float64)
        pen = W * np.abs(prod - V) / V
        if D > 0:
            top = np.argpartition(pen, -D)[-D:]
            return a.tolist(), sorted((top+1).tolist()), float(np.sum(pen)) - float(np.sum(pen[top]))
        return a.tolist(), [], float(np.sum(pen))

    def spanning_tree_solve(edge_order):
        tree, nontree = build_spanning_tree(edge_order)
        x, color = bfs_assign(tree)
        s = np.where(color == 0, 1.0, -1.0)
        t_cands = {0.0}
        if nontree:
            nt = np.array(nontree)
            coeff = s[R[nt]] + s[C[nt]]
            nt_v = nt[coeff != 0]; coeff_v = coeff[coeff != 0]
            if len(nt_v) > 0:
                t_tgts = (logV[nt_v] - x[R[nt_v]] - x[C[nt_v]]) / coeff_v
                w_tgts = W[nt_v]
                si = np.argsort(t_tgts)
                cw = np.cumsum(w_tgts[si])
                mi = np.searchsorted(cw, cw[-1]/2)
                if mi < len(t_tgts): t_cands.add(float(t_tgts[si[mi]]))
                t_cands.add(float(np.median(t_tgts)))
                n = min(30, len(t_tgts))
                for i in np.argpartition(-w_tgts, max(n-1, 0))[:n]: t_cands.add(float(t_tgts[i]))
                for i in si[np.linspace(0, len(si)-1, min(30, len(si)), dtype=int)]: t_cands.add(float(t_tgts[i]))
        best_t = min(t_cands, key=lambda t: eval_t(x, s, t))
        return final_output(x, s, best_t)

    best_a = [1]*N; best_discards = []; best_total = float('inf')
    for order in [np.argsort(W).tolist(), np.argsort(-W).tolist()]:
        a, discards, total = spanning_tree_solve(order)
        if total < best_total:
            best_total = total; best_a, best_discards = a, discards
    return best_a, best_discards


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