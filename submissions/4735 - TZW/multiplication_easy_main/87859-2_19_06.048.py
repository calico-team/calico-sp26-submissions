import sys
import math
import random

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    N = int(input_data[ptr]); ptr += 1
    M = int(input_data[ptr]); ptr += 1
    D = int(input_data[ptr]); ptr += 1
    
    adj = [[] for _ in range(N + 1)]
    constraints = []
    
    for i in range(1, M + 1):
        u = int(input_data[ptr]); ptr += 1
        v = int(input_data[ptr]); ptr += 1
        val = int(input_data[ptr]); ptr += 1
        w = int(input_data[ptr]); ptr += 1
        constraints.append((u, v, val, w, i))
        adj[u].append((v, val, w))
        adj[v].append((u, val, w))

    log_a = [math.log(math.sqrt(1e5))] * (N + 1)

    visited = [False] * (N + 1)
    for i in range(1, N + 1):
        if not visited[i]:
            visited[i] = True
            queue = [i]
            while queue:
                u = queue.pop(0)
                for v, val, w in adj[u]:
                    if not visited[v]:
                        log_a[v] = math.log(val) - log_a[u]
                        visited[v] = True
                        queue.append(v)

    iterations = 40
    for _ in range(iterations):
        for u in range(1, N + 1):
            if not adj[u]: continue

            targets = []
            for v, val, w in adj[u]:
                targets.append((math.log(val) - log_a[v], w))
            
            targets.sort()
            total_w = sum(w for _, w in targets)
            acc_w = 0
            best_log = targets[0][0]
            for val_target, w in targets:
                acc_w += w
                if acc_w >= total_w / 2:
                    best_log = val_target
                    break
            log_a[u] = best_log

    a = [max(1, min(10**9, int(round(math.exp(x))))) for x in log_a[1:]]
    
    errors = []
    for i in range(M):
        u, v, val, w, idx = constraints[i]
        calc = a[u-1] * a[v-1]
        penalty = w * abs(calc - val) / val
        errors.append((penalty, idx))
    
    errors.sort(key=lambda x: x[0], reverse=True)
    
    d = min(D, M)
    discarded_indices = [errors[i][1] for i in range(d)]
    
    print(*(a))
    print(d, *(discarded_indices))

if __name__ == "__main__":
    solve()
