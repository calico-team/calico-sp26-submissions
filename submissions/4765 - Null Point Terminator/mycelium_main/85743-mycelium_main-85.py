t = int(input())
for _ in range(t):
    xg, yg, xm, ym = map(int, input().split())

    occ = {}
    occ[(xg, yg)] = 'g'
    occ[(xm, ym)] = 'm'

    gf = [(xg, yg)]
    mf = [(xm, ym)]
    gs = 0
    ms = 0
    ans = 1

    dr = [(0,1),(0,-1),(1,0),(-1,0)]

    while mf:
        gt = 2 *(gs + 1)
        mt = 7 *(ms + 1)

        if gt < mt:
            nf = []
            for x, y in gf:
                for dx, dy in dr:
                    p = (x+dx, y+dy)
                    if p not in occ:
                        occ[p] = 'g'
                        nf.append(p)
            gf = nf
            gs = gs +1
        elif gt > mt:
            nf = []
            for x, y in mf:
                for dx,dy in dr:
                    p = (x+dx, y+dy)
                    if p not in occ:
                        occ[p] = 'm'
                        nf.append(p)
                        ans = ans +1
            mf = nf
            ms = ms +1
        else:
            ng = set()
            nm = set()
            for x, y in gf:
                for dx,dy in dr:
                    p = (x+dx,y+dy)
                    if p not in occ:
                        ng.add(p)
            for x, y in mf:
                for dx, dy in dr:
                    p = (x+dx,y+dy)
                    if p not in occ:
                        nm.add(p)
            nm = nm -ng
            for p in ng:
                occ[p] = 'g'
            for p in nm:
                occ[p] = 'm'
                ans = ans +1
            gf = list(ng)
            mf = list(nm)
            gs = gs +1
            ms = ms +1

    print(ans)
