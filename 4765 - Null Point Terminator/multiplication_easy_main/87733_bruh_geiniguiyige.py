import sys
import time
from math import log, exp
from array import array

def main():
    t0=time.time()
    data=sys.stdin.buffer.read()

    #fast int parser
    idx=0
    def rd():
        nonlocal idx
        while data[idx] <48:
            idx += 1
        num=0
        while idx< len(data) and data[idx] >= 48:
            num = num * 10 + data[idx] - 48
            idx += 1
        return num

    n=rd(); m= rd(); d=rd()

    #typed arrays: H=uint16 (n<=1500,W<=1000), I=uint32 (V<=1e9)
    R=array('H',[0]*m)
    C=array('H',[0]*m)
    V=array('I',[0]*m)
    W=array('H',[0]*m)
    for i in range(m):
        R[i]=rd()-1
        C[i] =rd()-1
        V[i] = rd()
        W[i] =rd()
    del data

    if d >= m:
        sys.stdout.write(' '.join(['1'] * n) + '\n')
        sys.stdout.write(str(m) + ' ' + ' '.join(str(i) for i in range(1, m+1)) + '\n')
        return

    #build CSR adjacency (store edge indices only)
    deg = array('i', [0] * n)
    for i in range(m):
        deg[R[i]] += 1
        deg[C[i]] += 1
    adj_ptr =array('i', [0] * (n + 1))
    for j in range(n):
        adj_ptr[j+1] = adj_ptr[j] + deg[j]
    del deg
    adj_edges = array('i', [0] * (2 * m))
    cur = array('i', [adj_ptr[j] for j in range(n)])
    for i in range(m):
        r = R[i]; c = C[i]
        adj_edges[cur[r]] = i;cur[r] += 1
        adj_edges[cur[c]] = i; cur[c] += 1
    del cur

    #init: weighted geometric mean in log-space
    log_v = array('d', [log(V[i]) if V[i] > 0 else 0.0 for i in range(m)])

    x = [0.0]*n
    ws = [0.0]*n
    for i in range(m):
        wlv = W[i] * log_v[i]
        x[R[i]] += wlv; ws[R[i]] += W[i]
        x[C[i]] += wlv; ws[C[i]] += W[i]
    for j in range(n):
        if ws[j] > 0:
            x[j] /= ws[j] * 2

    #gauss-seidel in log-space
    active = bytearray(b'\x01' * m)
    for gs in range(3):
        if time.time() - t0 > 2.0:
            break
        for j in range(n):
            st = adj_ptr[j]; en = adj_ptr[j+1]
            if st == en:
                continue
            num = 0.0; den = 0.0
            for k in range(st, en):
                ci = adj_edges[k]
                if active[ci]:
                    oi = C[ci] if R[ci]== j else R[ci]
                    num += W[ci] *(log_v[ci] - x[oi])
                    den += W[ci]
            if den > 0:
                val = num / den
                if val > 21: val = 21.0
                elif val < -21: val = -21.0
                x[j] = val

    #to integers
    a = [0]*n
    for j in range(n):
        xj = x[j]
        if xj> 20.7:
            a[j] = 1000000000
        elif xj <-20:
            a[j]= 1
        else:
            v = exp(xj)
            a[j] = max(1, min(1000000000, int(v + 0.5)))

    #Discard
    pens = array('d',[0.0] * m)
    def update_discard():
        for i in range(m):
            prod = a[R[i]] * a[C[i]]
            vi = V[i]
            pens[i] = W[i] * abs(prod - vi) / vi if vi else W[i] * prod
        if d > 0:
            order = sorted(range(m), key=pens.__getitem__, reverse=True)
            active[:] = b'\x01' * m
            for k in range(min(d, m)):
                active[order[k]] = 0

    update_discard()

    #coord descent with weighted median
    for cd in range(10):
        if time.time() - t0 > 8.0:
            break
        changed = False
        for j in range(n):
            if j % 200 == 0 and time.time() - t0 > 8.0:
                break
            st = adj_ptr[j]; en = adj_ptr[j+1]
            if st == en:
                continue
            items = []
            for k in range(st, en):
                ci = adj_edges[k]
                if not active[ci]:
                    continue
                oi = C[ci] if R[ci] ==j else R[ci]
                other = a[oi]
                vi = V[ci]
                if other <= 0 or vi == 0:
                    continue
                items.append((vi /other, W[ci] * other / vi))
            if not items:
                continue

            items.sort()
            total_w = 0.0
            for _, wt in items:
                total_w += wt
            half =total_w * 0.5
            cum= 0.0
            med =items[0][0]
            for t, wt in items:
                cum += wt
                if cum >= half:
                    med = t
                    break

            f = int(med)
            if f < 1: f = 1
            if f > 1000000000: f = 1000000000
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
            best_pen = 0.0
            for k in range(st, en):
                ci = adj_edges[k]
                if active[ci]:
                    oi = C[ci] if R[ci] == j else R[ci]
                    vi = V[ci]
                    if vi:
                        best_pen += W[ci] * abs(old * a[oi] - vi) / vi
                    else:
                        best_pen += W[ci] * old * a[oi]

            for cand in cands:
                pen = 0.0
                for k in range(st, en):
                    ci = adj_edges[k]
                    if active[ci]:
                        oi =C[ci] if R[ci] == j else R[ci]
                        vi = V[ci]
                        if vi:
                            pen += W[ci] * abs(cand * a[oi] - vi) / vi
                        else:
                            pen += W[ci] * cand * a[oi]
                if pen < best_pen:
                    best_pen = pen
                    best = cand

            if best != old:
                a[j] = best
                changed = True

        if not changed:
            break
        if time.time()- t0 > 8.0:
            break
        update_discard()

    #Final discard
    for i in range(m):
        prod = a[R[i]] * a[C[i]]
        vi = V[i]
        pens[i] = W[i]* abs(prod - vi) / vi if vi else W[i] * prod

    if d >0:
        order = sorted(range(m), key=pens.__getitem__, reverse=True)
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
