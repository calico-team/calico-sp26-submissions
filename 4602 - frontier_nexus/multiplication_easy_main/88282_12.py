import sys
import time
import math

def solve():
    # Record start time to maximize iterations without hitting the 10s Time Limit
    start_time = time.time()
    
    # Fast I/O
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    N = int(input_data[0])
    M = int(input_data[1])
    D = int(input_data[2])
    
    # Store edges in an adjacency list. Each edge is (adjacent_node, V, W, constraint_id)
    adj = [[] for _ in range(N + 1)]
    constraints = [None] * (M + 1)
    
    idx = 3
    for i in range(1, M + 1):
        r = int(input_data[idx])
        c = int(input_data[idx+1])
        v = float(input_data[idx+2])
        w = float(input_data[idx+3])
        idx += 4
        
        constraints[i] = (r, c, v, w)
        adj[r].append((c, v, w, i))
        adj[c].append((r, v, w, i))
        
    # 1. Initialize Array intelligently using geometric means of the sqrt of incident values
    A = [1.0] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            sum_log = 0.0
            for c, v, w, cid in adj[i]:
                sum_log += math.log(max(1.0, v)) / 2.0
            A[i] = math.exp(sum_log / len(adj[i]))
        A[i] = max(1.0, A[i])
        
    discarded = [False] * (M + 1)
    
    # 2. Continuous Optimization via Coordinate Descent
    while True:
        # Halt continuous optimization at 8.5 seconds to leave room for integer polishing
        if time.time() - start_time > 8.5:
            break
            
        # Update A variables utilizing the Weighted Median algorithm
        for x in range(1, N + 1):
            if not adj[x]:
                continue
            targets = []
            for y, v, w, cid in adj[x]:
                if discarded[cid]: 
                    continue
                A_y = A[y]
                target = v / A_y
                weight = w * A_y / v
                targets.append((target, weight))
            
            if not targets:
                continue
                
            targets.sort(key=lambda t: t[0])
            total_w = sum(t[1] for t in targets)
            run_w = 0.0
            best_c = targets[-1][0]
            
            # Find the weighted median
            for t, w_val in targets:
                run_w += w_val
                if run_w >= total_w / 2.0:
                    best_c = t
                    break
            A[x] = max(1.0, best_c)
            
        # Dynamically drop the top D constraints with the highest loss
        if D > 0:
            penalties = []
            for i in range(1, M + 1):
                r, c, v, w = constraints[i]
                p = w * abs(A[r] * A[c] - v) / v
                penalties.append((p, i))
                
            penalties.sort(reverse=True, key=lambda x: x[0])
            
            discarded = [False] * (M + 1)
            for i in range(min(D, M)):
                discarded[penalties[i][1]] = True

    # 3. Discretization phase
    A_int = [max(1, round(A[i])) for i in range(N + 1)]
    
    # 4. Local Search (Hill-Climbing) for exact integer solutions 
    while time.time() - start_time < 9.5:
        improved = False
        for x in range(1, N + 1):
            if not adj[x]: continue
            
            def calc_pen(val):
                p = 0.0
                for y, v, w, cid in adj[x]:
                    if discarded[cid]: continue
                    p += w * abs(val * A_int[y] - v) / v
                return p
            
            curr_val = A_int[x]
            curr_p = calc_pen(curr_val)
            
            # Explore stepping down
            if curr_val > 1:
                down_p = calc_pen(curr_val - 1)
                if down_p < curr_p:
                    curr_p = down_p
                    curr_val -= 1
                    improved = True
            
            # Explore stepping up
            up_p = calc_pen(curr_val + 1)
            if up_p < curr_p:
                curr_val += 1
                improved = True
                
            A_int[x] = curr_val
            
        if not improved:
            break
            
    # 5. Finalize the exact D subset to ignore based on integer evaluations
    if D > 0:
        penalties = []
        for i in range(1, M + 1):
            r, c, v, w = constraints[i]
            p = w * abs(float(A_int[r] * A_int[c] - v)) / v
            penalties.append((p, i))
        penalties.sort(reverse=True, key=lambda x: x[0])
        discarded_list = [p[1] for p in penalties[:min(D, M)]]
    else:
        discarded_list = []
        
    # Output arrays format
    print(" ".join(map(str, A_int[1:])))
    if discarded_list:
        print(f"{len(discarded_list)} " + " ".join(map(str, discarded_list)))
    else:
        print("0")

if __name__ == '__main__':
    solve()