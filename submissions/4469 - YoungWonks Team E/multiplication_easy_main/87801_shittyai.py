import sys
from math import sqrt

def main():
    #guess then cry
    #yea i see u rohaan
    input = sys.stdin.buffer.read().split()
    idx = 0
    n = int(input[idx])
    idx += 1
    m = int(input[idx])
    idx += 1
    cap = int(input[idx])
    idx += 1

    rs = [0] * m
    cs = [0] * m
    vs = [0] * m
    ws = [0] * m
    by_idx = []
    for i in range(n + 1):
        by_idx.append([])
    for i in range(m):
        r = int(input[idx])
        idx += 1
        c = int(input[idx])
        idx += 1
        v = int(input[idx])
        idx += 1
        w = int(input[idx])
        idx += 1
        rs[i] = r
        cs[i] = c
        vs[i] = v
        ws[i] = w
        by_idx[r].append(i)
        by_idx[c].append(i)

    a = [1] * (n + 1)
    for i in range(1, n + 1):
        if by_idx[i]:
            tmp = []
            for ci in by_idx[i]:
                tmp.append(vs[ci])
            tmp.sort()
            mid = tmp[len(tmp) // 2]
            g = int(round(sqrt(mid)))
            if g < 1:
                g = 1
            a[i] = g

    sweeps = 6
    for sweep in range(sweeps):
        for i in range(1, n + 1):
            lst = by_idx[i]
            if not lst:
                continue
            pts = []
            for ci in lst:
                if rs[ci] == i:
                    other = cs[ci]
                else:
                    other = rs[ci]
                aj = a[other]
                if aj < 1:
                    aj = 1
                target = vs[ci] / aj
                weight = ws[ci] * aj / vs[ci]
                pts.append((target, weight))
            pts.sort()
            total = 0.0
            for p in pts:
                total += p[1]
            half = total / 2
            run = 0.0
            chosen = pts[0][0]
            for p in pts:
                run += p[1]
                if run >= half:
                    chosen = p[0]
                    break
            ai = int(round(chosen))
            if ai < 1:
                ai = 1
            if ai > 10**9:
                ai = 10**9
            a[i] = ai

    pens = [0.0] * m
    for i in range(m):
        prod = a[rs[i]] * a[cs[i]]
        diff = prod - vs[i]
        if diff < 0:
            diff = -diff
        pens[i] = ws[i] * diff / vs[i]

    order = sorted(range(m), key=lambda x: -pens[x])
    discard = order[:cap]
    drop = set(discard)

    for i in range(1, n + 1):
        by_idx[i] = []
    for i in range(m):
        if i in drop:
            continue
        by_idx[rs[i]].append(i)
        by_idx[cs[i]].append(i)

    for sweep in range(6):
        for i in range(1, n + 1):
            lst = by_idx[i]
            if not lst:
                continue
            pts = []
            for ci in lst:
                if rs[ci] == i:
                    other = cs[ci]
                else:
                    other = rs[ci]
                aj = a[other]
                if aj < 1:
                    aj = 1
                target = vs[ci] / aj
                weight = ws[ci] * aj / vs[ci]
                pts.append((target, weight))
            pts.sort()
            total = 0.0
            for p in pts:
                total += p[1]
            half = total / 2
            run = 0.0
            chosen = pts[0][0]
            for p in pts:
                run += p[1]
                if run >= half:
                    chosen = p[0]
                    break
            ai = int(round(chosen))
            if ai < 1:
                ai = 1
            if ai > 10**9:
                ai = 10**9
            a[i] = ai

    out1 = []
    for i in range(1, n + 1):
        out1.append(str(a[i]))
    print(' '.join(out1))

    out2 = [str(len(discard))]
    for s in discard:
        out2.append(str(s + 1))
    print(' '.join(out2))

main()