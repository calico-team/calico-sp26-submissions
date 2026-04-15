import sys

def solve():
    # Generator to handle large input efficiently 
    def get_input():
        for line in sys.stdin:
            for word in line.split():
                yield word
    
    tokens = get_input()
    
    try:
        N = int(next(tokens))
        M = int(next(tokens))
        D = int(next(tokens))
    except StopIteration:
        return

    constraints = []
    adj = [[] for _ in range(N + 1)]
    
    for i in range(1, M + 1):
        r = int(next(tokens))
        c = int(next(tokens))
        v = int(next(tokens))
        w = int(next(tokens))
        constraints.append({'r': r, 'c': c, 'v': v, 'w': w, 'id': i})
        adj[r].append(i-1)
        adj[c].append(i-1)

    # 1. Improved Initialization
    a = [1000.0] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            # Use square root of median V for a better starting guess
            v_vals = sorted([constraints[j]['v'] for j in adj[i]])
            a[i] = max(1.0, (v_vals[len(v_vals)//2])**0.5)

    def refine(active_indices, iterations):
        for _ in range(iterations):
            for i in range(1, N + 1):
                if not adj[i]: continue
                
                # We need to find x that minimizes sum |w_j * (x * neigh_j - v_j) / v_j|
                # This is equivalent to weighted median of (v_j / neigh_j)
                # with weights (w_j * neigh_j / v_j)
                weighted_candidates = []
                for con_idx in adj[i]:
                    if con_idx not in active_indices: continue
                    con = constraints[con_idx]
                    neighbor_val = a[con['c']] if con['r'] == i else a[con['r']]
                    
                    target = con['v'] / neighbor_val
                    # The weight for the median calculation
                    weight = (con['w'] * neighbor_val) / con['v']
                    weighted_candidates.append((target, weight))
                
                if not weighted_candidates: continue
                
                # Weighted Median Calculation
                weighted_candidates.sort()
                total_weight = sum(c[1] for c in weighted_candidates)
                cumulative_weight = 0
                for val, w in weighted_candidates:
                    cumulative_weight += w
                    if cumulative_weight >= total_weight / 2:
                        a[i] = max(1.0, min(1e9, val))
                        break

    # Pass 1: Global optimization [cite: 536]
    all_indices = set(range(M))
    refine(all_indices, 5)

    # 2. Strategic Discard [cite: 495, 525]
    penalties = []
    for i in range(M):
        con = constraints[i]
        calc_v = a[con['r']] * a[con['c']]
        penalty = con['w'] * abs(calc_v - con['v']) / con['v']
        penalties.append((penalty, i))
    
    # Take the D worst constraints [cite: 525, 571]
    penalties.sort(key=lambda x: x[0], reverse=True)
    discarded_ids = [penalties[i][1] for i in range(D)]
    discarded_set = set(discarded_ids)
    
    # Pass 2: Refine excluding discarded constraints to beat Agentic GPT-5.4 
    refine(all_indices - discarded_set, 3)

    # 3. Final Output [cite: 516, 517]
    # a_1 to a_N [cite: 555]
    ans_a = [str(int(round(a[i]))) for i in range(1, N + 1)]
    print(" ".join(ans_a))
    
    # d and discarded IDs (1-indexed) [cite: 556, 559]
    ans_discarded = [str(i + 1) for i in discarded_ids]
    print(f"{len(ans_discarded)} {' '.join(ans_discarded)}".strip())

if __name__ == "__main__":
    solve()