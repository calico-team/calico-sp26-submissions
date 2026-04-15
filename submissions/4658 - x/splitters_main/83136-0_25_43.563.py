import sys
from math import gcd

def solve():
    data = sys.stdin.buffer.read().split()
    if not data:
        return

    t = int(data[0])
    pt = 1
    ans = []

    for _ in range(t):
        n = int(data[pt])
        m = int(data[pt + 1])
        pt += 2

        g = data[pt:pt + n]
        pt += n

        tot = n * m
        vis = bytearray(tot)
        order = []

        st = [(0, 0)] 

        while st:
            u, back = st.pop()

            if back:
                vis[u] = 2
                order.append(u)
                continue

            if vis[u]:
                continue

            vis[u] = 1
            st.append((u, 1))

            x = u // m
            y = u - x * m
            c = g[x][y]

            if c == 94:  # ^
                if x > 0:
                    v = u - m
                    if not vis[v]:
                        st.append((v, 0))

            elif c == 118:  # v
                if x + 1 < n:
                    v = u + m
                    if not vis[v]:
                        st.append((v, 0))

            elif c == 60:  # <
                if y > 0:
                    v = u - 1
                    if not vis[v]:
                        st.append((v, 0))

            elif c == 62:  # >
                if y + 1 < m:
                    v = u + 1
                    if not vis[v]:
                        st.append((v, 0))

            elif c == 83:  # S
                if x > 0:
                    v = u - m
                    cc = g[x - 1][y]
                    if cc == 88 or (cc in (94, 118, 60, 62) and cc != 118):
                        if not vis[v]:
                            st.append((v, 0))

                if x + 1 < n:
                    v = u + m
                    cc = g[x + 1][y]
                    if cc == 88 or (cc in (94, 118, 60, 62) and cc != 94):
                        if not vis[v]:
                            st.append((v, 0))

                if y > 0:
                    v = u - 1
                    cc = g[x][y - 1]
                    if cc == 88 or (cc in (94, 118, 60, 62) and cc != 62):
                        if not vis[v]:
                            st.append((v, 0))

                if y + 1 < m:
                    v = u + 1
                    cc = g[x][y + 1]
                    if cc == 88 or (cc in (94, 118, 60, 62) and cc != 60):
                        if not vis[v]:
                            st.append((v, 0))

        num = [0] * tot
        den = [1] * tot

        for u in order:
            x = u // m
            y = u - x * m
            c = g[x][y]

            if c == 88 or c == 46 or c == 48:   # X . 0
                num[u] = 0
                den[u] = 1

            elif c == 94:   # ^
                if x == 0:
                    num[u] = 1
                    den[u] = 1
                else:
                    v = u - m
                    num[u] = num[v]
                    den[u] = den[v]

            elif c == 118:  # v
                if x + 1 == n:
                    num[u] = 1
                    den[u] = 1
                else:
                    v = u + m
                    num[u] = num[v]
                    den[u] = den[v]

            elif c == 60:   # <
                if y == 0:
                    num[u] = 1
                    den[u] = 1
                else:
                    v = u - 1
                    num[u] = num[v]
                    den[u] = den[v]

            elif c == 62:   # >
                if y + 1 == m:
                    num[u] = 1
                    den[u] = 1
                else:
                    v = u + 1
                    num[u] = num[v]
                    den[u] = den[v]

            elif c == 83:   # S
                a = 0
                b = 1
                cnt = 0

                if x > 0:
                    v = u - m
                    cc = g[x - 1][y]
                    if cc == 88 or (cc in (94, 118, 60, 62) and cc != 118):
                        p = num[v]
                        q = den[v]
                        gg = gcd(b, q)
                        a = a * (q // gg) + p * (b // gg)
                        b = (b // gg) * q
                        if a:
                            gg2 = gcd(a, b)
                            if gg2 > 1:
                                a //= gg2
                                b //= gg2
                        else:
                            b = 1
                        cnt += 1

                if x + 1 < n:
                    v = u + m
                    cc = g[x + 1][y]
                    if cc == 88 or (cc in (94, 118, 60, 62) and cc != 94):
                        p = num[v]
                        q = den[v]
                        gg = gcd(b, q)
                        a = a * (q // gg) + p * (b // gg)
                        b = (b // gg) * q
                        if a:
                            gg2 = gcd(a, b)
                            if gg2 > 1:
                                a //= gg2
                                b //= gg2
                        else:
                            b = 1
                        cnt += 1

                if y > 0:
                    v = u - 1
                    cc = g[x][y - 1]
                    if cc == 88 or (cc in (94, 118, 60, 62) and cc != 62):
                        p = num[v]
                        q = den[v]
                        gg = gcd(b, q)
                        a = a * (q // gg) + p * (b // gg)
                        b = (b // gg) * q
                        if a:
                            gg2 = gcd(a, b)
                            if gg2 > 1:
                                a //= gg2
                                b //= gg2
                        else:
                            b = 1
                        cnt += 1

                if y + 1 < m:
                    v = u + 1
                    cc = g[x][y + 1]
                    if cc == 88 or (cc in (94, 118, 60, 62) and cc != 60):
                        p = num[v]
                        q = den[v]
                        gg = gcd(b, q)
                        a = a * (q // gg) + p * (b // gg)
                        b = (b // gg) * q
                        if a:
                            gg2 = gcd(a, b)
                            if gg2 > 1:
                                a //= gg2
                                b //= gg2
                        else:
                            b = 1
                        cnt += 1

                if a == 0:
                    num[u] = 0
                    den[u] = 1
                else:
                    gg = gcd(a, cnt)
                    a //= gg
                    cnt //= gg
                    num[u] = a
                    den[u] = b * cnt

            else:
                num[u] = 0
                den[u] = 1

        ans.append(f"{num[0]} {den[0]}")

    sys.stdout.write("\n".join(ans))

solve()