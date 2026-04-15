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

    best_a = None
    best_score = None
    seeds = [1.0, 2.0]
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
        rs_l = rs
        cs_l = cs
        vs_l = vs
        ws_l = ws
        a_l = a
        for sweep in range(6):
            for i in range(1, n + 1):
                lst = by_idx[i]
                if not lst:
                    continue
                pts = []
                for ci in lst:
                    if rs_l[ci] == i:
                        other = cs_l[ci]
                    else:
                        other = rs_l[ci]
                    aj = a_l[other]
                    if aj < 1:
                        aj = 1
                    target = vs_l[ci] / aj
                    weight = ws_l[ci] * aj / vs_l[ci]
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
                ai = int(chosen + 0.5)
                if ai < 1:
                    ai = 1
                if ai > 10**9:
                    ai = 10**9
                a_l[i] = ai

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
    chunk = cap // 2
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
        rs_l = rs
        cs_l = cs
        vs_l = vs
        ws_l = ws
        a_l = a
        for sweep in range(3):
            for i in range(1, n + 1):
                lst = by_idx[i]
                if not lst:
                    continue
                pts = []
                for ci in lst:
                    if rs_l[ci] == i:
                        other = cs_l[ci]
                    else:
                        other = rs_l[ci]
                    aj = a_l[other]
                    if aj < 1:
                        aj = 1
                    target = vs_l[ci] / aj
                    weight = ws_l[ci] * aj / vs_l[ci]
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
                ai = int(chosen + 0.5)
                if ai < 1:
                    ai = 1
                if ai > 10**9:
                    ai = 10**9
                a_l[i] = ai

    #polish
    rs_l = rs
    cs_l = cs
    vs_l = vs
    ws_l = ws
    a_l = a
    for sweep in range(4):
        for i in range(1, n + 1):
            lst = by_idx[i]
            if not lst:
                continue
            pts = []
            for ci in lst:
                if rs_l[ci] == i:
                    other = cs_l[ci]
                else:
                    other = rs_l[ci]
                aj = a_l[other]
                if aj < 1:
                    aj = 1
                target = vs_l[ci] / aj
                weight = ws_l[ci] * aj / vs_l[ci]
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
            ai = int(chosen + 0.5)
            if ai < 1:
                ai = 1
            if ai > 10**9:
                ai = 10**9
            a_l[i] = ai

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