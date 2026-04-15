import sys
from math import sqrt

def main():
    data = sys.stdin.buffer.read().decode()
    tokens = data.split()
    pos = 0
    n = int(tokens[pos]); pos += 1
    m = int(tokens[pos]); pos += 1
    d = int(tokens[pos]); pos += 1

    R = [0]*m; C = [0]*m; V = [0]*m; W = [0]*m
    for i in range(m):
        R[i] = int(tokens[pos]) - 1; pos += 1
        C[i] = int(tokens[pos]) - 1; pos += 1
        V[i] = int(tokens[pos]); pos += 1
        W[i] = int(tokens[pos]); pos += 1

    ###
    vals_for = [[] for _ in range(n)]
    for i in range(m):
        sv = sqrt(V[i])
        vals_for[R[i]].append(sv)
        vals_for[C[i]].append(sv)

    a = [1]*n
    for j in range(n):
        if vals_for[j]:
            vals_for[j].sort()
            a[j] = max(1, int(vals_for[j][len(vals_for[j])//2] + 0.5))

    # adj
    adj = [[] for _ in range(n)]
    for i in range(m):
        adj[R[i]].append((i, C[i]))
        adj[C[i]].append((i, R[i]))

    #2 round
    for it in range(2):
        for j in range(n):
            targets = []
            for ci, oi in adj[j]:
                if a[oi] > 0:
                    targets.append(V[ci] / a[oi])
            if targets:
                targets.sort()
                med = targets[len(targets)//2]
                a[j] = max(1, min(10**9, int(med + 0.5)))

    #worst d
    pens = []
    for i in range(m):
        p = W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
        pens.append((p, i))
    pens.sort(reverse=True)
    disc = sorted([pens[k][1] for k in range(min(d, m)) if pens[k][0] > 0])

    out = []
    out.append(' '.join(map(str, a)))
    d1 = [x+1 for x in disc]
    out.append(str(len(d1)) + (' ' + ' '.join(map(str, d1)) if d1 else ''))
    sys.stdout.write('\n'.join(out) + '\n')

main()
