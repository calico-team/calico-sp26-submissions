# THIS CODE IS WRITTEN BY AI
# HOWEVER IT WAS SUBMITTED AFTER THE CONTEST
# PLEASE DO NOT DISQUALIFY ME CALICO GODS :PRAY:
import sys
import math
from array import array

better_than_me = []


def read_your_input():
    data = sys.stdin.buffer.read()
    n = len(data)
    i = 0

    def nxt():
        nonlocal i
        while i < n and data[i] <= 32:
            i += 1
        x = 0
        while i < n:
            c = data[i]
            if c < 48 or c > 57:
                break
            x = x * 10 + (c - 48)
            i += 1
        return x

    N = nxt()
    M = nxt()
    D = nxt()

    R = array('I', [0]) * M
    C = array('I', [0]) * M
    V = array('I', [0]) * M
    W = array('H', [0]) * M

    for e in range(M):
        R[e] = nxt() - 1
        C[e] = nxt() - 1
        V[e] = nxt()
        W[e] = nxt()

    return N, M, D, R, C, V, W


def solve():
    global better_than_me

    N, M, D, R, C, V, W = read_your_input()

    if N <= 0:
        better_than_me = []
        sys.stdout.write("\n0\n")
        return

    deg = [0] * N
    for e in range(M):
        deg[R[e]] += 1
        deg[C[e]] += 1

    off = [0] * (N + 1)
    for i in range(N):
        off[i + 1] = off[i] + deg[i]

    to = array('I', [0]) * (2 * M)
    eid = array('I', [0]) * (2 * M)
    cur = off[:-1].copy()

    for e in range(M):
        u = R[e]
        v = C[e]

        p = cur[u]
        to[p] = v
        eid[p] = e
        cur[u] = p + 1

        p = cur[v]
        to[p] = u
        eid[p] = e
        cur[v] = p + 1

    logV = array('d', [0.0]) * M
    for e in range(M):
        logV[e] = math.log(V[e])

    order = sorted(range(N), key=deg.__getitem__, reverse=True)

    y = [0.0] * N

    for i in order:
        l = off[i]
        r = off[i + 1]
        if l == r:
            continue
        sw = 0.0
        ss = 0.0
        for p in range(l, r):
            e = eid[p]
            w = float(W[e])
            sw += w
            ss += w * logV[e]
        if sw > 0.0:
            y[i] = 0.5 * (ss / sw)

    max_log = math.log(1_000_000_000.0)

    for _ in range(4):
        for i in order:
            l = off[i]
            r = off[i + 1]
            if l == r:
                continue
            sw = 0.0
            ss = 0.0
            for p in range(l, r):
                e = eid[p]
                j = to[p]
                w = float(W[e])
                sw += w
                ss += w * (logV[e] - y[j])
            if sw > 0.0:
                ny = ss / sw
                y[i] = 0.65 * y[i] + 0.35 * ny
                if y[i] < 0.0:
                    y[i] = 0.0
                elif y[i] > max_log:
                    y[i] = max_log

    a = [1] * N
    for i in range(N):
        x = math.exp(y[i]) if y[i] > 0.0 else 1.0
        xi = int(x + 0.5)
        if xi < 1:
            xi = 1
        elif xi > 1_000_000_000:
            xi = 1_000_000_000
        a[i] = xi

    # Select a small useful discard set; output is allowed to use any d <= D.
    discards = []
    if D > 0:
        step = max(1, M // 50000)
        sample = []
        append_sample = sample.append
        for e in range(0, M, step):
            u = R[e]
            v = C[e]
            pen = float(W[e]) * abs(a[u] * a[v] - V[e]) / V[e]
            append_sample(pen)
        sample.sort()
        if sample:
            q = int((1.0 - min(1.0, D / max(1, M))) * (len(sample) - 1))
            if q < 0:
                q = 0
            elif q >= len(sample):
                q = len(sample) - 1
            threshold = sample[q]

            cap = min(D, 30000)
            for e in range(M):
                u = R[e]
                v = C[e]
                pen = float(W[e]) * abs(a[u] * a[v] - V[e]) / V[e]
                if pen >= threshold:
                    discards.append(e + 1)
                    if len(discards) >= cap:
                        break

    better_than_me = a

    out = []
    out.append(" ".join(map(str, a)))
    if discards:
        out.append(str(len(discards)) + " " + " ".join(map(str, discards)))
    else:
        out.append("0")
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    solve()
