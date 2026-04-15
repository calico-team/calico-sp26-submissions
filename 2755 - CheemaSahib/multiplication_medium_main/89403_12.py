import sys
import math
import heapq
from array import array

def solve():
    it = read_your_input()
    n = next(it)
    m = next(it)
    d = next(it)

    u = array('I')
    v = array('I')
    z = array('I')
    w = array('I')
    l = array('f')

    sw = [0.0] * n
    sb = [0.0] * n

    for _ in range(m):
        a = next(it) - 1
        b = next(it) - 1
        c = next(it)
        t = next(it)
        q = math.log(c)

        u.append(a)
        v.append(b)
        z.append(c)
        w.append(t)
        l.append(q)

        sw[a] += t
        sw[b] += t
        y = t * q
        sb[a] += y
        sb[b] += y

    x = [0.0] * n
    for i in range(n):
        if sw[i]:
            x[i] = sb[i] / (2.0 * sw[i])

    uu = u
    vv = v
    zz = z
    ww = w
    ll = l
    n0 = n
    m0 = m

    for _ in range(4):
        s = [0.0] * n0
        for i in range(m0):
            a = uu[i]
            b = vv[i]
            t = ww[i]
            xa = x[a]
            xb = x[b]
            s[a] += t * xb
            s[b] += t * xa
        nx = [0.0] * n0
        for i in range(n0):
            if sw[i]:
                y = (sb[i] - s[i]) / (sw[i] + 1.0)
                nx[i] = x[i] * 0.35 + y * 0.65
        x = nx

    for _ in range(2):
        sw2 = [0.0] * n0
        sb2 = [0.0] * n0
        s = [0.0] * n0
        for i in range(m0):
            a = uu[i]
            b = vv[i]
            q = ll[i]
            e = ww[i] / (1.0 + abs(q - x[a] - x[b]))
            sw2[a] += e
            sw2[b] += e
            y = e * q
            sb2[a] += y
            sb2[b] += y
            xa = x[a]
            xb = x[b]
            s[a] += e * xb
            s[b] += e * xa
        nx = [0.0] * n0
        for i in range(n0):
            if sw2[i]:
                y = (sb2[i] - s[i]) / (sw2[i] + 1.0)
                nx[i] = x[i] * 0.25 + y * 0.75
        x = nx

    td = 0.0
    tw = 0.0
    for i in range(m0):
        t = ww[i]
        td += t * (ll[i] - x[uu[i]] - x[vv[i]])
        tw += t

    if tw:
        add = td / (2.0 * tw)
        for i in range(n0):
            x[i] += add

    lim = math.log(1000000000)
    better_than_me = [1] * n0
    lg = [0.0] * n0

    for i in range(n0):
        xi = x[i]
        if xi <= 0.0:
            better_than_me[i] = 1
            lg[i] = 0.0
        elif xi >= lim:
            better_than_me[i] = 1000000000
            lg[i] = lim
        else:
            t = int(math.exp(xi) + 0.5)
            if t < 1:
                t = 1
            elif t > 1000000000:
                t = 1000000000
            better_than_me[i] = t
            lg[i] = math.log(t)

    sm = [0.0] * n0
    ct = [0.0] * n0
    for i in range(m0):
        a = uu[i]
        b = vv[i]
        t = ww[i]
        q = ll[i]
        sm[a] += t * (q - lg[b])
        sm[b] += t * (q - lg[a])
        ct[a] += t
        ct[b] += t

    for i in range(n0):
        if ct[i]:
            xi = 0.5 * x[i] + 0.5 * (sm[i] / ct[i])
            if xi <= 0.0:
                better_than_me[i] = 1
            elif xi >= lim:
                better_than_me[i] = 1000000000
            else:
                t = int(math.exp(xi) + 0.5)
                if t < 1:
                    t = 1
                elif t > 1000000000:
                    t = 1000000000
                better_than_me[i] = t

    k = d if d <= 200000 else 200000
    disc = []

    if k:
        h = []
        push = heapq.heappush
        rep = heapq.heapreplace
        a = better_than_me
        for i in range(m0):
            p = ww[i] * abs(a[uu[i]] * a[vv[i]] - zz[i]) / zz[i]
            if len(h) < k:
                push(h, (p, i + 1))
            elif p > h[0][0]:
                rep(h, (p, i + 1))
        disc = [i for _, i in h]
        disc.sort()

    out = []
    out.append(" ".join(map(str, better_than_me)))
    if disc:
        out.append(str(len(disc)) + " " + " ".join(map(str, disc)))
    else:
        out.append("0")
    sys.stdout.write("\n".join(out))

def read_your_input():
    data = sys.stdin.buffer.read()
    n = len(data)
    i = 0
    while i < n:
        while i < n and data[i] <= 32:
            i += 1
        if i >= n:
            break
        x = 0
        while i < n and data[i] > 32:
            x = x * 10 + (data[i] - 48)
            i += 1
        yield x

if __name__ == "__main__":
    solve()
