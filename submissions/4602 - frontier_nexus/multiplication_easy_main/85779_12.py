import sys
from math import log, exp
from collections import defaultdict

def weighted_median_int(values_weights):
    if not values_weights:
        return 1
    vw = sorted(values_weights)
    total_w = sum(w for v, w in vw)
    half = total_w / 2
    cumw = 0
    for v, w in vw:
        cumw += w
        if cumw >= half:
            return max(1, min(10**9, round(v)))
    return max(1, min(10**9, round(vw[-1][0])))

def solve():
    data = read_your_input().split()
    pos = 0
    N = int(data[pos]); pos += 1
    M = int(data[pos]); pos += 1
    D = int(data[pos]); pos += 1

    R = [0]*M; C = [0]*M; V = [0]*M; W = [0]*M
    for i in range(M):
        R[i] = int(data[pos]); pos += 1
        C[i] = int(data[pos]); pos += 1
        V[i] = int(data[pos]); pos += 1
        W[i] = int(data[pos]); pos += 1

    node_constraints = defaultdict(list)
    for i in range(M):
        node_constraints[R[i]].append(i)
        node_constraints[C[i]].append(i)

    log_V = [log(V[i]) for i in range(M)]

    # Phase 1: damped coordinate descent in log space
    x = [0.0] * (N+1)
    damping = 0.5

    for _ in range(800):
        sum_w   = [0.0] * (N+1)
        sum_rhs = [0.0] * (N+1)
        for i in range(M):
            r, c, w, lv = R[i], C[i], W[i], log_V[i]
            sum_w[r]   += w
            sum_rhs[r] += w * (lv - x[c])
            sum_w[c]   += w
            sum_rhs[c] += w * (lv - x[r])

        max_chg = 0.0
        for i in range(1, N+1):
            if sum_w[i] > 0:
                target = sum_rhs[i] / sum_w[i]
                nv = (1 - damping) * target + damping * x[i]
                if abs(nv - x[i]) > max_chg:
                    max_chg = abs(nv - x[i])
                x[i] = nv
        if max_chg < 1e-12:
            break

    # Phase 2: round to integers
    a = [0] * (N+1)
    for i in range(1, N+1):
        a[i] = max(1, min(10**9, round(exp(x[i]))))

    def get_constraint_penalty(i):
        return W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]

    def recompute_discards():
        pens = [(get_constraint_penalty(i), i) for i in range(M)]
        pens.sort(reverse=True)
        dm = [False] * M
        for j in range(min(D, M)):
            dm[pens[j][1]] = True
        return dm

    def node_contrib(node, val, dm):
        total = 0.0
        for ci in node_constraints[node]:
            if dm[ci]: continue
            other = C[ci] if R[ci] == node else R[ci]
            total += W[ci] * abs(val * a[other] - V[ci]) / V[ci]
        return total

    dm = recompute_discards()

    # Phase 3: integer coordinate descent using weighted median
    improved = True
    rounds = 0
    while improved and rounds < 50:
        improved = False
        rounds += 1
        for node in range(1, N+1):
            orig = a[node]
            vw = []
            for ci in node_constraints[node]:
                if dm[ci]: continue
                other = C[ci] if R[ci] == node else R[ci]
                if a[other] == 0: continue
                target = V[ci] / a[other]
                vw.append((target, W[ci]))

            if not vw:
                continue

            med = weighted_median_int(vw)
            candidates = {med, max(1, med-1), max(1, med+1),
                          max(1, min(10**9, round(exp(x[node])))), orig}

            orig_c = node_contrib(node, orig, dm)
            best_val, best_c = orig, orig_c
            for cand in candidates:
                nc = node_contrib(node, cand, dm)
                if nc < best_c:
                    best_c = nc
                    best_val = cand

            if best_val != orig:
                a[node] = best_val
                improved = True
                dm = recompute_discards()

    dm = recompute_discards()
    disc = sorted(i+1 for i in range(M) if dm[i])

    line1 = ' '.join(str(a[i]) for i in range(1, N+1))
    line2 = (str(len(disc)) + ' ' + ' '.join(str(s) for s in disc)) if disc else '0'
    better_than_me = line1 + '\n' + line2
    print(better_than_me)


def read_your_input():
    return sys.stdin.read()


solve()