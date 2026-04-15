# WRITTEN BY CLAUDE OPUS 4.6 EXTENDED

#   /$$$$$$  /$$        /$$$$$$  /$$   /$$ /$$$$$$$  /$$$$$$$$
#  /$$__  $$| $$       /$$__  $$| $$  | $$| $$__  $$| $$_____/
# | $$  \__/| $$      | $$  \ $$| $$  | $$| $$  \ $$| $$
# | $$      | $$      | $$$$$$$$| $$  | $$| $$  | $$| $$$$$
# | $$      | $$      | $$__  $$| $$  | $$| $$  | $$| $$__/
# | $$    $$| $$      | $$  | $$| $$  | $$| $$  | $$| $$
# |  $$$$$$/| $$$$$$$$| $$  | $$|  $$$$$$/| $$$$$$$/| $$$$$$$$
#  \______/ |________/|__/  |__/ \______/ |_______/ |________/
                                                            
# (which should probably be allowed since contest ended and I have 0 clue how to do this)
# PLS NO BAN

import sys
import math
import time
from collections import defaultdict

def main():
    t0 = time.time()
    input_data = sys.stdin.buffer.read().decode()
    tokens = input_data.split()
    pos = 0
    N = int(tokens[pos]); pos += 1
    M = int(tokens[pos]); pos += 1
    D = int(tokens[pos]); pos += 1

    R = [0]*M; C = [0]*M; V = [0.0]*M; W = [0.0]*M
    for i in range(M):
        R[i] = int(tokens[pos])-1; pos+=1
        C[i] = int(tokens[pos])-1; pos+=1
        V[i] = float(tokens[pos]); pos+=1
        W[i] = float(tokens[pos]); pos+=1

    # Per-variable adjacency
    var_cons = defaultdict(list)  # var -> list of (constraint_idx, other_var)
    for i in range(M):
        var_cons[R[i]].append((i, C[i]))
        var_cons[C[i]].append((i, R[i]))

    # Phase 1: weighted geometric mean approach in log space
    # For each variable, collect log(V) - log(a_other) targets
    # Start with a = all 1s, iterate
    log_a = [0.0] * N  # ln(a[i])

    # Initialize: for each var, weighted average of (ln(V) - ln(a_other))
    # Iterate coordinate descent in log space
    for iteration in range(40):
        if time.time() - t0 > 2.0:
            break
        max_change = 0.0
        for v in range(N):
            if v not in var_cons or not var_cons[v]:
                continue
            num = 0.0
            den = 0.0
            for ci, other in var_cons[v]:
                w = W[ci]
                target = math.log(V[ci]) - log_a[other]
                num += w * target
                den += w
            if den > 0:
                new_val = num / den
                max_change = max(max_change, abs(new_val - log_a[v]))
                log_a[v] = new_val
        if max_change < 1e-9:
            break

    a = [max(1, min(10**9, round(math.exp(log_a[i])))) for i in range(N)]

    # Compute penalties
    def calc_penalties(a):
        pens = [0.0]*M
        for i in range(M):
            pens[i] = W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
        return pens

    def pick_discard(pens):
        if D == 0:
            return set()
        indexed = [(pens[i], i) for i in range(M)]
        indexed.sort(reverse=True)
        ds = set()
        for j in range(min(D, M)):
            if indexed[j][0] > 0:
                ds.add(indexed[j][1])
            else:
                break
        return ds

    def total_pen(pens, ds):
        s = 0.0
        for i in range(M):
            if i not in ds:
                s += pens[i]
        return s

    pens = calc_penalties(a)
    ds = pick_discard(pens)
    best_penalty = total_pen(pens, ds)
    best_a = a[:]
    best_ds = ds

    # Phase 2: re-solve log-space without discarded, iterate
    for outer in range(5):
        if time.time() - t0 > 3.0:
            break
        log_a = [math.log(max(1, a[i])) for i in range(N)]
        for iteration in range(30):
            if time.time() - t0 > 3.0:
                break
            for v in range(N):
                if v not in var_cons or not var_cons[v]:
                    continue
                num = 0.0
                den = 0.0
                for ci, other in var_cons[v]:
                    if ci in best_ds:
                        continue
                    w = W[ci]
                    target = math.log(V[ci]) - log_a[other]
                    num += w * target
                    den += w
                if den > 0:
                    log_a[v] = num / den

        a = [max(1, min(10**9, round(math.exp(log_a[i])))) for i in range(N)]
        pens = calc_penalties(a)
        ds = pick_discard(pens)
        pen = total_pen(pens, ds)
        if pen < best_penalty - 1e-9:
            best_penalty = pen
            best_a = a[:]
            best_ds = ds
        else:
            break

    # Phase 3: local search
    a = best_a[:]
    pens = calc_penalties(a)

    for local_iter in range(20):
        if time.time() - t0 > 9.0:
            break
        improved = False

        for v in range(N):
            if time.time() - t0 > 9.0:
                break
            if v not in var_cons or not var_cons[v]:
                continue

            old_val = a[v]
            constraints = var_cons[v]

            # Current penalty sum for this var's constraints
            old_pen = 0.0
            for ci, other in constraints:
                old_pen += W[ci] * abs(old_val * a[other] - V[ci]) / V[ci]

            # Candidates: +/-1,2,3 and ideal values
            cands = set()
            for delta in [-3,-2,-1,1,2,3]:
                nv = old_val + delta
                if 1 <= nv <= 10**9:
                    cands.add(nv)
            for ci, other in constraints[:40]:
                if a[other] > 0:
                    ideal = V[ci] / a[other]
                    for nv in (max(1,int(ideal)), max(1,int(ideal)+1)):
                        if nv <= 10**9:
                            cands.add(nv)
            cands.discard(old_val)

            best_local = old_val
            best_local_pen = old_pen
            for nv in cands:
                p = 0.0
                for ci, other in constraints:
                    p += W[ci] * abs(nv * a[other] - V[ci]) / V[ci]
                if p < best_local_pen - 1e-12:
                    best_local_pen = p
                    best_local = nv

            if best_local != old_val:
                a[v] = best_local
                improved = True

        if not improved:
            break

    pens = calc_penalties(a)
    ds = pick_discard(pens)
    pen = total_pen(pens, ds)
    if pen < best_penalty:
        best_a = a[:]
        best_ds = ds

    # Output
    discard_1indexed = sorted([i+1 for i in best_ds])
    sys.stdout.write(' '.join(str(x) for x in best_a) + '\n')
    sys.stdout.write(str(len(discard_1indexed)))
    if discard_1indexed:
        sys.stdout.write(' ' + ' '.join(str(x) for x in discard_1indexed))
    sys.stdout.write('\n')

if __name__ == '__main__':
    main()
