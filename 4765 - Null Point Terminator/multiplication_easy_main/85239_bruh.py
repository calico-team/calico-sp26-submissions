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

    #init from avg log(v)/2 (unweighted)
    log_v = [log(V[i]) if V[i] > 0 else 0.0 for i in range(m)]
    log_sum = [0.0]*n
    cnt = [0]*n
    for i in range(m):
        log_sum[R[i]] +=log_v[i]
        cnt[R[i]] += 1
        log_sum[C[i]]+=log_v[i]
        cnt[C[i]] += 1

    a = [1]*n
    for j in range(n):
        if cnt[j] > 0:
            v = exp(log_sum[j] /cnt[j] / 2.0)
            a[j] = max(1, min(10**9, int(v + 0.5)))

    # build adj
    adj = [[] for _ in range(n)]
    for i in range(m):
        adj[R[i]].append((i, C[i]))
        adj[C[i]].append((i, R[i]))

    #1 pass median refinement
    for j in range(n):
        targets = []
        for ci, oi in adj[j]:
            if a[oi] > 0:
                targets.append(V[ci] / a[oi])
        if targets:
            targets.sort()
            med = targets[len(targets)//2]
            a[j] = max(1, min(10**9, int(med + 0.5)))

    # discard
    pens =[]
    for i in range(m):
        p =W[i] * abs(a[R[i]] * a[C[i]]- V[i]) / V[i]
        pens.append((p, i))
    pens.sort(reverse=True)
    disc = sorted([pens[k][1] for k in range(min(d, m)) if pens[k][0] > 0])

    out = []
    out.append(' '.join(map(str, a)))
    d1 = [x+1 for x in disc]
    out.append(str(len(d1)) + (' ' + ' '.join(map(str, d1)) if d1 else ''))
    sys.stdout.write('\n'.join(out) + '\n')

main()
