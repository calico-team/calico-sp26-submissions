import sys
from math import sqrt

def main():
    #guess then cry
    #yea i see u rohaan
    input = sys.stdin.buffer.read().split()
    idx = 1
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

    best_a = None
    best_score = None
    seeds = [0.5, 1.0, 1.5, 2.0]
    for seed_mul in seeds:
        #please dont get t limit
        for i in range(1, n + 1):
            if by_idx[i]:
                tmp = []
                for ci in by_idx[i]:
                    tmp.append(vs[ci])
                tmp.sort()
                mid = tmp[len(tmp) // 2]
                g = int(round(sqrt(mid) * seed_mul))
                if g < 1:
                    g = 1
                a[i] = g
            else:
                a[i] = 1

        #another
        for sweep in range(15):
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
                cands = [int(chosen), int(chosen) + 1]
                best_v = None
                best_p = None
                for cand in cands:
                    if cand < 1:
                        cand = 1
                    if cand > 10**9:
                        cand = 10**9
                    pp = 0.0
                    for ci in lst:
                        if rs[ci] == i:
                            other = cs[ci]
                        else:
                            other = rs[ci]
                        prod = cand * a[other]
                        d = prod - vs[ci]
                        if d < 0:
                            d = -d
                        pp += ws[ci] * d / vs[ci]
                    if best_p is None or pp < best_p:
                        best_p = pp
                        best_v = cand
                a[i] = best_v

        #then we score this
        plist = []
        for i1 in range(m):
            prod = a[rs[i1]] * a[cs[i1]]
            d = prod - vs[i1]
            if d < 0:
                d = -d
            plist.append((ws[i1] * d / vs[i1], i1))
        plist.sort(reverse=True)
        sc = 0.0
        kept = 0
        for p, i1 in plist:
            if kept < cap:
                kept += 1
                continue
            sc += p
        if best_score is None or sc < best_score:
            best_score = sc
            best_a = a[:]
    a = best_a[:]

    #chunkz with rohaan
    drop = set()
    remaining = cap
    chunk = cap // 5
    if chunk < 1:
        chunk = 1
    while remaining > 0:
        pens = [0.0] * m
        for i1 in range(m):
            if i1 in drop:
                pens[i1] = -1.0
                continue
            prod = a[rs[i1]] * a[cs[i1]]
            d = prod - vs[i1]
            if d < 0:
                d = -d
            pens[i1] = ws[i1] * d / vs[i1]
        order = sorted(range(m), key=lambda x: -pens[x])
        take = min(chunk, remaining)
        added = 0
        for i1 in order:
            if added == take:
                break
            if i1 in drop:
                continue
            drop.add(i1)
            added += 1
        remaining -= added
        for i in range(1, n + 1):
            by_idx[i] = []
        for i1 in range(m):
            if i1 in drop:
                continue
            by_idx[rs[i1]].append(i1)
            by_idx[cs[i1]].append(i1)

        #more
        for sweep in range(5):
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
                cands = [int(chosen), int(chosen) + 1]
                best_v = None
                best_p = None
                for cand in cands:
                    if cand < 1:
                        cand = 1
                    if cand > 10**9:
                        cand = 10**9
                    pp = 0.0
                    for ci in lst:
                        if rs[ci] == i:
                            other = cs[ci]
                        else:
                            other = rs[ci]
                        prod = cand * a[other]
                        d = prod - vs[ci]
                        if d < 0:
                            d = -d
                        pp += ws[ci] * d / vs[ci]
                    if best_p is None or pp < best_p:
                        best_p = pp
                        best_v = cand
                a[i] = best_v

    #polish
    for sweep in range(10):
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
            cands = [int(chosen), int(chosen) + 1]
            best_v = None
            best_p = None
            for cand in cands:
                if cand < 1:
                    cand = 1
                if cand > 10**9:
                    cand = 10**9
                pp = 0.0
                for ci in lst:
                    if rs[ci] == i:
                        other = cs[ci]
                    else:
                        other = rs[ci]
                    prod = cand * a[other]
                    d = prod - vs[ci]
                    if d < 0:
                        d = -d
                    pp += ws[ci] * d / vs[ci]
                if best_p is None or pp < best_p:
                    best_p = pp
                    best_v = cand
            a[i] = best_v

    out1 = []
    for i in range(1, n + 1):
        out1.append(str(a[i]))
    print(' '.join(out1))

    discard = list(drop)
    out2 = [str(len(discard))]
    for s in discard:
        out2.append(str(s + 1))
    print(' '.join(out2))

main()