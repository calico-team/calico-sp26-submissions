import sys

def solve(N, M, D, cells):
    """
    Return a tuple (A, discards) where:
      A: list of N integers in [1, 10^9]
      discards: list of at most D distinct 1-indexed cell indices to discard
    """
    # SAFETY: Ensure we don't get an IndexError if a testcase has u or v > N
    max_idx = N
    for u, v, _, _ in cells:
        if u > max_idx: max_idx = u
        if v > max_idx: max_idx = v
        
    adj = [[] for _ in range(max_idx + 1)]
    
    # Pre-calculate the division math to drastically speed up the inner loops
    for i, (u, v, val, w) in enumerate(cells):
        idx = i + 1
        val_f = float(val)
        # Prevent division by zero if a test case sneaks in a V=0
        safe_val = max(1.0, val_f) 
        w_div_val = float(w) / safe_val
        
        adj[u].append((v, val_f, w_div_val, idx))
        adj[v].append((u, val_f, w_div_val, idx))
        
    A = [1] * (max_idx + 1)
    
    # Initialization trick: Set each node to the median of the square root of its edges.
    for i in range(1, max_idx + 1):
        if adj[i]:
            sqrts = [max(1, int(x[1] ** 0.5)) for x in adj[i]]
            sqrts.sort()
            A[i] = min(10**9, sqrts[len(sqrts) // 2])
            
    # Highly optimized helper function
    def optimize_passes(passes, graph):
        for _ in range(passes):
            for i in range(1, max_idx + 1):
                edges = graph[i]
                if not edges: 
                    continue
                
                cands = []
                tot_weight = 0.0
                
                # Single inline float math to prevent timeouts
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

    # Run only 2 iterations (faster, prevents Timeout errors)
    optimize_passes(2, adj)
    
    # Calculate penalties to find discards
    penalties = []
    for i, (u, v, val, w) in enumerate(cells):
        safe_val = max(1.0, float(val))
        err = w * abs(A[u] * A[v] - val) / safe_val
        penalties.append((err, i + 1))
        
    penalties.sort(reverse=True, key=lambda x: x[0])
    
    # Protect against D being larger than the actual edges
    discards = [idx for err, idx in penalties[:min(D, len(penalties))]]
    discard_set = set(discards)
    
    # Rebuild graph without discarded edges
    adj2 = [[] for _ in range(max_idx + 1)]
    for i, (u, v, val, w) in enumerate(cells):
        idx = i + 1
        if idx not in discard_set:
            val_f = float(val)
            safe_val = max(1.0, val_f)
            w_div_val = float(w) / safe_val
            adj2[u].append((v, val_f, w_div_val, idx))
            adj2[v].append((u, val_f, w_div_val, idx))
            
    # Run 2 more fine-tuning iterations
    optimize_passes(2, adj2)
    
    # Return exactly N elements as expected by the constraints
    return A[1:N+1], discards

def main():
    # FAST I/O: Reads the entire input at once in C, bypassing Python's slow input() buffering.
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    N = int(input_data[0])
    M = int(input_data[1])
    D = int(input_data[2])
    
    cells = []
    idx = 3
    for _ in range(M):
        # Read the values directly from the pre-split array
        cells.append((int(input_data[idx]), int(input_data[idx+1]), int(input_data[idx+2]), float(input_data[idx+3])))
        idx += 4
        
    A, discards = solve(N, M, D, cells)
    
    # FAST OUTPUT: Write directly to stdout instead of calling print() multiple times
    sys.stdout.write(' '.join(str(x) for x in A) + '\n')
    sys.stdout.write(' '.join(str(x) for x in [len(discards)] + discards) + '\n')

if __name__ == '__main__':
    main()