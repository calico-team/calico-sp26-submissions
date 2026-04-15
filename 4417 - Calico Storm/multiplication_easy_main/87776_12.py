import sys
import math


def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return

    idx = 0
    N = int(data[idx]); idx += 1
    M = int(data[idx]); idx += 1
    D = int(data[idx]); idx += 1

    rows = []
    cols = []
    vals = []
    wts  = []

    for _ in range(M):
        r = int(data[idx]) - 1; idx += 1
        c = int(data[idx]) - 1; idx += 1
        v = float(data[idx]);   idx += 1
        w = float(data[idx]);   idx += 1

        rows.append(r)
        cols.append(c)
        vals.append(v)
        wts.append(w)

    # Initialize values
    x = [0.0] * N
    log_vals = [math.log(v) if v > 0 else 0 for v in vals]

    # Iterative relaxation
    for _ in range(300):
        x_old = x[:]

        numerator = [0.0] * N
        denominator = [0.0] * N

        for i in range(M):
            r = rows[i]
            c = cols[i]
            w = wts[i]

            numerator[r] += w * (log_vals[i] - x[c])
            denominator[r] += w

            numerator[c] += w * (log_vals[i] - x[r])
            denominator[c] += w

        for i in range(N):
            if denominator[i] > 0:
                x[i] = numerator[i] / denominator[i]

        # Check convergence
        diff = max(abs(x[i] - x_old[i]) for i in range(N))
        if diff < 1e-9:
            break

    # Convert to integer values
    a = []
    for val in x:
        num = round(math.exp(val))
        num = max(1, min(num, 10**9))
        a.append(num)

    penalties = []
    for i in range(M):
        if vals[i] == 0:
            penalty = 0
        else:
            penalty = wts[i] * abs(a[rows[i]] * a[cols[i]] - vals[i]) / vals[i]
        penalties.append((penalty, i))

    penalties.sort(reverse=True)
    worst = [i + 1 for _, i in penalties[:D]]

    # Output
    print(*a)
    print(len(worst), *worst)


solve()