def egcd(a, b):
    if b == 0:
        return (1, 0, a)
    x, y, g = egcd(b, a % b)
    return (y, x - (a // b) * y, g)

def crt(a1, m1, a2, m2):
    x, y, g = egcd(m1, m2)

    if (a2 - a1) % g != 0:
        return (-1, -1)  # no solution

    lcm = m1 // g * m2

    t = ((a2 - a1) // g * x) % (m2 // g)
    res = (a1 + m1 * t) % lcm

    return (res, lcm)


def solve(K, N, M, P, Q, X, Y):
    """
    Find the index of the first asteroid hit by the laser.

    K: Number of asteroids
    N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """
    o1, o2 = egcd(N, Q)[2], egcd(M, P)[2]
    N //= o1
    M //= o2
    Q //= o1
    P //= o2
    b = N*M
    res = -1
    s = X[0], Y[0]
    Xt, Yt, idx = [], [], []
    for i in range(K):
        X[i] -= s[0]
        Y[i] -= s[1]
        if X[i] % o1 or Y[i] % o2:
            continue
        Xt.append(((X[i] - Q) * pow(Q, -1, N)) % N)
        Yt.append(((Y[i] - P) * pow(P, -1, M)) % M)
        idx.append(i)
    for i in range(len(Xt)):
        a = crt(Xt[i], N, Yt[i], M)[0]
        # print((X[i] - P), (Y[i] - Q), Xt[i], Yt[i])
        # print("a", a)
        if a>0 and a < b:
            b = a
            res = idx[i]
    # print()
    return res


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