t = int(input())

for _ in range(t):
    gx, gy, mx, my = map(int, input().split())
    g = {(gx, gy)}
    m = {(mx, my)}
    dr = [(0,1),(0,-1),(1,0),(-1,0)]

    for tick in range(1, 10001):
        gsp = tick % 2 == 0
        msp = tick % 7 == 0
        if not gsp and not msp:
            continue

        ng = set()
        nm = set()

        if gsp:
            for x, y in g:
                for dx, dy in dr:
                    q = (x+dx, y+dy)
                    if q not in g and q not in m:
                        ng.add(q)

        if msp:
            for x, y in m:
                for dx, dy in dr:
                    q = (x+dx, y+dy)
                    if q not in g and q not in m:
                        nm.add(q)

        nm -= ng
        g |= ng
        m |= nm

        if msp and not nm:
            break

    print(len(m))


