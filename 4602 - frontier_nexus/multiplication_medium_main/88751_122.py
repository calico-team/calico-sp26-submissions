import sys
import time
import math

def solve():
    # Start timer to safely bound our heuristic against the 10-second limit
    start_time = time.time()
    
    # Fast I/O reading for massive test cases
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
        
        # Precalculate the division factor (w / v) to save time in the inner loop
        # We minimize sum( (W_i / V_i) * |a_r * a_c - V_i| )
        factor = w / v
        adj[r].append((c, v, factor, i))
        adj[c].append((r, v, factor, i))
        edges.append((r, c, v, w, i))

    # Smart Initialization: square root of the median of connected edges
    a = [1] * (N + 1)
    for u in range(1, N + 1):
        if adj[u]:
            vals = [e[1] for e in adj[u]]
            vals.sort()
            med_v = vals[len(vals) // 2]
            a[u] = max(1, int(math.sqrt(med_v)))

    # Phase 1: Global Coordinate Descent
    # Run for up to 4.5 seconds to find the best general shape
    while time.time() - start_time < 4.5:
        changed = False
        for u in range(1, N + 1):
            if not adj[u]:
                continue
            
            targets = []
            tot_weight = 0.0
            
            for v_node, v_val, factor, idx in adj[u]:
                av = a[v_node]
                t = v_val / av
                wt = factor * av
                targets.append((t, wt))
                tot_weight += wt
            
            targets.sort(key=lambda x: x[0])
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
            
            cost1 = sum(wt * abs(c1 - t) for t, wt in targets)
            cost2 = sum(wt * abs(c2 - t) for t, wt in targets)
            
            best_val = c1 if cost1 <= cost2 else c2
            best_val = min(10**9, best_val)
            
            if a[u] != best_val:
                a[u] = best_val
                changed = True
                
        if not changed:
            break

    # Identify initial outliers to ignore during Phase 2
    errors = []
    for r, c, v, w, i in edges:
        err = w * abs(a[r] * a[c] - v) / v
        errors.append((err, i))
        
    errors.sort(reverse=True, key=lambda x: x[0])
    d = min(D, len(errors))
    discard_set = set(e[1] for e in errors[:d])

    # Rebuild adjacency without the worst constraints
    new_adj = [[] for _ in range(N + 1)]
    for r, c, v, w, i in edges:
        if i not in discard_set:
            factor = w / v
            new_adj[r].append((c, v, factor, i))
            new_adj[c].append((r, v, factor, i))

    # Phase 2: Refinement 
    # Fine-tune the array heavily against the core constraints until 9.0 seconds
    while time.time() - start_time < 9.0:
        changed = False
        for u in range(1, N + 1):
            if not new_adj[u]:
                continue
            
            targets = []
            tot_weight = 0.0
            
            for v_node, v_val, factor, idx in new_adj[u]:
                av = a[v_node]
                t = v_val / av
                wt = factor * av
                targets.append((t, wt))
                tot_weight += wt
            
            if not targets:
                continue

            targets.sort(key=lambda x: x[0])
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
            
            cost1 = sum(wt * abs(c1 - t) for t, wt in targets)
            cost2 = sum(wt * abs(c2 - t) for t, wt in targets)
            
            best_val = c1 if cost1 <= cost2 else c2
            best_val = min(10**9, best_val)
            
            if a[u] != best_val:
                a[u] = best_val
                changed = True
                
        if not changed:
            break

    # Phase 3: Final Exact Discard Selection
    # Whatever the array is now, mathematically pick the exact D worst edges to throw away
    final_errors = []
    for r, c, v, w, i in edges:
        err = w * abs(a[r] * a[c] - v) / v
        final_errors.append((err, i))
        
    final_errors.sort(reverse=True, key=lambda x: x[0])
    final_d = min(D, len(final_errors))
    
    actual_discards = []
    for i in range(final_d):
        if final_errors[i][0] > 1e-9: # Only discard if it actually causes a penalty
            actual_discards.append(final_errors[i][1])

    # Format Output
    ans_a = " ".join(map(str, a[1:N+1]))
    if actual_discards:
        ans_d = f"{len(actual_discards)} " + " ".join(map(str, actual_discards))
    else:
        ans_d = "0"
        
    sys.stdout.write(ans_a + "\n")
    sys.stdout.write(ans_d + "\n")

if __name__ == '__main__':
    solve()