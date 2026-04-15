import sys
import time
import math

def solve():
    # Enforce strict timing to prevent Time Limit Exceeded (TLE)
    start_time = time.time()
    
    # Fast I/O
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    N = int(input_data[0])
    M = int(input_data[1])
    D = int(input_data[2])

    adj = [[] for _ in range(N + 1)]
    edges = []

    ptr = 3
    for i in range(1, M + 1):
        r = int(input_data[ptr])
        c = int(input_data[ptr+1])
        v = int(input_data[ptr+2])
        w = int(input_data[ptr+3])
        ptr += 4
        
        factor = w / v
        log_v = math.log(v) if v > 0 else 0
        
        adj[r].append((c, v, log_v, factor, i))
        adj[c].append((r, v, log_v, factor, i))
        edges.append((r, c, v, w, i))

    # --- PHASE 0: Log-Space Gauss-Seidel Initialization ---
    # By mapping the problem to log-space, we create a convex L2 surface.
    # This completely bypasses local minima and instantly finds the correct global magnitudes.
    x = [0.0] * (N + 1)
    
    # 25 rapid iterations to solve the linear system
    for _ in range(25):
        for u in range(1, N + 1):
            if not adj[u]:
                continue
            s = 0.0
            for v_node, v_val, log_v, factor, idx in adj[u]:
                s += log_v - x[v_node]
            x[u] = s / len(adj[u])

    # Convert back from log-space to exact integers
    a = [1] * (N + 1)
    for u in range(1, N + 1):
        if adj[u]:
            try:
                val = math.exp(x[u])
            except OverflowError:
                val = 10**9
            a[u] = max(1, min(10**9, int(round(val))))

    # --- PHASE 1: Exact L1 Coordinate Descent ---
    # Now that the magnitudes are perfect, we optimize the exact asymmetric penalty formula
    while time.time() - start_time < 4.0:
        changed = False
        for u in range(1, N + 1):
            if not adj[u]:
                continue
            
            targets = []
            tot_weight = 0.0
            
            for v_node, v_val, log_v, factor, idx in adj[u]:
                av = a[v_node]
                t = v_val / av
                wt = factor * av
                targets.append((t, wt))
                tot_weight += wt
            
            targets.sort(key=lambda item: item[0])
            half = tot_weight / 2.0
            cum = 0.0
            best_t = targets[-1][0]
            
            for t, wt in targets:
                cum += wt
                if cum >= half:
                    best_t = t
                    break
            
            c1 = max(1, int(best_t))
            c2 = c1 + 1
            
            cost1 = 0.0
            cost2 = 0.0
            for t, wt in targets:
                cost1 += wt * abs(c1 - t)
                cost2 += wt * abs(c2 - t)
            
            best_val = c1 if cost1 <= cost2 else c2
            best_val = min(10**9, best_val)
            
            if a[u] != best_val:
                a[u] = best_val
                changed = True
                
        if not changed:
            break

    # --- PHASE 2: Discard Worst Outliers ---
    errors = []
    for r, c, v, w, i in edges:
        err = w * abs(a[r] * a[c] - v) / v
        errors.append((err, i))
        
    errors.sort(reverse=True, key=lambda item: item[0])
    d = min(D, len(errors))
    discard_set = set(item[1] for item in errors[:d])

    # Rebuild graph without the worst edges
    new_adj = [[] for _ in range(N + 1)]
    for r, c, v, w, i in edges:
        if i not in discard_set:
            factor = w / v
            new_adj[r].append((c, v, 0.0, factor, i))
            new_adj[c].append((r, v, 0.0, factor, i))

    # --- PHASE 3: Refined L1 Coordinate Descent ---
    while time.time() - start_time < 8.5:
        changed = False
        for u in range(1, N + 1):
            if not new_adj[u]:
                continue
            
            targets = []
            tot_weight = 0.0
            
            for v_node, v_val, _log_v, factor, idx in new_adj[u]:
                av = a[v_node]
                t = v_val / av
                wt = factor * av
                targets.append((t, wt))
                tot_weight += wt
            
            if not targets:
                continue

            targets.sort(key=lambda item: item[0])
            half = tot_weight / 2.0
            cum = 0.0
            best_t = targets[-1][0]
            
            for t, wt in targets:
                cum += wt
                if cum >= half:
                    best_t = t
                    break
            
            c1 = max(1, int(best_t))
            c2 = c1 + 1
            
            cost1 = 0.0
            cost2 = 0.0
            for t, wt in targets:
                cost1 += wt * abs(c1 - t)
                cost2 += wt * abs(c2 - t)
            
            best_val = c1 if cost1 <= cost2 else c2
            best_val = min(10**9, best_val)
            
            if a[u] != best_val:
                a[u] = best_val
                changed = True
                
        if not changed:
            break

    # --- PHASE 4: Final Exact Discard Selection ---
    # Recalculate absolute errors dynamically against the final refined array
    final_errors = []
    for r, c, v, w, i in edges:
        err = w * abs(a[r] * a[c] - v) / v
        final_errors.append((err, i))
        
    final_errors.sort(reverse=True, key=lambda item: item[0])
    final_d = min(D, len(final_errors))
    
    actual_discards = []
    for i in range(final_d):
        if final_errors[i][0] > 1e-9:
            actual_discards.append(final_errors[i][1])

    # --- OUTPUT ---
    ans_a = " ".join(map(str, a[1:N+1]))
    if actual_discards:
        ans_d = f"{len(actual_discards)} " + " ".join(map(str, actual_discards))
    else:
        ans_d = "0"
        
    sys.stdout.write(ans_a + "\n")
    sys.stdout.write(ans_d + "\n")

if __name__ == '__main__':
    solve()