import math
from collections import defaultdict
import heapq

def solve():
    N, M, D = map(int, input().split())

    constraints = []
    for i in range(M):
        r, c, v, w = map(int, input().split())
        constraints.append((r-1, c-1, v, w))

    # Sort constraints by weight descending
    # Greedily pick spanning tree using highest weight edges
    # Then try multiple root values

    def build_spanning_tree(constraints_active):
        # Returns adjacency for spanning tree: adj[i] = list of (j, log_v)
        adj = defaultdict(list)
        for r, c, v, w in constraints_active:
            lv = math.log(v)
            adj[r].append((c, lv, w))
            adj[c].append((r, lv, w))
        return adj

    def assign_from_root(root_val, root, adj, N):
        x = [None] * N
        x[root] = math.log(root_val)
        visited = [False] * N
        visited[root] = True
        # BFS
        queue = [root]
        while queue:
            node = queue.pop(0)
            for nb, lv, w in adj[node]:
                if not visited[nb]:
                    visited[nb] = True
                    x[nb] = lv - x[node]
                    queue.append(nb)
        for i in range(N):
            if x[i] is None:
                x[i] = 0.0
        return x

    def x_to_a(x):
        a = []
        for xi in x:
            val = round(math.exp(xi))
            val = max(1, min(10**9, val))
            a.append(val)
        return a

    def total_pen(a, active_indices, constraints):
        total = 0.0
        for idx in active_indices:
            r, c, v, w = constraints[idx]
            prod = a[r] * a[c]
            total += w * abs(prod - v) / v
        return total

    def get_pen_list(a, constraints):
        pen_list = []
        for i, (r, c, v, w) in enumerate(constraints):
            prod = a[r] * a[c]
            pen = w * abs(prod - v) / v
            pen_list.append((pen, i+1))
        return pen_list

    # Step 1: find best D constraints to discard
    # Try: discard by highest W*V inconsistency
    # Use all constraints to build spanning tree, find worst, discard, redo

    best_a = None
    best_pen = float('inf')
    best_discard = []

    # Try discarding each possible subset greedily
    # For small D, try removing top D by weight first
    for trial in range(3):
        if trial == 0:
            # discard nothing first
            active_idx = list(range(M))
        elif trial == 1:
            # discard top D by weight
            by_w = sorted(range(M), key=lambda i: -constraints[i][3])
            active_idx = [i for i in range(M) if i not in set(by_w[:D])]
        else:
            # discard top D by value (largest V = most likely outlier)
            by_v = sorted(range(M), key=lambda i: -constraints[i][2])
            active_idx = [i for i in range(M) if i not in set(by_v[:D])]

        active_cons = [constraints[i] for i in active_idx]
        if not active_cons:
            continue

        adj = build_spanning_tree(active_cons)

        # Try a few root values
        for root in range(min(N, 3)):
            for root_val in [1, 2, 3, 4, 5, 6, 7, 8, 10]:
                x = assign_from_root(root_val, root, adj, N)
                a = x_to_a(x)
                pen_list = get_pen_list(a, constraints)
                pen_sorted = sorted(pen_list, key=lambda x: -x[0])
                discard = [pen_sorted[i][1] for i in range(min(D, M))]
                discard_set = set(discard)
                active_pen = sum(p for p, idx in pen_list if idx not in discard_set)
                if active_pen < best_pen:
                    best_pen = active_pen
                    best_a = a[:]
                    best_discard = discard

        # Also do coordinate descent from spanning tree solution
        adj2 = build_spanning_tree(active_cons)
        x = assign_from_root(1, 0, adj2, N)

        node_cons = defaultdict(list)
        for r, c, v, w in active_cons:
            lv = math.log(v)
            node_cons[r].append((c, lv, w))
            node_cons[c].append((r, lv, w))

        for _ in range(500):
            max_change = 0.0
            for i in range(N):
                if not node_cons[i]:
                    continue
                total_w = 0.0
                total_val = 0.0
                for j, lv, w in node_cons[i]:
                    total_val += w * (lv - x[j])
                    total_w += w
                if total_w > 0:
                    new_xi = total_val / total_w
                    max_change = max(max_change, abs(new_xi - x[i]))
                    x[i] = new_xi
            if max_change < 1e-15:
                break

        a = x_to_a(x)
        pen_list = get_pen_list(a, constraints)
        pen_sorted = sorted(pen_list, key=lambda x: -x[0])
        discard = [pen_sorted[i][1] for i in range(min(D, M))]
        discard_set = set(discard)
        active_pen = sum(p for p, idx in pen_list if idx not in discard_set)
        if active_pen < best_pen:
            best_pen = active_pen
            best_a = a[:]
            best_discard = discard

    print(*best_a)
    print(len(best_discard), *best_discard)

solve()