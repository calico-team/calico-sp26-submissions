import sys

def solve():
    # Read N, M, D
    line1 = sys.stdin.readline().split()
    if not line1: return
    N, M, D = map(int, line1)
    
    constraints = []
    adj = [[] for _ in range(N + 1)]
    
    for i in range(1, M + 1):
        r, c, v, w = map(int, sys.stdin.readline().split())
        constraints.append({'r': r, 'c': c, 'v': v, 'w': w, 'id': i})
        adj[r].append(len(constraints) - 1)
        adj[c].append(len(constraints) - 1)

    # 1. Initialize a_i with a reasonable guess
    a = [1000] * (N + 1) # Starting at 1000 is a safe middle ground for Vi up to 10^9
    
    # 2. Iterative Refinement (Coordinate Descent)
    # We perform a few passes to lower the penalty
    for _ in range(5):
        for i in range(1, N + 1):
            if not adj[i]: continue
            
            # Find best a[i] by checking values around the current average target
            targets = []
            for idx in adj[i]:
                con = constraints[idx]
                neighbor_val = a[con['c']] if con['r'] == i else a[con['r']]
                targets.append(con['v'] // neighbor_val)
            
            # Use the median of targets as a robust estimator
            targets.sort()
            new_val = max(1, targets[len(targets)//2])
            a[i] = min(10**9, new_val)

    # 3. Calculate individual penalties and find top D to discard
    penalties = []
    for i in range(M):
        con = constraints[i]
        calc_v = a[con['r']] * a[con['c']]
        error = abs(calc_v - con['v']) / con['v']
        weighted_error = con['w'] * error
        penalties.append((weighted_error, con['id']))
    
    penalties.sort(key=lambda x: x[0], reverse=True)
    
    discarded_indices = [p[1] for p in penalties[:D]]
    
    # 4. Output according to format
    # a_1 to a_N
    print(*(a[1:]))
    # d followed by discarded indices
    print(len(discarded_indices), *discarded_indices)

if __name__ == "__main__":
    solve()