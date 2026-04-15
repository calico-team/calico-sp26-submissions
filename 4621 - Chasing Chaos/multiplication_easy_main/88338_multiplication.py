def solve(N, M, D, cells):
    """
    Return a tuple (A, discards) where:
      A: list of N integers in [1, 10^9]
      discards: list of at most D distinct 1-indexed cell indices to discard

    The discards output line will begin with t, the number of discarded
    cells, followed by those t indices; t is computed and written for
    you in main().

    N: length of the array A
    M: number of cells
    D: maximum number of cells you may discard
    cells: list of M tuples (R, C, V, W); for cell k (1-indexed), the product
           A[R] * A[C] should be close to the target V, with weight W
    """
    
    # Build an adjacency list for quick neighbor lookups
    adj = [[] for _ in range(N + 1)]
    for i, (u, v, val, w) in enumerate(cells):
        adj[u].append((v, val, w, i + 1))
        adj[v].append((u, val, w, i + 1))
        
    A = [1] * (N + 1)
    
    # Initialization trick: Set each node to the median of the square root of its edges.
    # This gives the optimization algorithm a strong head start.
    for i in range(1, N + 1):
        if adj[i]:
            sqrts = [ (x[1] ** 0.5) for x in adj[i] ]
            sqrts.sort()
            A[i] = max(1, min(10**9, int(sqrts[len(sqrts)//2])))
            
    # Helper function to iteratively improve the array using weighted medians
    def optimize_passes(passes, graph):
        for _ in range(passes):
            for i in range(1, N + 1):
                if not graph[i]:
                    continue
                
                cands = []
                for nxt, val, w, idx in graph[i]:
                    # We want A[i] * A[nxt] ≈ val. 
                    # The ideal target for A[i] is val / A[nxt].
                    # The relative weight in the L1 penalty mathematically simplifies to this:
                    target = val / A[nxt]
                    weight = w * A[nxt] / val
                    cands.append((target, weight))
                    
                # Find the weighted median for this node
                cands.sort(key=lambda x: x[0])
                tot_weight = sum(x[1] for x in cands)
                
                cur = 0
                for target, weight in cands:
                    cur += weight
                    if cur >= tot_weight / 2:
                        A[i] = max(1, min(10**9, int(round(target))))
                        break

    # Run 4 iterations of coordinate descent on the full graph
    optimize_passes(4, adj)
    
    # Calculate the penalties for all constraints to see which ones are the worst
    penalties = []
    for i, (u, v, val, w) in enumerate(cells):
        err = w * abs(A[u] * A[v] - val) / val
        penalties.append((err, i + 1))
        
    # Sort by penalty (descending) and discard the worst D constraints
    penalties.sort(reverse=True, key=lambda x: x[0])
    discards = [idx for err, idx in penalties[:D]]
    discard_set = set(discards)
    
    # Rebuild the graph entirely without the discarded edges
    adj2 = [[] for _ in range(N + 1)]
    for i, (u, v, val, w) in enumerate(cells):
        if (i + 1) not in discard_set:
            adj2[u].append((v, val, w, i + 1))
            adj2[v].append((u, val, w, i + 1))
            
    # Run 5 more iterations to fine-tune the array without the bad edges dragging it down
    optimize_passes(5, adj2)
    
    return A[1:], discards


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