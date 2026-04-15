import sys
import math
from bisect import bisect_left


def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(data[idx]); idx += 1
    M = int(data[idx]); idx += 1
    D = int(data[idx]); idx += 1

    R = [0] * M
    C = [0] * M
    V = [0.0] * M
    W = [0.0] * M

    for i in range(M):
        R[i] = int(data[idx]) - 1; idx += 1
        C[i] = int(data[idx]) - 1; idx += 1
        V[i] = float(data[idx]); idx += 1
        W[i] = float(data[idx]); idx += 1

    # Build adjacency: for each variable, list of (constraint_idx, partner_idx)
    adj = [[] for _ in range(N)]
    for i in range(M):
        adj[R[i]].append((i, C[i]))
        adj[C[i]].append((i, R[i]))

    # Step 1: Initialize via iterative averaging in log-space (Gauss-Seidel)
    # x[j] = log(a[j]), want x[R] + x[C] = log(V)
    x = [0.0] * N

    # Compute initial guess: average of log(V)/2 for all constraints touching j
    for j in range(N):
        if not adj[j]:
            continue
        s = 0.0
        w_total = 0.0
        for ci, partner in adj[j]:
            s += W[ci] * math.log(V[ci]) * 0.5
            w_total += W[ci]
        if w_total > 0:
            x[j] = s / w_total

    # Gauss-Seidel iterations in log-space
    for iteration in range(30):
        for j in range(N):
            if not adj[j]:
                continue
            num = 0.0
            den = 0.0
            for ci, partner in adj[j]:
                w = W[ci]
                num += w * (math.log(V[ci]) - x[partner])
                den += w
            if den > 0:
                x[j] = num / den

    # Convert to integers
    a = [0] * N
    for j in range(N):
        val = math.exp(x[j])
        a[j] = max(1, min(10**9, round(val)))

    # Step 2: Coordinate descent in original space (weighted median)
    active = [True] * M

    for outer in range(2):
        for iteration in range(10):
            changed = False
            for j in range(N):
                if not adj[j]:
                    continue

                # Collect active constraints for this variable
                targets = []
                weights = []
                constraint_info = []
                for ci, partner in adj[j]:
                    if not active[ci]:
                        continue
                    ap = max(a[partner], 1)
                    t = V[ci] / ap
                    w = W[ci] * ap / V[ci]
                    targets.append(t)
                    weights.append(w)
                    constraint_info.append((ci, partner))

                if not targets:
                    continue

                # Weighted median
                pairs = sorted(zip(targets, weights))
                total_w = sum(weights)
                half = total_w / 2.0
                cum = 0.0
                optimal = pairs[0][0]
                for t, w in pairs:
                    cum += w
                    if cum >= half:
                        optimal = t
                        break

                cand_floor = max(1, min(10**9, int(math.floor(optimal))))
                cand_ceil = max(1, min(10**9, int(math.ceil(optimal))))

                # Evaluate both candidates
                pen_floor = 0.0
                pen_ceil = 0.0
                for ci, partner in constraint_info:
                    ap = max(a[partner], 1)
                    v = V[ci]
                    w = W[ci]
                    pen_floor += w * abs(cand_floor * ap - v) / v
                    pen_ceil += w * abs(cand_ceil * ap - v) / v

                new_val = cand_floor if pen_floor <= pen_ceil else cand_ceil
                if new_val != a[j]:
                    changed = True
                    a[j] = new_val

            if not changed:
                break

        # After first round, discard top D and re-optimize
        if outer == 0 and D > 0:
            penalties = []
            for i in range(M):
                if active[i]:
                    pen = W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
                    penalties.append((pen, i))
                else:
                    penalties.append((-1.0, i))
            penalties.sort(reverse=True)
            for k in range(min(D, M)):
                if penalties[k][0] > 0:
                    active[penalties[k][1]] = False

    # Step 3: Final penalty computation, discard top D
    penalties = []
    for i in range(M):
        pen = W[i] * abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
        penalties.append((pen, i))

    if D > 0:
        penalties_sorted = sorted(penalties, reverse=True)
        discard = []
        for k in range(min(D, M)):
            if penalties_sorted[k][0] > 0:
                discard.append(penalties_sorted[k][1] + 1)  # 1-indexed
        discard.sort()
        print(' '.join(map(str, a)))
        if discard:
            print(str(len(discard)) + ' ' + ' '.join(map(str, discard)))
        else:
            print('0')
    else:
        print(' '.join(map(str, a)))
        print('0')


solve()
