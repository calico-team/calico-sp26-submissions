import sys
import math
from collections import defaultdict
import heapq

def solve():
    data = sys.stdin.read().split()
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

    def spanning_tree_assign(active_set, root_val):
        adj = defaultdict(list)
        for i in active_set:
            lv = math.log(V[i])
            adj[R[i]].append((-W[i], C[i], lv))
            adj[C[i]].append((-W[i], R[i], lv))

        x = [None] * N
        x[0] = math.log(root_val)
        visited = [False] * N
        visited[0] = True
        heap = []
        for neg_w, nb, lv in adj[0]:
            heapq.heappush(heap, (neg_w, nb, lv, 0))

        while heap:
            neg_w, node, lv, from_node = heapq.heappop(heap)
            if visited[node]:
                continue
            visited[node] = True
            x[node] = lv - x[from_node]
            for neg_w2, nb2, lv2 in adj[node]:
                if not visited[nb2]:
                    heapq.heappush(heap, (neg_w2, nb2, lv2, node))

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

    all_idx = list(range(M))

    best_a = None
    best_total = float('inf')
    best_discard = []

    strategies = []
    strategies.append(sorted(all_idx, key=lambda i: -W[i])[:D])
    strategies.append(sorted(all_idx, key=lambda i: -V[i])[:D])
    strategies.append([])

    for initial_discard in strategies:
        discard_set = set(initial_discard)
        active_set = [i for i in all_idx if i not in discard_set]

        for root_val in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]:
            x = spanning_tree_assign(active_set, root_val)
            a = x_to_a(x)

            all_pen = []
            for i in range(M):
                prod = a[R[i]] * a[C[i]]
                pen = W[i] * abs(prod - V[i]) / V[i]
                all_pen.append((pen, i))

            all_pen_sorted = sorted(all_pen, key=lambda x: -x[0])
            final_discard = [all_pen_sorted[i][1] for i in range(min(D, M))]
            final_discard_set = set(final_discard)
            active_total = sum(p for p, i in all_pen if i not in final_discard_set)

            if active_total < best_total:
                best_total = active_total
                best_a = a[:]
                best_discard = [i+1 for i in final_discard]

    print(*best_a)
    print(len(best_discard), *best_discard)

solve()
