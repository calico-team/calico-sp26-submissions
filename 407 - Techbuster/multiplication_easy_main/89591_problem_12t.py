import sys
import math
from array import array

def solve():
    # Fast I/O token generator to completely prevent Memory Limit Exceeded
    def get_ints():
        for line in sys.stdin:
            for token in line.split():
                yield int(token)
    
    tokens = get_ints()
    try:
        N = next(tokens)
    except StopIteration:
        return
    M = next(tokens)
    D = next(tokens)
    
    if M == 0:
        print(*( [1]*N ))
        print(0)
        return

    # Store constraints using efficient C-type arrays
    R = array('i', [0] * M)
    C = array('i', [0] * M)
    V = array('i', [0] * M)
    W = array('i', [0] * M)
    
    # Forward-star graph representation for ultra-low memory graph traversal
    head = array('i', [-1] * (N + 1))
    nxt = array('i', [-1] * (2 * M))
    to = array('i', [0] * (2 * M))
    val = array('i', [0] * (2 * M))
    weight = array('i', [0] * (2 * M))
    edge_idx = array('i', [0] * (2 * M))
    
    edge_cnt = 0
    for i in range(M):
        r = next(tokens)
        c = next(tokens)
        v = next(tokens)
        w = next(tokens)
        
        R[i] = r
        C[i] = c
        V[i] = v
        W[i] = w
        
        to[edge_cnt] = c
        val[edge_cnt] = v
        weight[edge_cnt] = w
        edge_idx[edge_cnt] = i
        nxt[edge_cnt] = head[r]
        head[r] = edge_cnt
        edge_cnt += 1
        
        to[edge_cnt] = r
        val[edge_cnt] = v
        weight[edge_cnt] = w
        edge_idx[edge_cnt] = i
        nxt[edge_cnt] = head[c]
        head[c] = edge_cnt
        edge_cnt += 1

    # Heuristic Initialization based on the median of adjacent connections
    a = [1.0] * (N + 1)
    for i in range(1, N + 1):
        edge = head[i]
        vs = []
        while edge != -1:
            vs.append(val[edge])
            edge = nxt[edge]
        if vs:
            vs.sort()
            a[i] = max(1.0, math.sqrt(vs[len(vs) // 2]))

    active = array('b', [1] * M) # Boolean array for non-discarded active edges
    
    # Adapt iteration limits based on problem density to guarantee no TLE
    if M > 1000000:
        outer_loops = 2
        inner_loops = 4
    elif M > 300000:
        outer_loops = 2
        inner_loops = 6
    else:
        outer_loops = 3
        inner_loops = 8
        
    # Main Coordinate Descent Phase using Weighted Median
    for loop in range(outer_loops):
        for _ in range(inner_loops):
            for i in range(1, N + 1):
                edge = head[i]
                if edge == -1:
                    continue
                
                pts = []
                while edge != -1:
                    idx = edge_idx[edge]
                    if active[idx]:
                        j = to[edge]
                        v = val[edge]
                        aj = a[j]
                        # Target value and its exact L1 penalty weight mapping
                        t = v / aj
                        wt = weight[edge] * aj / v
                        pts.append((t, wt))
                    edge = nxt[edge]
                
                if pts:
                    pts.sort() # Native tuple sorting is exponentially faster in Python
                    tot = sum(p[1] for p in pts)
                    half = tot / 2.0
                    cum = 0.0
                    for t, wt in pts:
                        cum += wt
                        if cum >= half:
                            a[i] = max(1.0, min(10**9, t)) # Enforce problem constraints boundary
                            break
        
        # Recalculate and disable the highest penalty constraints 
        if D > 0 and loop < outer_loops - 1:
            penalties = []
            for i in range(M):
                r = R[i]
                c = C[i]
                v = V[i]
                w = W[i]
                p = w * abs(a[r] * a[c] - v) / v
                penalties.append((p, i))
            penalties.sort(key=lambda x: x[0], reverse=True)
            
            for i in range(M):
                active[i] = 1
            for i in range(min(D, M)):
                active[penalties[i][1]] = 0

    # Final Integer Polish
    a_int = [0] * (N + 1)
    for i in range(1, N + 1):
        a_int[i] = max(1, min(10**9, int(round(a[i]))))
        
    for _ in range(3):
        changed = False
        for i in range(1, N + 1):
            edge = head[i]
            if edge == -1:
                continue
            
            best_val = a_int[i]
            best_p = -1.0
            
            # Check integer increments neighboring the final calculated vector
            for cand in (a_int[i], a_int[i] - 1, a_int[i] + 1):
                if cand < 1 or cand > 10**9:
                    continue
                p_sum = 0.0
                curr_edge = head[i]
                while curr_edge != -1:
                    idx = edge_idx[curr_edge]
                    if active[idx]:
                        j = to[curr_edge]
                        v = val[curr_edge]
                        w = weight[curr_edge]
                        p_sum += w * abs(cand * a_int[j] - v) / v
                    curr_edge = nxt[curr_edge]
                
                if best_p < 0 or p_sum < best_p:
                    best_p = p_sum
                    best_val = cand
            
            if best_val != a_int[i]:
                a_int[i] = best_val
                changed = True
        if not changed:
            break

    # Calculate final discard vector matching integer coordinates
    final_penalties = []
    for i in range(M):
        r = R[i]
        c = C[i]
        v = V[i]
        w = W[i]
        p = w * abs(a_int[r] * a_int[c] - v) / v
        final_penalties.append((p, i + 1))  # 1-indexed for final problem evaluation
        
    final_penalties.sort(key=lambda x: x[0], reverse=True)
    discarded = [final_penalties[i][1] for i in range(min(D, M))]
    discarded.sort()

    print(*(a_int[1:]))
    print(len(discarded), *(discarded))

if __name__ == '__main__':
    solve()