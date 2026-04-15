import sys
import math
from collections import defaultdict
import heapq

def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(data[idx]); idx+=1
    M = int(data[idx]); idx+=1
    D = int(data[idx]); idx+=1

    R = [0]*M
    C = [0]*M
    V = [0.0]*M
    W = [0.0]*M

    for i in range(M):
        R[i] = int(data[idx])-1; idx+=1
        C[i] = int(data[idx])-1; idx+=1
        V[i] = float(data[idx]);  idx+=1
        W[i] = float(data[idx]);  idx+=1

    # Build adjacency: for each node, store (weight, neighbor, log_v, constraint_idx)
    adj = defaultdict(list)
    for i in range(M):
        lv = math.log(V[i])
        adj[R[i]].append((-W[i], C[i], lv, i))
        adj[C[i]].append((-W[i], R[i], lv, i))

    # Prim's: assign x[i] = log(a[i]) via max-weight spanning tree
    def spanning_tree_assign(root_val):
        x = [None] * N
        x[0] = math.log(root_val)
        visited = [False] * N
        visited[0] = True

        # heap: (neg_weight, neighbor, log_v, from_node)
        heap = []
        for neg_w, nb, lv, ci in adj[0]:
            heapq.heappush(heap, (neg_w, nb, lv, 0))

        while heap:
            neg_w, node, lv, from_node = heapq.heappop(heap)
            if visited[node]:
                continue
            visited[node] = True
            # x[from_node] + x[node] = lv
            x[node] = lv - x[from_node]
            for neg_w2, nb2, lv2, ci2 in adj[node]:
                if not visited[nb2]:
                    heapq.heappush(heap, (neg_w2, nb2, lv2, node))

        # unvisited nodes
        for i in range(N):
            if x[i] is None:
                x[i] = 0.0
        return x

    def x_to_a(x):
        a = []
        for xi in x:
            val = int(round(math.exp(xi)))
            val = max(1, min(10**9, val))
            a.append(val)
        return a

    def get_penalties(a):
        pen = [0.0] * M
        for i in range(M):
            prod = a[R[i]] * a[C[i]]
            pen[i] = W[i] * abs(prod - V[i]) / V[i]
        return pen

    best_a = None
    best_total = float('inf')
    best_discard = []

    # Try a few root values
    for root_val in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]:
        x = spanning_tree_assign(root_val)
        a = x_to_a(x)
        pen = get_penalties(a)

        # pick top D to discard
        order = sorted(range(M), key=lambda i: -pen[i])
        discard_set = set(order[:D])
        active_total = sum(pen[i] for i in range(M) if i not in discard_set)

        if active_total < best_total:
            best_total = active_total
            best_a = a[:]
            best_discard = [order[i]+1 for i in range(min(D, M))]

    print(*best_a)
    print(len(best_discard), *best_discard)

solve()
