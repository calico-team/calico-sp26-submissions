import sys
import time

def solve():
    # Start timer to safely bound our heuristic iterations against the 10-second limit
    start_time = time.time()
    
    # Fast I/O reading
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
        
        # Store as (neighbor, target_value, weight, original_index)
        adj[r].append((c, v, w, i))
        adj[c].append((r, v, w, i))
        edges.append((r, c, v, w, i))

    # Initialize the target array elements arbitrarily within constraints
    a = [10] * (N + 1)

    # Phase 1: Coordinate Descent (Weighted Median) on all edges
    # Bound to 3.5 seconds to leave ample time for the refinement phase
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

            # Find the weighted median
            targets.sort(key=lambda x: x[0])
            cur_c = 0.0
            best_t = a[u]
            half_tot = tot_c / 2.0
            
            for t, c in targets:
                cur_c += c
                if cur_c >= half_tot:
                    best_t = t
                    break

            # Clamp the value bounds between 1 and 10^9
            new_val = max(1, min(10**9, int(round(best_t))))
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
        discard_set.add(errors[j][1])
        discard_list.append(errors[j][1])

    # Rebuild the adjacency graph without the discarded outlier edges
    if d > 0:
        adj = [[] for _ in range(N + 1)]
        for r, c, v, w, i in edges:
            if i not in discard_set:
                adj[r].append((c, v, w, i))
                adj[c].append((r, v, w, i))

        # Phase 3: Refinement Descent
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

                targets.sort(key=lambda x: x[0])
                cur_c = 0.0
                best_t = a[u]
                half_tot = tot_c / 2.0
                
                for t, c in targets:
                    cur_c += c
                    if cur_c >= half_tot:
                        best_t = t
                        break

                new_val = max(1, min(10**9, int(round(best_t))))
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