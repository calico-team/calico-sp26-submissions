import sys
import math
from collections import deque
import heapq


def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(data[idx]); idx += 1
    M = int(data[idx]); idx += 1
    D = int(data[idx]); idx += 1

    R = [0] * M
    C = [0] * M
    V = [0.0] * M
    W = [0.0] * M
    logV = [0.0] * M

    _log = math.log
    for i in range(M):
        R[i] = int(data[idx]) - 1; idx += 1
        C[i] = int(data[idx]) - 1; idx += 1
        V[i] = float(data[idx]); idx += 1
        W[i] = float(data[idx]); idx += 1
        logV[i] = _log(V[i]) if V[i] > 0 else 0.0

    # Build CSR adjacency for fast iteration
    off = [0] * (N + 1)
    for i in range(M):
        off[R[i] + 1] += 1
        off[C[i] + 1] += 1
    for j in range(N):
        off[j + 1] += off[j]
    adj_ci = [0] * (2 * M)
    adj_p = [0] * (2 * M)
    cur = list(off[:N])
    for i in range(M):
        r, c = R[i], C[i]
        p = cur[r]; adj_ci[p] = i; adj_p[p] = c; cur[r] = p + 1
        p = cur[c]; adj_ci[p] = i; adj_p[p] = r; cur[c] = p + 1

    # Step 1: BFS initialization in log-space (O(M) instead of iterative)
    x = [0.0] * N
    visited = bytearray(N)
    for start in range(N):
        if visited[start]:
            continue
        s0 = off[start]; e0 = off[start + 1]
        if s0 == e0:
            continue
        sm = 0.0; wt = 0.0
        for k in range(s0, e0):
            ci = adj_ci[k]
            sm += W[ci] * logV[ci] * 0.5
            wt += W[ci]
        if wt > 0:
            x[start] = sm / wt
        visited[start] = 1
        q = deque()
        q.append(start)
        while q:
            u = q.popleft()
            su = off[u]; eu = off[u + 1]
            for k in range(su, eu):
                v = adj_p[k]
                if not visited[v]:
                    x[v] = logV[adj_ci[k]] - x[u]
                    visited[v] = 1
                    q.append(v)

    # Step 2: Gauss-Seidel refinement (few passes after BFS init)
    num_iters = min(6, max(2, 80000 // max(M, 1)))
    for _ in range(num_iters):
        for j in range(N):
            sj = off[j]; ej = off[j + 1]
            if sj == ej:
                continue
            num = 0.0; den = 0.0
            for k in range(sj, ej):
                ci = adj_ci[k]
                w = W[ci]
                num += w * (logV[ci] - x[adj_p[k]])
                den += w
            if den > 0:
                x[j] = num / den

    # Convert to integers
    _exp = math.exp
    a = [0] * N
    for j in range(N):
        v = _exp(x[j])
        a[j] = max(1, min(1000000000, int(v + 0.5)))

    # Step 3: Coordinate descent (weighted median) for small inputs
    if M <= 300000:
        _floor = math.floor
        _ceil = math.ceil
        for _ in range(2):
            changed = False
            for j in range(N):
                sj = off[j]; ej = off[j + 1]
                if sj == ej:
                    continue
                pairs = []
                for k in range(sj, ej):
                    ci = adj_ci[k]
                    ap = a[adj_p[k]]
                    if ap <= 0:
                        ap = 1
                    t = V[ci] / ap
                    w = W[ci] * ap / V[ci]
                    pairs.append((t, w))
                pairs.sort()
                total_w = 0.0
                for t, w in pairs:
                    total_w += w
                half = total_w * 0.5
                cum = 0.0
                optimal = pairs[0][0]
                for t, w in pairs:
                    cum += w
                    if cum >= half:
                        optimal = t
                        break
                cf = max(1, min(1000000000, int(_floor(optimal))))
                cc = max(1, min(1000000000, int(_ceil(optimal))))
                pf = pc = 0.0
                for k in range(sj, ej):
                    ci = adj_ci[k]
                    ap = a[adj_p[k]]
                    if ap <= 0:
                        ap = 1
                    v = V[ci]; w = W[ci]
                    pf += w * abs(cf * ap - v) / v
                    pc += w * abs(cc * ap - v) / v
                nv = cf if pf <= pc else cc
                if nv != a[j]:
                    changed = True
                    a[j] = nv
            if not changed:
                break

    # Step 4: Compute penalties and discard top D
    out = [' '.join(map(str, a))]
    if D > 0:
        penalties = [0.0] * M
        for i in range(M):
            penalties[i] = W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
        dc = min(D, M)
        if dc * 4 < M:
            top = heapq.nlargest(dc, range(M), key=lambda i: penalties[i])
            discard = sorted(i + 1 for i in top if penalties[i] > 0)
        else:
            indexed = sorted(range(M), key=lambda i: penalties[i], reverse=True)
            discard = []
            for k in range(dc):
                if penalties[indexed[k]] > 0:
                    discard.append(indexed[k] + 1)
            discard.sort()
        if discard:
            out.append(str(len(discard)) + ' ' + ' '.join(map(str, discard)))
        else:
            out.append('0')
    else:
        out.append('0')

    sys.stdout.write('\n'.join(out) + '\n')


solve()
