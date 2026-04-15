import sys

def solve():
    # Use fast I/O
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
        u = int(input_data[ptr]); ptr += 1
        v = int(input_data[ptr]); ptr += 1
        val = int(input_data[ptr]); ptr += 1
        w = int(input_data[ptr]); ptr += 1
        constraints.append([u, v, val, w, i + 1])
        # We store (neighbor, target_val, weight, constraint_index)
        adj[u].append((v, val, w, i))
        adj[v].append((u, val, w, i))

    # Initial guess: many problems like this start well at 1 or sqrt of average V
    a = [1.0] * (N + 1)
    
    # Simple Coordinate Descent
    # We want to minimize sum of W * |a_i * a_j - V| / V
    # Which is equivalent to minimizing sum of (W/V * a_j) * |a_i - V/a_j|
    # The optimal a_i is the weighted median of (V/a_j) with weights (W/V * a_j)
    
    iterations = 5 # Small number of passes is usually enough for competitive programming
    for _ in range(iterations):
        for i in range(1, N + 1):
            if not adj[i]:
                continue
            
            points = []
            for neighbor, val, w, idx in adj[i]:
                target = val / a[neighbor]
                weight = (w / val) * a[neighbor]
                points.append((target, weight))
            
            # Weighted Median calculation
            points.sort()
            total_weight = sum(p[1] for p in points)
            cumulative_weight = 0
            for target, weight in points:
                cumulative_weight += weight
                if cumulative_weight >= total_weight / 2:
                    a[i] = max(1.0, target)
                    break

    # Convert to integers as required by the problem
    a_final = [max(1, int(round(x))) for x in a]

    # Calculate penalties to decide which D constraints to discard
    penalties = []
    for u, v, val, w, idx in constraints:
        penalty = w * abs(a_final[u] * a_final[v] - val) / val
        penalties.append((penalty, idx))
    
    # Sort by penalty descending and pick the top D to discard
    penalties.sort(key=lambda x: x[0], reverse=True)
    discarded_indices = [penalties[i][1] for i in range(min(D, M))]
    discarded_indices.sort()

    # Output results
    print(*(a_final[1:]))
    if discarded_indices:
        print(len(discarded_indices), *discarded_indices)
    else:
        print(0)

if __name__ == "__main__":
    solve()