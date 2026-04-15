import sys
import threading
import math

def solve():
    input = sys.stdin.readline
    N, M, D = map(int, input().split())

    R = [0]*M
    C = [0]*M
    V = [0]*M
    W = [0]*M

    for i in range(M):
        r, c, v, w = map(int, input().split())
        R[i] = r - 1
        C[i] = c - 1
        V[i] = v
        W[i] = w

    # log variables
    x = [0.0] * N

    # Precompute log V
    logV = [math.log(v) for v in V]

    # Iterative relaxation (few passes only)
    for _ in range(3):
        for i in range(M):
            u = R[i]
            v = C[i]
            target = logV[i]
            err = (x[u] + x[v] - target)

            w = W[i] / (V[i] + 1e-9)

            delta = 0.01 * w * err

            x[u] -= delta
            x[v] -= delta

    # Recover a_i
    a = [0]*N
    for i in range(N):
        val = int(round(math.exp(x[i])))
        val = max(1, min(10**9, val))
        a[i] = val

    # Compute penalties
    penalties = []
    for i in range(M):
        u = R[i]
        v = C[i]
        pred = a[u] * a[v]
        penalty = W[i] * abs(pred - V[i]) / V[i]
        penalties.append((penalty, i))

    # Sort descending and discard worst D
    penalties.sort(reverse=True)
    discard_set = set(idx for _, idx in penalties[:D])

    # Output
    print(*a)

    d = len(discard_set)
    if d == 0:
        print(0)
    else:
        res = [str(d)]
        for idx in discard_set:
            res.append(str(idx + 1))
        print(" ".join(res))


def main():
    solve()

if __name__ == "__main__":
    main()