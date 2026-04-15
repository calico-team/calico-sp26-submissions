import sys
import math

def solve():
    # Read all inputs from standard input fast
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    N = int(input_data[0])
    M = int(input_data[1])
    D = int(input_data[2])

    # Adjacency list to store constraints per node
    # adj[node] = list of (other_node, V, W, constraint_index)
    adj = [[] for _ in range(N + 1)]
    constraints = []

    idx = 3
    for i in range(1, M + 1):
        u = int(input_data[idx])
        v = int(input_data[idx+1])
        V = int(input_data[idx+2])
        W = int(input_data[idx+3])
        idx += 4
        
        constraints.append((u, v, V, W, i))
        adj[u].append((v, V, W, i))
        adj[v].append((u, V, W, i))

    # Initialize the array
    # A good guess is the square root of the median V for that row/col
    a = [1] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            vals = sorted([V for _, V, _, _ in adj[i]])
            median_V = vals[len(vals) // 2]
            a[i] = max(1, int(math.sqrt(median_V)))

    active = [True] * (M + 1)

    # Coordinate Descent Function
    def run_iterations(iters):
        for _ in range(iters):
            for i in range(1, N + 1):
                if not adj[i]: 
                    continue
                
                targets = []
                total_weight = 0.0
                
                for v, V, W, c_idx in adj[i]:
                    if not active[c_idx]: 
                        continue
                    
                    target_val = V / a[v]
                    weight = (W * a[v]) / V
                    
                    targets.append((target_val, weight))
                    total_weight += weight
                    
                if not targets:
                    continue
                    
                # Calculate the weighted median
                targets.sort(key=lambda x: x[0])
                cum_weight = 0.0
                chosen_val = targets[-1][0] # Default to max
                
                for val, w in targets:
                    cum_weight += w
                    if cum_weight >= total_weight / 2.0:
                        chosen_val = val
                        break
                        
                # Update the variable, ensuring it remains at least 1
                a[i] = max(1, int(round(chosen_val)))

    # Phase 1: Optimize with all constraints active
    run_iterations(15)

    discarded_indices = []
    
    # Phase 2: Discard the worst constraints and refine
    if D > 0:
        penalties = []
        for u, v, V, W, c_idx in constraints:
            pen = W * abs(a[u] * a[v] - V) / V
            penalties.append((pen, c_idx))
            
        # Sort penalties descending to find the worst offenders
        penalties.sort(key=lambda x: x[0], reverse=True)
        
        for i in range(D):
            c_idx = penalties[i][1]
            active[c_idx] = False
            discarded_indices.append(c_idx)
            
        # Refine the array without the noisy discarded constraints
        run_iterations(10)

    # Print output formatted according to the problem requirements
    print(" ".join(map(str, a[1:])))
    
    if D > 0:
        print(f"{D} " + " ".join(map(str, discarded_indices)))
    else:
        print("0")

if __name__ == '__main__':
    solve()