import sys
from math import log, exp

def main():
    data = sys.stdin.buffer.read().decode()
    tokens = data.split()
    pos = 0
    n = int(tokens[pos]);pos += 1
    m = int(tokens[pos]); pos += 1
    d = int(tokens[pos]); pos += 1

    R = [0]*m; C = [0]*m;V = [0]*m; W = [0]*m
    for i in range(m):
        R[i] = int(tokens[pos]) - 1; pos += 1
        C[i] = int(tokens[pos]) - 1; pos += 1
        V[i] = int(tokens[pos]); pos += 1
        W[i] = int(tokens[pos]); pos += 1

    if d >= m:
        sys.stdout.write(' '.join(['1']*n) + '\n')
        sys.stdout.write(str(m) + ' ' + ' '.join(str(i) for i in range(1,m+1)) + '\n')
        return

    log_v = [log(V[i]) if V[i] > 0 else 0.0 for i in range(m)]

    adj = [[] for _ in range(n)]
    for i in range(m):
        adj[R[i]].append((i, C[i]))
        adj[C[i]].append((i, R[i]))

    #weighted init
    x = [0.0]*n
    ws = [0.0]*n
    for i in range(m):
        wlv = W[i] * log_v[i]
        x[R[i]] +=wlv; ws[R[i]] += W[i]
        x[C[i]] += wlv;ws[C[i]] += W[i]
    for j in range(n):
        if ws[j] > 0:
            x[j] /= ws[j] * 2

    #gauss-seidel 3 pass
    for gs in range(3):
        for j in range(n):
            if not adj[j]: continue
            num = 0.0;den = 0.0
            for ci, oi in adj[j]:
                num += W[ci] * (log_v[ci] - x[oi])
                den += W[ci]
            if den > 0:
                x[j] = num / den

    a = [1]*n
    for j in range(n):
        v = exp(x[j])
        a[j] = max(1, min(10**9, int(v + 0.5)))

    #discard
    pens = []
    for i in range(m):
        p = W[i] *abs(a[R[i]] * a[C[i]]- V[i]) / V[i]
        pens.append((p, i))
    pens.sort(reverse=True)
    disc = sorted([pens[k][1] for k in range(min(d, m)) if pens[k][0] > 0])

    out = []
    out.append(' '.join(map(str, a)))
    d1 = [x+1 for x in disc]
    out.append(str(len(d1)) + (' ' + ' '.join(map(str, d1)) if d1 else ''))
    sys.stdout.write('\n'.join(out) + '\n')

main()
