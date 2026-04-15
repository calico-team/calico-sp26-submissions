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

# runtime error counter: 4
# timelimit error: 0
# wrong answer counter: 0

import sys
import math
import time
import heapq
from array import array

def main():
    t0 = time.time()
    data = sys.stdin.buffer.read().decode()
    tokens = data.split()
    pos = 0
    N = int(tokens[pos]); pos += 1
    M = int(tokens[pos]); pos += 1
    D = int(tokens[pos]); pos += 1

    R = array('i', [0]*M)
    C = array('i', [0]*M)
    V = array('d', [0.0]*M)
    W = array('d', [0.0]*M)
    for i in range(M):
        R[i] = int(tokens[pos])-1; pos+=1
        C[i] = int(tokens[pos])-1; pos+=1
        V[i] = float(tokens[pos]); pos+=1
        W[i] = float(tokens[pos]); pos+=1
    del tokens, data

    # Build flat adjacency: for each variable, store (constraint_idx, other_var)
    # as two flat arrays + offset array
    # First pass: count per variable
    counts = array('i', [0]*N)
    for i in range(M):
        counts[R[i]] += 1
        counts[C[i]] += 1

    # Build offsets
    offsets = array('i', [0]*(N+1))
    for i in range(N):
        offsets[i+1] = offsets[i] + counts[i]

    total_adj = offsets[N]  # = 2*M
    adj_ci = array('i', [0]*total_adj)    # constraint index
    adj_ov = array('i', [0]*total_adj)    # other variable

    # Fill (use counts as running index)
    fill = array('i', [0]*N)
    for i in range(M):
        r = R[i]; c = C[i]
        pos_r = offsets[r] + fill[r]
        adj_ci[pos_r] = i; adj_ov[pos_r] = c
        fill[r] += 1
        pos_c = offsets[c] + fill[c]
        adj_ci[pos_c] = i; adj_ov[pos_c] = r
        fill[c] += 1
    del fill, counts

    LOG_MAX = math.log(1e9)
    log_func = math.log
    exp_func = math.exp

    def clamp_log(x):
        if x < 0.0: return 0.0
        if x > LOG_MAX: return LOG_MAX
        return x

    def log_to_int(x):
        if x < 0.0: x = 0.0
        elif x > LOG_MAX: x = LOG_MAX
        v = int(exp_func(x) + 0.5)
        if v < 1: return 1
        if v > 1000000000: return 1000000000
        return v

    def total_pen_with_discard(a):
        pens_sum = 0.0
        if D == 0:
            for i in range(M):
                pens_sum += W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
            return pens_sum, set()
        if D >= M:
            return 0.0, set(range(M))

        heap = []
        for i in range(M):
            p = W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
            pens_sum += p
            if p > 0:
                if len(heap) < D:
                    heapq.heappush(heap, (p, i))
                elif p > heap[0][0]:
                    heapq.heapreplace(heap, (p, i))

        disc_sum = 0.0
        ds = set()
        for p, idx in heap:
            ds.add(idx)
            disc_sum += p
        return pens_sum - disc_sum, ds

    # Phase 1: coordinate descent in log space
    log_a = [0.0] * N
    logV = array('d', [log_func(V[i]) for i in range(M)])

    for iteration in range(30):
        if time.time() - t0 > 1.5:
            break
        for v in range(N):
            start = offsets[v]; end = offsets[v+1]
            if start == end:
                continue
            num = 0.0
            den = 0.0
            for j in range(start, end):
                w = W[adj_ci[j]]
                num += w * (logV[adj_ci[j]] - log_a[adj_ov[j]])
                den += w
            if den > 0:
                log_a[v] = clamp_log(num / den)

    a = [log_to_int(log_a[i]) for i in range(N)]
    best_penalty, best_ds = total_pen_with_discard(a)
    best_a = a[:]

    # Phase 2: re-solve without discarded
    for outer in range(3):
        if time.time() - t0 > 2.5:
            break
        log_a = [clamp_log(log_func(max(1, ai))) for ai in a]
        for iteration in range(20):
            if time.time() - t0 > 2.5:
                break
            for v in range(N):
                start = offsets[v]; end = offsets[v+1]
                if start == end:
                    continue
                num = 0.0
                den = 0.0
                for j in range(start, end):
                    ci = adj_ci[j]
                    if ci in best_ds:
                        continue
                    w = W[ci]
                    num += w * (logV[ci] - log_a[adj_ov[j]])
                    den += w
                if den > 0:
                    log_a[v] = clamp_log(num / den)

        a = [log_to_int(log_a[i]) for i in range(N)]
        pen, ds = total_pen_with_discard(a)
        if pen < best_penalty - 1e-9:
            best_penalty = pen
            best_a = a[:]
            best_ds = ds
        else:
            break

    del logV  # free memory

    # Phase 3: local search
    a = best_a[:]
    _abs = abs

    for local_iter in range(15):
        if time.time() - t0 > 8.5:
            break
        improved = False

        for v in range(N):
            if time.time() - t0 > 8.5:
                break
            start = offsets[v]; end = offsets[v+1]
            if start == end:
                continue

            old_val = a[v]
            old_pen = 0.0
            for j in range(start, end):
                ci = adj_ci[j]; ov = adj_ov[j]
                old_pen += W[ci] * _abs(old_val * a[ov] - V[ci]) / V[ci]

            cands = []
            seen = {old_val}
            for delta in (-3,-2,-1,1,2,3):
                nv = old_val + delta
                if 1 <= nv <= 1000000000:
                    cands.append(nv); seen.add(nv)

            cnt = 0
            for j in range(start, end):
                if cnt >= 30: break
                cnt += 1
                ao = a[adj_ov[j]]
                if ao > 0:
                    ideal = V[adj_ci[j]] / ao
                    fl = max(1, int(ideal))
                    ce = fl + 1
                    if fl not in seen and fl <= 1000000000:
                        cands.append(fl); seen.add(fl)
                    if ce not in seen and ce <= 1000000000:
                        cands.append(ce); seen.add(ce)

            best_local = old_val
            best_local_pen = old_pen
            for nv in cands:
                p = 0.0
                for j in range(start, end):
                    ci = adj_ci[j]; ov = adj_ov[j]
                    p += W[ci] * _abs(nv * a[ov] - V[ci]) / V[ci]
                if p < best_local_pen - 1e-12:
                    best_local_pen = p
                    best_local = nv

            if best_local != old_val:
                a[v] = best_local
                improved = True

        if not improved:
            break

    pen, ds = total_pen_with_discard(a)
    if pen < best_penalty:
        best_a = a
        best_ds = ds

    # Output
    discard_1indexed = sorted(i+1 for i in best_ds)
    sys.stdout.write(' '.join(map(str, best_a)))
    sys.stdout.write('\n')
    sys.stdout.write(str(len(discard_1indexed)))
    if discard_1indexed:
        sys.stdout.write(' ')
        sys.stdout.write(' '.join(map(str, discard_1indexed)))
    sys.stdout.write('\n')

if __name__ == '__main__':
    main()
