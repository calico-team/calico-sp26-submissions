import sys

def solve():
    # Efficient token generator for large M
    def get_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    
    tokens = get_tokens()
    
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

    # 1. Initialization [cite: 629]
    a = [1000.0] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            # Initial guess based on the median of nearby V values
            sample_v = sorted([constraints[j]['v'] for j in adj[i]])
            a[i] = max(1.0, (sample_v[len(sample_v)//2])**0.5)

    def perform_refinement(active_indices, passes):
        for _ in range(passes):
            for i in range(1, N + 1):
                if not adj[i]: continue
                
                candidates = []
                for con_idx in adj[i]:
                    if con_idx not in active_indices: continue
                    con = constraints[con_idx]
                    neighbor = con['c'] if con['r'] == i else con['r']
                    
                    target = con['v'] / a[neighbor]
                    # Statistical weight for the relative error minimization
                    weight = (con['w'] * a[neighbor]) / con['v']
                    candidates.append((target, weight))
                
                if not candidates: continue
                
                # Weighted Median update to minimize L1 relative error 
                candidates.sort()
                total_w = sum(c[1] for c in candidates)
                curr_w = 0
                for val, w in candidates:
                    curr_w += w
                    if curr_w >= total_w / 2:
                        a[i] = max(1.0, min(10**9, val))
                        break

    # Pass 1: Global Refinement [cite: 618]
    all_indices = set(range(M))
    perform_refinement(all_indices, 5)

    # 2. Identify Top D Discards 
    penalties = []
    for i in range(M):
        con = constraints[i]
        calc_v = a[con['r']] * a[con['c']]
        penalty = con['w'] * abs(calc_v - con['v']) / con['v']
        penalties.append((penalty, i))
    
    penalties.sort(key=lambda x: x[0], reverse=True)
    discarded_ids = [penalties[i][1] for i in range(D)]
    discarded_set = set(discarded_ids)
    
    # Pass 2: Fine-tune excluding the discards to beat GPT-5.4 [cite: 636, 637]
    perform_refinement(all_indices - discarded_set, 3)

    # 3. Formatted Output [cite: 613, 614]
    final_a = [str(int(round(a[i]))) for i in range(1, N + 1)]
    print(" ".join(final_a))
    
    final_discards = [str(i + 1) for i in discarded_ids]
    print(f"{len(final_discards)} {' '.join(final_discards)}".strip())

if __name__ == "__main__":
    solve()