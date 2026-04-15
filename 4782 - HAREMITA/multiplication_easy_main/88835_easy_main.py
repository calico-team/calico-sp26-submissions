import sys

def solve():
    # Generator for memory-efficient tokenization 
    def get_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    
    tokens = get_tokens()
    
    try:
        # No 'T' for this problem; starts directly with N, M, D [cite: 704]
        N = int(next(tokens))
        M = int(next(tokens))
        D = int(next(tokens))
    except (StopIteration, ValueError):
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

    # 1. Initialization [cite: 726]
    a = [1000.0] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            v_vals = sorted([constraints[j]['v'] for j in adj[i]])
            a[i] = max(1.0, (v_vals[len(v_vals)//2])**0.5)

    # 2. Iterative Refinement (Coordinate Descent)
    def refine(active_indices, passes):
        for _ in range(passes):
            for i in range(1, N + 1):
                if not adj[i]: continue
                
                candidates = []
                for idx in adj[i]:
                    if idx not in active_indices: continue
                    con = constraints[idx]
                    neighbor = con['c'] if con['r'] == i else con['r']
                    
                    target = con['v'] / a[neighbor]
                    # Statistical weight for relative error 
                    weight = (con['w'] * a[neighbor]) / con['v']
                    candidates.append((target, weight))
                
                if candidates:
                    candidates.sort()
                    total_w = sum(c[1] for c in candidates)
                    curr_w = 0
                    for val, w in candidates:
                        curr_w += w
                        if curr_w >= total_w / 2:
                            a[i] = max(1.0, min(10**9, val))
                            break

    # Pass 1: Global Refinement
    refine(set(range(M)), 5)

    # 3. Identify Top D Discards [cite: 689, 719]
    penalties = []
    for i in range(M):
        con = constraints[i]
        calc_v = a[con['r']] * a[con['c']]
        penalty = con['w'] * abs(calc_v - con['v']) / con['v']
        penalties.append((penalty, i))
    
    penalties.sort(key=lambda x: x[0], reverse=True)
    discarded_ids = [penalties[i][1] for i in range(D)]
    discarded_set = set(discarded_ids)
    
    # Pass 2: Refine excluding discards to beat GPT-5.4 baselines [cite: 734]
    refine(set(range(M)) - discarded_set, 3)

    # 4. Output according to format [cite: 710, 711]
    ans_a = [str(int(round(a[i]))) for i in range(1, N + 1)]
    print(" ".join(ans_a))
    
    ans_discarded = [str(i + 1) for i in discarded_ids]
    # Format: d followed by indices [cite: 711]
    print(f"{len(ans_discarded)} {' '.join(ans_discarded)}".strip())

if __name__ == "__main__":
    solve()