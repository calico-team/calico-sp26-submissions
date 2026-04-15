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

# runtime error counter: 3
# timelimit error: 0
# wrong answer counter: 0

import sys
import math
import time
import heapq

def main():
    t0 = time.time()
    data = sys.stdin.buffer.read().decode()
    tokens = data.split()
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

    var_cons = [[] for _ in range(N)]
    for i in range(M):
        var_cons[R[i]].append((i, C[i]))
        var_cons[C[i]].append((i, R[i]))

    LOG_MAX = math.log(1e9)

    def clamp_log(x):
        if x < 0.0: return 0.0
        if x > LOG_MAX: return LOG_MAX
        return x

    def log_to_int(x):
        x = clamp_log(x)
        v = int(math.exp(x) + 0.5)
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

        heap = []  # min-heap of (penalty, index), size D
        for i in range(M):
            p = W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
            pens_sum += p
            if p > 0:
                if len(heap) < D:
                    heapq.heappush(heap, (p, i))
                elif p > heap[0][0]:
                    heapq.heapreplace(heap, (p, i))

        ds = set()
        disc_sum = 0.0
        for p, idx in heap:
            ds.add(idx)
            disc_sum += p
        return pens_sum - disc_sum, ds

    # Phase 1: coordinate descent in log space
    log_a = [0.0] * N
    for iteration in range(30):
        if time.time() - t0 > 1.5:
            break
        for v in range(N):
            cons = var_cons[v]
            if not cons:
                continue
            num = 0.0
            den = 0.0
            for ci, other in cons:
                w = W[ci]
                num += w * (math.log(V[ci]) - log_a[other])
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
        log_a = [clamp_log(math.log(max(1, ai))) for ai in a]
        for iteration in range(20):
            if time.time() - t0 > 2.5:
                break
            for v in range(N):
                cons = var_cons[v]
                if not cons:
                    continue
                num = 0.0
                den = 0.0
                for ci, other in cons:
                    if ci in best_ds:
                        continue
                    w = W[ci]
                    num += w * (math.log(V[ci]) - log_a[other])
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

    # Phase 3: local search
    a = best_a[:]

    for local_iter in range(15):
        if time.time() - t0 > 8.5:
            break
        improved = False

        for v in range(N):
            if time.time() - t0 > 8.5:
                break
            cons = var_cons[v]
            if not cons:
                continue

            old_val = a[v]
            old_pen = 0.0
            for ci, other in cons:
                old_pen += W[ci] * abs(old_val * a[other] - V[ci]) / V[ci]

            cands = []
            seen = {old_val}
            for delta in (-3,-2,-1,1,2,3):
                nv = old_val + delta
                if 1 <= nv <= 1000000000 and nv not in seen:
                    cands.append(nv)
                    seen.add(nv)

            cnt = 0
            for ci, other in cons:
                if cnt >= 30: break
                cnt += 1
                ao = a[other]
                if ao > 0:
                    ideal = V[ci] / ao
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
                for ci, other in cons:
                    p += W[ci] * abs(nv * a[other] - V[ci]) / V[ci]
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
