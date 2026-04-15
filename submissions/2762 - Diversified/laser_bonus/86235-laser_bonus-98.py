def solve(K, N, M, P, Q, X, Y):
    """
    Find the index of the first asteroid hit by the laser.

    K: Number of asteroids
    N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """
    from math import gcd

    def egcd(a, b):
        if b == 0:
            return a, 1, 0
        g, x, y = egcd(b, a % b)
        return g, y, x - (a // b) * y

    def inv(a, mod):
        g, x, _ = egcd(a, mod)
        if g != 1:
            return None
        return x % mod

    pos = {}
    for i in range(K):
        pos[(X[i], Y[i])] = i

    x0, y0 = X[0], Y[0]
    best = -1
    best_t = float("inf")

    for i in range(1, K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M

        g1 = gcd(Q, N)
        if dx % g1 != 0:
            continue
        n1 = N // g1
        q1 = Q // g1
        dx1 = dx // g1

        g2 = gcd(P, M)
        if dy % g2 != 0:
            continue
        m1 = M // g2
        p1 = P // g2
        dy1 = dy // g2

        iq = inv(q1, n1)
        ip = inv(p1, m1)
        if iq is None or ip is None:
            continue

        t1 = (dx1 * iq) % n1
        t2 = (dy1 * ip) % m1

        g = gcd(n1, m1)
        if (t2 - t1) % g != 0:
            continue

        lcm = n1 * m1 // g
        inv_n = inv(n1 // g, m1 // g)
        if inv_n is None:
            continue

        t = (t1 + ((t2 - t1) // g) * inv_n % (m1 // g) * n1) % lcm

        if t > 0 and t < best_t:
            best_t = t
            best = i

    return best

def main():
    T = int(input())

    for _ in range(T):
        line = input().split()
        K = int(line[0])
        N = int(line[1])
        M = int(line[2])
        P = int(line[3])
        Q = int(line[4])

        X = []
        Y = []
        for _ in range(K):
            coords = input().split()
            a_i = int(coords[0])
            b_i = int(coords[1])
            X.append(a_i)
            Y.append(b_i)

        print(solve(K, N, M, P, Q, X, Y))


if __name__ == '__main__':
    main()