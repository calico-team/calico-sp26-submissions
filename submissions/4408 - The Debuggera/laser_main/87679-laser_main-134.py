import math
import sys


def solve_lin(a, b, m):
    """Smallest k0 in [0, period) such that a*k ≡ b (mod m); all solutions k ≡ k0 (mod period).
    Returns (k0, period). period==0 means any integer k satisfies the congruence (a≡b≡0 mod m)."""
    if m == 0:
        return None
    a %= m
    b %= m
    g = math.gcd(a, m)
    if b % g:
        return None
    if a == 0:
        if b == 0:
            return (0, 0)
        return None
    a1 = a // g
    b1 = b // g
    m1 = m // g
    inv = pow(a1, -1, m1)
    k0 = (b1 * inv) % m1
    return (k0, m1)


def min_t_hit(X0, Y0, P, Q, N, M, Xi, Yi):
    ax = (Xi - X0) % N
    ay = (Yi - Y0) % M

    gq = math.gcd(Q, N)
    if ax % gq:
        return None
    N1 = N // gq
    if N1 == 1:
        s2 = solve_lin(P, ay, M)
        if s2 is None:
            return None
        t0, p = s2
        if p == 0:
            tx = N // math.gcd(Q, N)
            ty = M // math.gcd(P, M)
            return tx * ty // math.gcd(tx, ty)
        if t0 > 0:
            return t0
        return p

    Q1 = Q // gq
    ax1 = ax // gq
    inv = pow(Q1, -1, N1)
    t0 = (ax1 * inv) % N1
    p1 = N1

    Pt0 = (P * t0) % M
    A = (P * p1) % M
    B = (ay - Pt0) % M

    if A == 0:
        if B != 0:
            return None
        if p1 == 0:
            return None if t0 <= 0 else t0
        if t0 > 0:
            return t0
        return p1

    s2 = solve_lin(A, B, M)
    if s2 is None:
        return None
    k0, p2 = s2
    if p2 == 0:
        if t0 > 0:
            return t0
        return p1 if p1 > 0 else None

    t = t0 + p1 * k0
    if t > 0:
        return t
    step = p1 * p2
    if t == 0:
        if step == 0:
            return None
        return step
    if step == 0:
        return None
    j = (1 - t + step - 1) // step
    return t + j * step


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        K = int(next(it))
        N = int(next(it))
        M = int(next(it))
        P = int(next(it))
        Q = int(next(it))
        pts = []
        for _i in range(K):
            X = int(next(it))
            Y = int(next(it))
            pts.append((X, Y))
        X0, Y0 = pts[0]
        best_t = None
        best_i = None
        for i in range(K):
            Xi, Yi = pts[i]
            mt = min_t_hit(X0, Y0, P, Q, N, M, Xi, Yi)
            if mt is None:
                continue
            if best_t is None or mt < best_t or (mt == best_t and i < best_i):
                best_t, best_i = mt, i
        out.append(str(best_i))
    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
