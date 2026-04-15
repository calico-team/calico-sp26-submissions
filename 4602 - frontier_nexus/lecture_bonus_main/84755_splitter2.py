import sys
from math import log, exp
from collections import defaultdict

def solve():
    data = read_your_input().split()
    pos = 0

    N = int(data[pos]); pos += 1
    M = int(data[pos]); pos += 1
    D = int(data[pos]); pos += 1

    constraints = []
    for _ in range(M):
        r = int(data[pos]); pos += 1
        c = int(data[pos]); pos += 1
        v = int(data[pos]); pos += 1
        w = int(data[pos]); pos += 1
        constraints.append((r, c, v, w))

    # log space: x[r] + x[c] ~ log(v), coordinate descent
    x = [0.0] * (N + 1)
    log_v = [log(v) for r, c, v, w in constraints]

    for _ in range(600):
        sum_w   = [0.0] * (N + 1)
        sum_rhs = [0.0] * (N + 1)

        for i, (r, c, v, w) in enumerate(constraints):
            lv = log_v[i]
            sum_w[r]   += w
            sum_rhs[r] += w * (lv - x[c])
            sum_w[c]   += w
            sum_rhs[c] += w * (lv - x[r])

        max_change = 0.0
        for i in range(1, N + 1):
            if sum_w[i] > 0:
                new_val = sum_rhs[i] / sum_w[i]
                max_change = max(max_change, abs(new_val - x[i]))
                x[i] = new_val

        if max_change < 1e-12:
            break

    a = [0] * (N + 1)
    for i in range(1, N + 1):
        val = round(exp(x[i]))
        a[i] = max(1, min(10**9, int(val)))

    # greedily discard the D highest-penalty constraints
    pen_list = []
    for i, (r, c, v, w) in enumerate(constraints):
        prod = a[r] * a[c]
        pen = w * abs(prod - v) / v
        pen_list.append((pen, i + 1))

    pen_list.sort(key=lambda t: -t[0])
    to_discard = sorted(pen_list[j][1] for j in range(min(D, M)))

    line1 = ' '.join(str(a[i]) for i in range(1, N + 1))
    line2 = (str(len(to_discard)) + ' ' + ' '.join(str(s) for s in to_discard)) if to_discard else '0'

    better_than_me = line1 + '\n' + line2
    print(better_than_me)


def read_your_input():
    return sys.stdin.read()


solve()