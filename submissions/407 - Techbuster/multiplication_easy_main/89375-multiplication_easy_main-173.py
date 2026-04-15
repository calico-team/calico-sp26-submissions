import sys
import math

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
    
    for i in range(M):
        r = int(input_data[ptr]); ptr += 1
        c = int(input_data[ptr]); ptr += 1
        v = int(input_data[ptr]); ptr += 1
        w = int(input_data[ptr]); ptr += 1
        constraints.append((r, c, v, w, i))
        adj[r].append((c, v, w, i))
        adj[c].append((r, v, w, i))

    a = [1.0] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            vs = sorted([edge[1] for edge in adj[i]])
            a[i] = max(1.0, math.sqrt(vs[len(vs) // 2]))

    def run_irls(iterations, current_adj):
        for _ in range(iterations):
            for i in range(1, N + 1):
                edges = current_adj[i]
                if not edges: 
                    continue
                num = 0.0
                den = 0.0
                ai = a[i]
                for j, v, w, idx in edges:
                    aj = a[j]
                    t = v / aj
                    diff = abs(ai - t)
                    d = diff if diff > 1e-4 else 1e-4
                    weight = w / d
                    num += weight
                    den += weight * aj / v
                if den > 0:
                    a[i] = max(1.0, num / den)

    run_irls(20, adj)
    
    active = [True] * M
    if D > 0:
        for _ in range(2):
            penalties = []
            for r, c, v, w, idx in constraints:
                p = w * abs(a[r] * a[c] - v) / v
                penalties.append((p, idx))
            penalties.sort(key=lambda x: x[0], reverse=True)
            
            active = [True] * M
            for i in range(min(D, M)):
                active[penalties[i][1]] = False
                
            new_adj = [[] for _ in range(N + 1)]
            for i in range(1, N + 1):
                for j, v, w, idx in adj[i]:
                    if active[idx]:
                        new_adj[i].append((j, v, w, idx))
                        
            run_irls(10, new_adj)
            
        penalties = []
        for r, c, v, w, idx in constraints:
            p = w * abs(a[r] * a[c] - v) / v
            penalties.append((p, idx))
        penalties.sort(key=lambda x: x[0], reverse=True)
        active = [True] * M
        for i in range(min(D, M)):
            active[penalties[i][1]] = False

    a_int = [0] * (N + 1)
    for i in range(1, N + 1):
        a_int[i] = max(1, min(10**9, int(round(a[i]))))
        
    polish_adj = [[] for _ in range(N + 1)]
    for i in range(1, N + 1):
        for j, v, w, idx in adj[i]:
            if active[idx]:
                polish_adj[i].append((j, v, w))
                
    for _ in range(3):
        changed = False
        for i in range(1, N + 1):
            if not polish_adj[i]:
                continue
            best_val = a_int[i]
            best_p = -1.0
            
            for cand in (a_int[i], a_int[i] - 1, a_int[i] + 1):
                if cand < 1 or cand > 10**9: 
                    continue
                p_sum = 0.0
                for j, v, w in polish_adj[i]:
                    p_sum += w * abs(cand * a_int[j] - v) / v
                
                if best_p < 0 or p_sum < best_p:
                    best_p = p_sum
                    best_val = cand
            
            if best_val != a_int[i]:
                a_int[i] = best_val
                changed = True
        if not changed:
            break
            
    final_penalties = []
    for r, c, v, w, idx in constraints:
        p = w * abs(a_int[r] * a_int[c] - v) / v
        final_penalties.append((p, idx + 1))
        
    final_penalties.sort(key=lambda x: x[0], reverse=True)
    discarded = [final_penalties[i][1] for i in range(min(D, M))]
    discarded.sort()
    
    print(*(a_int[1:]))
    print(len(discarded), *(discarded))

if __name__ == '__main__':
    solve()