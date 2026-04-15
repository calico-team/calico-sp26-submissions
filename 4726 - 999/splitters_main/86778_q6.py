import math

T = int(input())
out_lines = []
for _ in range(T):
    n, m = map(int, input().split())
    a = []
    for _ in range(n):
        row = input().strip()
        a.append(row)
    b = [[0] * m for _ in range(n)]
    c = [[1] * m for _ in range(n)]
    b[0][0] = 1
    d = 0
    e = 1
    while True:
        f = False
        g = [row[:] for row in b]
        h = [row[:] for row in c]
        for i in range(n):
            for j in range(m):
                if b[i][j] == 0:
                    continue
                ch = a[i][j]
                if ch == '.' or ch == 'X':
                    continue
                p = b[i][j]
                q = c[i][j]
                g[i][j] = 0
                h[i][j] = 1
                f = True
                if ch == '<':
                    ni, nj = i, j - 1
                    if not (0 <= ni < n and 0 <= nj < m):
                        nd = d * q + p * e
                        ne = e * q
                        gd = math.gcd(nd, ne)
                        d = nd // gd
                        e = ne // gd
                    elif a[ni][nj] == 'X':
                        pass
                    else:
                        nz = g[ni][nj] * q + p * h[ni][nj]
                        nm = h[ni][nj] * q
                        gd = math.gcd(nz, nm)
                        g[ni][nj] = nz // gd
                        h[ni][nj] = nm // gd
                elif ch == '>':
                    ni, nj = i, j + 1
                    if not (0 <= ni < n and 0 <= nj < m):
                        nd = d * q + p * e
                        ne = e * q
                        gd = math.gcd(nd, ne)
                        d = nd // gd
                        e = ne // gd
                    elif a[ni][nj] == 'X':
                        pass
                    else:
                        nz = g[ni][nj] * q + p * h[ni][nj]
                        nm = h[ni][nj] * q
                        gd = math.gcd(nz, nm)
                        g[ni][nj] = nz // gd
                        h[ni][nj] = nm // gd
                elif ch == '^':
                    ni, nj = i - 1, j
                    if not (0 <= ni < n and 0 <= nj < m):
                        nd = d * q + p * e
                        ne = e * q
                        gd = math.gcd(nd, ne)
                        d = nd // gd
                        e = ne // gd
                    elif a[ni][nj] == 'X':
                        pass
                    else:
                        nz = g[ni][nj] * q + p * h[ni][nj]
                        nm = h[ni][nj] * q
                        gd = math.gcd(nz, nm)
                        g[ni][nj] = nz // gd
                        h[ni][nj] = nm // gd
                elif ch == 'v':
                    ni, nj = i + 1, j
                    if not (0 <= ni < n and 0 <= nj < m):
                        nd = d * q + p * e
                        ne = e * q
                        gd = math.gcd(nd, ne)
                        d = nd // gd
                        e = ne // gd
                    elif a[ni][nj] == 'X':
                        pass
                    else:
                        nz = g[ni][nj] * q + p * h[ni][nj]
                        nm = h[ni][nj] * q
                        gd = math.gcd(nz, nm)
                        g[ni][nj] = nz // gd
                        h[ni][nj] = nm // gd
                elif ch == 'S':
                    cnt = 0
                    u = dw = l = r = False
                    if i > 0:
                        cc = a[i-1][j]
                        if cc == 'X':
                            u = True
                            cnt += 1
                        elif cc != '.':
                            if cc != 'v':
                                u = True
                                cnt += 1
                    if i < n-1:
                        cc = a[i+1][j]
                        if cc == 'X':
                            dw = True
                            cnt += 1
                        elif cc != '.':
                            if cc != '^':
                                dw = True
                                cnt += 1
                    if j > 0:
                        cc = a[i][j-1]
                        if cc == 'X':
                            l = True
                            cnt += 1
                        elif cc != '.':
                            if cc != '>':
                                l = True
                                cnt += 1
                    if j < m-1:
                        cc = a[i][j+1]
                        if cc == 'X':
                            r = True
                            cnt += 1
                        elif cc != '.':
                            if cc != '<':
                                r = True
                                cnt += 1
                    if cnt > 0:
                        sz = p
                        sm = q * cnt
                        gd = math.gcd(sz, sm)
                        sz //= gd
                        sm //= gd
                        if u and a[i-1][j] != 'X':
                            nz = g[i-1][j] * sm + sz * h[i-1][j]
                            nm = h[i-1][j] * sm
                            gd = math.gcd(nz, nm)
                            g[i-1][j] = nz // gd
                            h[i-1][j] = nm // gd
                        if dw and a[i+1][j] != 'X':
                            nz = g[i+1][j] * sm + sz * h[i+1][j]
                            nm = h[i+1][j] * sm
                            gd = math.gcd(nz, nm)
                            g[i+1][j] = nz // gd
                            h[i+1][j] = nm // gd
                        if l and a[i][j-1] != 'X':
                            nz = g[i][j-1] * sm + sz * h[i][j-1]
                            nm = h[i][j-1] * sm
                            gd = math.gcd(nz, nm)
                            g[i][j-1] = nz // gd
                            h[i][j-1] = nm // gd
                        if r and a[i][j+1] != 'X':
                            nz = g[i][j+1] * sm + sz * h[i][j+1]
                            nm = h[i][j+1] * sm
                            gd = math.gcd(nz, nm)
                            g[i][j+1] = nz // gd
                            h[i][j+1] = nm // gd
        b = g
        c = h
        if not f:
            break
    if d == 0:
        out_lines.append("0 1")
    else:
        gd = math.gcd(d, e)
        out_lines.append(f"{d//gd} {e//gd}")
print("\n".join(out_lines))
