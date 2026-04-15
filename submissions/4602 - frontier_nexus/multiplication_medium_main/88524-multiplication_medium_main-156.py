import sys
import time
import math

def solve():
    # 1. Initialize timer and Fast I/O
    start_time = time.time()
    
    # Read all standard input at once into a list of strings
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    iterator = iter(input_data)
    try:
        N = int(next(iterator))
        M = int(next(iterator))
        D = int(next(iterator))
    except StopIteration:
        return
        
    # 2. Graph Representation
    adj = [[] for _ in range(N + 1)]
    constraints = [None] * (M + 1)
    
    for i in range(1, M + 1):
        r = int(next(iterator))
        c = int(next(iterator))
        v = float(next(iterator))
        w = float(next(iterator))
        
        constraints[i] = (r, c, v, w)
        adj[r].append((c, v, w, i))
        adj[c].append((r, v, w, i))
        
    # 3. Smart Initialization (Geometric mean of the square root of incident values)
    A = [1.0] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            sum_log = 0.0
            for c, v, w, cid in adj[i]:
                sum_log += math.log(max(1.0, v)) / 2.0
            A[i] = math.exp(sum_log / len(adj[i]))
        A[i] = max(1.0, A[i])
        
    discarded = [False] * (M + 1)
    
    # 4. Continuous Optimization via Coordinate Descent
    # Halt at 8.0 seconds to leave ample time for integer rounding and final output
    while time.time() - start_time < 8.0:
        max_shift = 0.0
        
        for x in range(1, N + 1):
            if not adj[x]:
                continue
            
            targets = []
            for y, v, w, cid in adj[x]:
                if discarded[cid]: 
                    continue
                A_y = A[y]
                
                # Target value for A[x] to satisfy A[x] * A[y] = V
                target = v / A_y
                # Weight mathematically derived from L1 penalty derivative
                weight = w * A_y / v
                targets.append((target, weight))
            
            if not targets:
                continue
                
            # Sort targets to find the weighted median
            targets.sort(key=lambda t: t[0])
            total_w = sum(t[1] for t in targets)
            run_w = 0.0
            best_c = targets[-1][0]
            
            for t, w_val in targets:
                run_w += w_val
                if run_w >= total_w / 2.0:
                    best_c = t
                    break
            
            best_c = max(1.0, best_c)
            shift = abs(A[x] - best_c)
            if shift > max_shift:
                max_shift = shift
            A[x] = best_c
            
        # Dynamically drop the worst D constraints
        if D > 0:
            penalties = []
            for i in range(1, M + 1):
                r, c, v, w = constraints[i]
                p = w * abs(A[r] * A[c] - v) / v
                penalties.append((p, i))
                
            penalties.sort(reverse=True, key=lambda x: x[0])
            
            discarded = [False] * (M + 1)
            for i in range(D):
                discarded[penalties[i][1]] = True
                
        # Early stopping if the array has stabilized
        if max_shift < 1e-3:
            break

    # 5. Discretization Phase
    A_int = [max(1, round(A[i])) for i in range(N + 1)]
    
    # 6. Final Discard Selection based strictly on integers
    discarded_list = []
    if D > 0:
        penalties = []
        for i in range(1, M + 1):
            r, c, v, w = constraints[i]
            p = w * abs(float(A_int[r] * A_int[c] - v)) / v
            penalties.append((p, i))
        penalties.sort(reverse=True, key=lambda x: x[0])
        discarded_list = [p[1] for p in penalties[:D]]
        
    # 7. Output Format Generation
    print(" ".join(map(str, A_int[1:])))
    if discarded_list:
        print(f"{len(discarded_list)} " + " ".join(map(str, discarded_list)))
    else:
        print("0")

if __name__ == '__main__':
    solve()