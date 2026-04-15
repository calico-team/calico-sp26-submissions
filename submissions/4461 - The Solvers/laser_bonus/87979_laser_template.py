def mod_inv(a, m):
    # Extended Euclidean Algorithm
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        a, m = m, a % m
        x0, x1 = x1 - q * x0, x0
    return x1 % m0


def solve(K, N, M, P, Q, X, Y):
    x0, y0 = X[0], Y[0]

    best_t = float('inf')
    ans = 0

    invQ = mod_inv(Q, N) 

    for i in range(K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M

        t = (dx * invQ) % N

        if (t * P) % M != dy:
            continue

        if t == 0:
            continue

        if t < best_t:
            best_t = t
            ans = i

    return ans


def main():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())

        X = []
        Y = []
        for _ in range(K):
            x, y = map(int, input().split())
            X.append(x)
            Y.append(y)

        print(solve(K, N, M, P, Q, X, Y))


if __name__ == "__main__":
    main()