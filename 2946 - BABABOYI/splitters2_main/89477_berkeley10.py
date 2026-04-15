import sys
import time

def solve():
    start_time = time.time()
    input_str = sys.stdin.read().split()
    if not input_str:
        return
    data = list(map(int, input_str))
    
    N = data[0]
    M = data[1]
    D = data[2]
    
    adj = [[] for _ in range(N + 1)]
    idx = 3
    for i in range(1, M + 1):
        r = data[idx]
        c = data[idx+1]
        v = data[idx+2]
        w = data[idx+3]
        idx += 4
        adj[r].append((c, v, w, i))
        adj[c].append((r, v, w, i))
        
    a = [1] * (N + 1)
    for i in range(1, N + 1):
        if adj[i]:
            vals = sorted(v for _, v, _, _ in adj[i])
            a[i] = max(1, int(vals[len(vals)//2] ** 0.5))
            
    active_mask = [True] * (M + 1)
    
    def update_node(u):
        items = []
        for v, V, W, edge_idx in adj[u]:
            if not active_mask[edge_idx]:
                continue
            av = a[v]
            c = V / av
            w = W * av / V
            items.append((c, w))
        if not items:
            return
        items.sort(key=lambda x: x[0])
        tot_w = sum(w for c, w in items)
        half = tot_w / 2
        curr = 0
        opt_c = items[-1][0]
        for c, w in items:
            curr += w
            if curr >= half:
                opt_c = c
                break
        
        c_floor = max(1, int(opt_c))
        c_ceil = c_floor + 1
        
        cost_floor = 0
        cost_ceil = 0
        for c, w in items:
            cost_floor += w * abs(c_floor - c)
            cost_ceil += w * abs(c_ceil - c)
            
        a[u] = c_floor if cost_floor <= cost_ceil else c_ceil

    while time.time() - start_time < 4.0:
        for u in range(1, N + 1):
            update_node(u)

    if D > 0:
        penalties = []
        idx = 3
        for i in range(1, M + 1):
            r = data[idx]
            c = data[idx+1]
            v = data[idx+2]
            w = data[idx+3]
            idx += 4
            p = w * abs(a[r] * a[c] - v) / v
            penalties.append((p, i))
            
        penalties.sort(key=lambda x: x[0], reverse=True)
        for i in range(D):
            active_mask[penalties[i][1]] = False
            
        while time.time() - start_time < 8.5:
            for u in range(1, N + 1):
                update_node(u)
                
        penalties = []
        idx = 3
        for i in range(1, M + 1):
            r = data[idx]
            c = data[idx+1]
            v = data[idx+2]
            w = data[idx+3]
            idx += 4
            p = w * abs(a[r] * a[c] - v) / v
            penalties.append((p, i))
            
        penalties.sort(key=lambda x: x[0], reverse=True)
        discarded = [p[1] for p in penalties[:D]]
    else:
        discarded = []

    sys.stdout.write(" ".join(map(str, a[1:])) + "\n")
    if discarded:
        sys.stdout.write(f"{len(discarded)} " + " ".join(map(str, discarded)) + "\n")
    else:
        sys.stdout.write("0\n")

if __name__ == '__main__':
    solve()