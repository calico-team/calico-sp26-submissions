import sys
import time
from math import log, exp

def main():
    t0 = time.time()
    da = sys.stdin.buffer.read().decode()
    toks = da.split()
    pos = 0
    n = int(toks[pos]);pos +=1
    m = int(toks[pos]); pos += 1
    d = int(toks[pos]); pos += 1

    R = [0]*m; C = [0]*m;V = [0]*m; W = [0]*m
    for i in range(m):
        R[i] =int(toks[pos]) - 1; pos += 1
        C[i] = int(toks[pos])- 1; pos += 1
        V[i] = int(toks[pos]); pos += 1
        W[i] = int(toks[pos]); pos += 1

    if d >=m:
        sys.stdout.write(' '.join(['1'] * n) + '\n')
        sys.stdout.write(str(m) + ' ' + ' '.join(str(i) for i in range(1, m+1)) + '\n')
        return

    #build adj
    adj = [[] for _ in range(n)]
    for i in range(m):
        adj[R[i]].append((i, C[i]))
        adj[C[i]].append((i, R[i]))

    #init: weighted geometric mean in log-space
    log_v = [0.0]*m
    for i in range(m):
        log_v[i] = log(V[i]) if V[i] > 0 else 0.0

    x =[0.0]*n
    ws= [0.0]*n
    for i in range(m):
        wlv = W[i] * log_v[i]
        x[R[i]] += wlv
        ws[R[i]] +=W[i]
        x[C[i]] += wlv
        ws[C[i]]+= W[i]
    for j in range(n):
        if ws[j] > 0:
            x[j]/= ws[j] * 2

    # Gauss-Seidel in log-space(fast convergence)
    active =[True]*m
    for gs in range(3):
        if time.time() - t0 > 2.5:
            break
        for j in range(n):
            neighbors = adj[j]
            if not neighbors:
                continue
            num = 0.0
            den = 0.0
            for ci, oi in neighbors:
                if active[ci]:
                    num += W[ci] * (log_v[ci] - x[oi])
                    den += W[ci]
            if den > 0:
                x[j] = num / den

    #to integers
    a = [0]*n
    for j in range(n):
        v = exp(x[j])
        if v < 1: a[j] = 1
        elif v > 1000000000: a[j] =1000000000
        else: a[j] = int(v + 0.5)

    #Discard
    def update_discard():
        pens = [0.0]*m
        for i in range(m):
            prod = a[R[i]] * a[C[i]]
            pens[i] = W[i] * abs(prod - V[i]) / V[i]
        if d > 0:
            order = sorted(range(m), key=lambda i: pens[i], reverse=True)
            for i in range(m):
                active[i] = True
            for k in range(min(d, m)):
                active[order[k]] = False

    update_discard()

    #coordinate w/ weighted median
    for cd in range(10):
        if time.time() - t0 > 8.0:
            break
        changed = False
        for j in range(n):
            neighbors = adj[j]
            if not neighbors:
                continue
            items = []
            for ci, oi in neighbors:
                if not active[ci]:
                    continue
                other = a[oi]
                if other <= 0:
                    continue
                t = V[ci] / other
                wt = W[ci] * other / V[ci]
                items.append((t, wt))
            if not items:
                continue

            items.sort()
            total_w = 0.0
            for _, wt in items:
                total_w += wt
            half = total_w * 0.5
            cum = 0.0
            med = items[0][0]
            for t, wt in items:
                cum += wt
                if cum >= half:
                    med = t
                    break

            f = int(med)
            if f < 1: f = 1
            if f > 1000000000:f = 1000000000
            c = f + 1 if f < 1000000000 else f

            old = a[j]
            cands = []
            if f != old: cands.append(f)
            if c != old: cands.append(c)
            if old - 1 >= 1: cands.append(old - 1)
            if old + 1 <= 1000000000 and old + 1 != c: cands.append(old + 1)

            if not cands:
                continue

            best = old
            best_pen =0.0
            for ci, oi in neighbors:
                if active[ci]:
                    best_pen +=W[ci] * abs(old * a[oi] - V[ci]) / V[ci]

            for cand in cands:
                pen = 0.0
                for ci, oi in neighbors:
                    if active[ci]:
                        pen += W[ci] * abs(cand * a[oi] - V[ci]) / V[ci]
                if pen < best_pen:
                    best_pen = pen
                    best = cand

            if best!=  old:
                a[j] = best
                changed = True

        if not changed:
            break
        update_discard()

    #Final discard
    pens = [0.0]*m
    for i in range(m):
        prod = a[R[i]] * a[C[i]]
        pens[i] = W[i] * abs(prod - V[i]) / V[i]

    if d > 0:
        order = sorted(range(m), key=lambda i: pens[i], reverse=True)
        disc = sorted(order[:min(d, m)])
    else:
        disc = []

    #zero filter
    disc = [i for i in disc if pens[i] > 0]
    disc.sort()

    out = []
    out.append(' '.join(map(str, a)))
    d1 = [i + 1 for i in disc]
    if d1:
        out.append(str(len(d1)) + ' ' + ' '.join(map(str, d1)))
    else:
        out.append('0')
    sys.stdout.write('\n'.join(out) + '\n')
main()
