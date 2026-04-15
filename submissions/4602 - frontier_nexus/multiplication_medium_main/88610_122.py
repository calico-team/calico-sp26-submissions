import sys
import time
import math

def solve():
    # Keep track of time to ensure we never TLE (Time Limit Exceeded)
    start_time = time.time()
    
    # Fast I/O reading for massive inputs
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
        
        adj[r].append((c, v, w, i))
        adj[c].append((r, v, w, i))
        edges.append((r, c, v, w, i))

    # Smart Initialization: Start values near the square root of their median edges
    # This prevents the gradient descent from getting stuck in bad local minimums
    a = [1] * (N + 1)
    for u in range(1, N + 1):
        if adj[u]:
            vals = [edge[1] for edge in adj[u]]
            vals.sort()
            med_v = vals[len(vals) // 2]
            a[u] = max(1, int(math.sqrt(med_v)))

    # Phase 1: Coordinate Descent (Weighted Median Optimization)
    # Give it ~3.5 seconds to build the general shape of the array
    while time.time() - start_time < 3.5:
        changed = False
        for u in range(1, N + 1):
            if not adj[u]:
                continue
            
            targets = []
            tot_c = 0.0
            
            for v, V_i, W_i, idx in adj[u]:
                av = a[v]
                t = V_i / av
                c = W_i * av / V_i
                targets.append((t, c))
                tot_c += c

            targets.sort(key=lambda x: x[0])
            
            half = tot_c / 2.0
            cum = 0.0
            best_t = targets[-1][0]
            
            for t, c in targets:
                cum += c
                if cum >= half:
                    best_t = t
                    break

            # Test both floor and ceil explicitly to guarantee optimal integer choice
            c1 = max(1, int(best_t))
            c2 = c1 + 1
            
            cost1 = sum(c * abs(c1 - t) for t, c in targets)
            cost2 = sum(c * abs(c2 - t) for t, c in targets)
            
            new_val = c1 if cost1 <= cost2 else c2
            new_val = min(10**9, new_val) # Clamp to constraints

            if a[u] != new_val:
                a[u] = new_val
                changed = True

        if not changed:
            break

    # Phase 2: Error Evaluation and Discard Selection
    errors = []
    for r, c, v, w, i in edges:
        err = w * abs(a[r] * a[c] - v) / v
        errors.append((err, i))

    # Sort descending to find the worst constraints
    errors.sort(key=lambda x: x[0], reverse=True)
    d = min(D, len(errors))
    
    discard_set = set()
    discard_list = []
    for j in range(d):
        # ONLY discard if the edge is actually producing an error
        if errors[j][0] > 1e-11:
            discard_set.add(errors[j][1])
            discard_list.append(errors[j][1])
            
    d = len(discard_list)

    # Phase 3: Refinement Descent
    # Rebuild the adjacency graph without the discarded outlier edges
    if d > 0:
        adj = [[] for _ in range(N + 1)]
        for r, c, v, w, i in edges:
            if i not in discard_set:
                adj[r].append((c, v, w, i))
                adj[c].append((r, v, w, i))

        # Run until roughly 8.5 seconds to guarantee termination before 10.0s Limit
        while time.time() - start_time < 8.5:
            changed = False
            for u in range(1, N + 1):
                if not adj[u]:
                    continue
                
                targets = []
                tot_c = 0.0
                
                for v, V_i, W_i, idx in adj[u]:
                    av = a[v]
                    t = V_i / av
                    c = W_i * av / V_i
                    targets.append((t, c))
                    tot_c += c

                if not targets:
                    continue

                targets.sort(key=lambda x: x[0])
                
                half = tot_c / 2.0
                cum = 0.0
                best_t = targets[-1][0]
                
                for t, c in targets:
                    cum += c
                    if cum >= half:
                        best_t = t
                        break

                c1 = max(1, int(best_t))
                c2 = c1 + 1
                
                cost1 = sum(c * abs(c1 - t) for t, c in targets)
                cost2 = sum(c * abs(c2 - t) for t, c in targets)
                
                new_val = c1 if cost1 <= cost2 else c2
                new_val = min(10**9, new_val)

                if a[u] != new_val:
                    a[u] = new_val
                    changed = True

            if not changed:
                break

    # Formatting Output 
    # Line 1: Space separated integers for 'a'
    ans_a = " ".join(map(str, a[1:N+1]))
    
    # Line 2: The count 'd' followed by the original indices of the discarded items
    if d > 0:
        ans_discard = str(d) + " " + " ".join(map(str, discard_list))
    else:
        ans_discard = "0"

    sys.stdout.write(ans_a + "\n")
    sys.stdout.write(ans_discard + "\n")

if __name__ == '__main__':
    solve()