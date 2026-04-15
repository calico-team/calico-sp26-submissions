import sys

# Set recursion depth just in case, though not needed for this iterative approach
sys.setrecursionlimit(2000)

def solve():
    # Read N, M, D [cite: 335]
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    M = int(input_data[1])
    D = int(input_data[2])
    
    constraints = []
    adj = [[] for _ in range(N + 1)]
    
    idx = 3
    for i in range(1, M + 1):
        r = int(input_data[idx])
        c = int(input_data[idx+1])
        v = int(input_data[idx+2])
        w = int(input_data[idx+3])
        constraints.append({'r': r, 'c': c, 'v': v, 'w': w, 'id': i})
        adj[r].append(i-1)
        adj[c].append(i-1)
        idx += 4

    # 1. Initialization: Use the square root of the median V as a starting point
    a = [1.0] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            vals = [constraints[j]['v'] for j in adj[i]]
            vals.sort()
            a[i] = max(1.0, (vals[len(vals)//2])**0.5)

    # 2. Iterative Refinement (3 passes is usually enough to beat baselines)
    def refine(active_indices):
        for _ in range(3):
            for i in range(1, N + 1):
                if not adj[i]: continue
                
                candidates = []
                for con_idx in adj[i]:
                    if con_idx not in active_indices: continue
                    con = constraints[con_idx]
                    neighbor = con['c'] if con['r'] == i else con['r']
                    # Target value for a[i] based on this constraint
                    candidates.append(con['v'] / a[neighbor])
                
                if candidates:
                    candidates.sort()
                    # Weighted median would be better, but simple median is fast and effective
                    a[i] = max(1.0, min(1e9, candidates[len(candidates)//2]))

    # Pass 1: All constraints [cite: 316]
    active = set(range(M))
    refine(active)

    # 3. Identify Discards [cite: 320]
    penalties = []
    for i in range(M):
        con = constraints[i]
        calc_v = a[con['r']] * a[con['c']]
        penalty = con['w'] * abs(calc_v - con['v']) / con['v']
        penalties.append((penalty, i))
    
    # Sort by penalty descending and take top D [cite: 350, 362]
    penalties.sort(key=lambda x: x[0], reverse=True)
    discarded_ids = [penalties[i][1] for i in range(D)]
    discarded_set = set(discarded_ids)
    
    # Final Refinement: Only non-discarded constraints
    final_active = active - discarded_set
    refine(final_active)

    # 4. Output Format [cite: 341, 342]
    # Round a[i] to integers as per sample output [cite: 380]
    int_a = [int(round(val)) for val in a[1:]]
    print(*(int_a))
    
    # Output d and discarded 1-indexed IDs [cite: 342]
    out_discarded = [i + 1 for i in discarded_ids]
    print(len(out_discarded), *out_discarded)

if __name__ == "__main__":
    solve()