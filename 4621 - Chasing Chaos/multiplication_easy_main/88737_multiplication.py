def solve(N, M, D, cells):
    """
    Return a tuple (A, discards) where:
      A: list of N integers in [1, 10^9]
      discards: list of at most D distinct 1-indexed cell indices to discard
    """
    
    
    max_idx = N
    for u, v, _, _ in cells:
        if u > max_idx: max_idx = u
        if v > max_idx: max_idx = v
        
    adj = [[] for _ in range(max_idx + 1)]
    
    
    for i, (u, v, val, w) in enumerate(cells):
        idx = i + 1
        val_f = float(val)
        
        safe_val = max(1.0, val_f) 
        w_div_val = float(w) / safe_val
        
        adj[u].append((v, val_f, w_div_val, idx))
        adj[v].append((u, val_f, w_div_val, idx))
        
    A = [1] * (max_idx + 1)
    
    
    for i in range(1, max_idx + 1):
        if adj[i]:
            sqrts = [max(1, int(x[1] ** 0.5)) for x in adj[i]]
            sqrts.sort()
            A[i] = min(10**9, sqrts[len(sqrts) // 2])
            
    
    def optimize_passes(passes, graph):
        for _ in range(passes):
            for i in range(1, max_idx + 1):
                edges = graph[i]
                if not edges: 
                    continue
                
                cands = []
                tot_weight = 0.0
                
                
                for nxt, val_f, w_div_val, idx in edges:
                    Anxt = A[nxt]
                    weight = w_div_val * Anxt
                    target = val_f / Anxt
                    cands.append((target, weight))
                    tot_weight += weight
                    
                cands.sort(key=lambda x: x[0])
                
                cur = 0.0
                half = tot_weight * 0.5
                for target, weight in cands:
                    cur += weight
                    if cur >= half:
                        A[i] = max(1, min(10**9, int(target + 0.5)))
                        break

    
    optimize_passes(2, adj)
    
    
    penalties = []
    for i, (u, v, val, w) in enumerate(cells):
        safe_val = max(1.0, float(val))
        err = w * abs(A[u] * A[v] - val) / safe_val
        penalties.append((err, i + 1))
        
    penalties.sort(reverse=True, key=lambda x: x[0])
    
    discards = [idx for err, idx in penalties[:min(D, len(penalties))]]
    discard_set = set(discards)
    
    
    adj2 = [[] for _ in range(max_idx + 1)]
    for i, (u, v, val, w) in enumerate(cells):
        idx = i + 1
        if idx not in discard_set:
            val_f = float(val)
            safe_val = max(1.0, val_f)
            w_div_val = float(w) / safe_val
            adj2[u].append((v, val_f, w_div_val, idx))
            adj2[v].append((u, val_f, w_div_val, idx))
            
    
    optimize_passes(2, adj2)
    
    
    return A[1:N+1], discards


def main():
    N, M, D = map(int, input().split())
    cells = []
    for _ in range(M):
        R, C, V, W = map(int, input().split())
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))


if __name__ == '__main__':
    main()