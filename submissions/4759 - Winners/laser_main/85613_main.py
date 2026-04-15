from math import gcd
import sys


def crt(a1, m1, a2, m2):
    g = gcd(m1, m2)
    diff = a2 - a1
    if diff % g != 0:
        return None
    m1g = m1 // g
    m2g = m2 // g
    k = ((diff // g) * pow(m1g, -1, m2g)) % m2g
    lcm = m1 * m2g
    return (a1 + m1 * k) % lcm, lcm


def solve(K, N, M, P, Q, X, Y):
    x0 = X[0]
    y0 = Y[0]
    gx = gcd(Q, N)
    gy = gcd(P, M)
    nx = N // gx
    my = M // gy
    invx = pow(Q // gx, -1, nx)
    invy = pow(P // gy, -1, my)
    best_t = None
    best_i = 0
    for i in range(K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M
        if dx % gx != 0 or dy % gy != 0:
            continue
        tx = ((dx // gx) * invx) % nx
        ty = ((dy // gy) * invy) % my
        merged = crt(tx, nx, ty, my)
        if merged is None:
            continue
        t, period = merged
        if t == 0:
            t = period
        if best_t is None or t < best_t:
            best_t = t
            best_i = i
    return best_i


def main():
    input = sys.stdin.readline
    T = int(input())
    out = []
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        X = []
        Y = []
        for _ in range(K):
            x, y = map(int, input().split())
            X.append(x)
            Y.append(y)
        out.append(str(solve(K, N, M, P, Q, X, Y)))
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()
