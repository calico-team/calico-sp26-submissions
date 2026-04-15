import sys
from math import log, exp
from collections import defaultdict

def solve():
    input_data = read_your_input()
    tokens = input_data.split()
    idx = 0

    N = int(tokens[idx]); idx += 1
    M = int(tokens[idx]); idx += 1
    D = int(tokens[idx]); idx += 1

    constraints = []
    for i in range(M):
        r = int(tokens[idx]); idx += 1
        c = int(tokens[idx]); idx += 1
        v = int(tokens[idx]); idx += 1
        w = int(tokens[idx]); idx += 1
        constraints.append((r, c, v, w))

    # Work in log space: a[i] = exp(x[i])
    # penalty for constraint i = w * |exp(x[r]+x[c]) - v| / v
    # In log space, ideal: x[r] + x[c] = log(v)
    # So we want to find x[1..N] minimizing weighted sum of relative errors

    # Strategy: treat log(a[i]) = x[i], then x[r] + x[c] ~ log(v)
    # Use weighted least squares on logs as initialization, then refine

    # Build a system: for each constraint, x[r-1] + x[c-1] = log(v), weight w
    # Solve via weighted averaging iteratively (coordinate descent)

    INF = float('inf')
    x = [0.0] * (N + 1)  # 1-indexed, log space

    # Initialize x using weighted median approach per node
    # First pass: collect equations
    log_v = []
    for r, c, v, w in constraints:
        log_v.append(log(v))

    # Iterative coordinate descent in log space
    # For each node i, fix all others, find best x[i]
    # Sum over constraints involving i: w * |x[i] + x[other] - log(v)|/... 
    # Actually minimize weighted squared error first for init

    # Weighted least squares initialization
    # x[r] + x[c] = log(v)  =>  treat as linear system, solve via iterative refinement
    
    sum_w = defaultdict(float)
    sum_wx = defaultdict(float)

    # Start: x[i] = 0 for all, then do passes
    for _ in range(300):
        new_sum_w = defaultdict(float)
        new_sum_rhs = defaultdict(float)
        for idx2, (r, c, v, w) in enumerate(constraints):
            lv = log_v[idx2]
            # want x[r] + x[c] = lv
            # fix x[c], update x[r]: x[r] ~ lv - x[c]
            new_sum_w[r] += w
            new_sum_rhs[r] += w * (lv - x[c])
            new_sum_w[c] += w
            new_sum_rhs[c] += w * (lv - x[r])
        
        max_change = 0.0
        for i in range(1, N + 1):
            if new_sum_w[i] > 0:
                new_val = new_sum_rhs[i] / new_sum_w[i]
                max_change = max(max_change, abs(new_val - x[i]))
                x[i] = new_val
        
        if max_change < 1e-9:
            break

    # Convert to integers, clamp to [1, 1e9]
    a = [0] * (N + 1)
    for i in range(1, N + 1):
        val = round(exp(x[i]))
        a[i] = max(1, min(10**9, val))

    # Now decide which D constraints to discard
    # Compute penalty contribution of each constraint with current a
    penalties = []
    for i, (r, c, v, w) in enumerate(constraints):
        prod = a[r] * a[c]
        pen = w * abs(prod - v) / v
        penalties.append((pen, i + 1))  # 1-indexed

    # Sort descending by penalty, discard top D
    penalties.sort(key=lambda x: -x[0])
    discarded = []
    for i in range(min(D, M)):
        discarded.append(penalties[i][1])

    # Output
    out = []
    out.append(' '.join(str(a[i]) for i in range(1, N + 1)))
    out.append(str(len(discarded)) + (' ' + ' '.join(str(s) for s in discarded) if discarded else ''))
    
    better_than_me = '\n'.join(out)
    print(better_than_me)


def read_your_input():
    return sys.stdin.read()


solve()