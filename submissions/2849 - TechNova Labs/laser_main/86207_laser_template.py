import math
import sys


def solve(K, N, M, P, Q, X, Y):
    best_t = None
    best_idx = 0
    sx0, sy0 = X[0], Y[0]
    lazarbeam = (sx0, sy0)

    for i in range(K):
        dx = (X[i] - sx0) % N
        dy = (Y[i] - sy0) % M

        g1 = math.gcd(Q, N)
        if dx % g1 != 0:
            continue
        Q1, dx1, N1 = Q // g1, dx // g1, N // g1
        inv1 = pow(Q1 % N1, -1, N1)
        tx = (inv1 * (dx1 % N1)) % N1

        g2 = math.gcd(P, M)
        if dy % g2 != 0:
            continue
        P1, dy1, M1 = P // g2, dy // g2, M // g2
        inv2 = pow(P1 % M1, -1, M1)
        ty = (inv2 * (dy1 % M1)) % M1

        g3 = math.gcd(N1, M1)
        if (ty - tx) % g3 != 0:
            continue
        M1g = M1 // g3
        inv3 = pow((N1 // g3) % M1g, -1, M1g)
        k = ((ty - tx) // g3 % M1g) * inv3 % M1g
        lcm = N1 * M1g
        t = (tx + N1 * k) % lcm
        if t == 0:
            t = lcm

        if best_t is None or t < best_t or (t == best_t and i < best_idx):
            best_t = t
            best_idx = i

    return best_idx


def main():
    raw = sys.stdin.buffer.read().split()
    data = [int(tok) for tok in raw if tok.lstrip(b"-").isdigit()]
    if not data:
        return
    it = iter(data)
    results = []

    for _ in range(next(it)):
        K, N, M, P, Q = next(it), next(it), next(it), next(it), next(it)
        X, Y = [], []
        for _ in range(K):
            X.append(next(it))
            Y.append(next(it))
        results.append(str(solve(K, N, M, P, Q, X, Y)))

    sys.stdout.write("\n".join(results))


def read_your_input():
    cases = []
    for _ in range(int(input())):
        K, N, M, P, Q = map(int, input().split())
        X, Y = [], []
        for _ in range(K):
            xi, yi = map(int, input().split())
            X.append(xi)
            Y.append(yi)
        cases.append((K, N, M, P, Q, X, Y))
    return cases


if __name__ == '__main__':
    main()