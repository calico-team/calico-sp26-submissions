import sys

def get_tokens():
    for line in sys.stdin:
        for token in line.split():
            yield token

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def safe_inv(val, mod):
    if mod <= 1:
        return 0
    return pow(val % mod, -1, mod)

def solve():
    tokens = get_tokens()

    try:
        T_str = next(tokens)
    except StopIteration:
        return
    T = int(T_str)

    for _ in range(T):
        K = int(next(tokens))
        N = int(next(tokens))
        M = int(next(tokens))
        P = int(next(tokens))
        Q = int(next(tokens))

        X0 = int(next(tokens))
        Y0 = int(next(tokens))

        gx = gcd(Q, N)
        gy = gcd(P, M)

        q_prime = Q // gx if gx else 0
        n_prime = N // gx if gx else 1

        p_prime = P // gy if gy else 0
        m_prime = M // gy if gy else 1

        inv_q = safe_inv(q_prime, n_prime)
        inv_p = safe_inv(p_prime, m_prime)

        g_nm = gcd(n_prime, m_prime)
        L = (n_prime // g_nm) * m_prime

        def get_time(dx, dy):
            if dx % gx != 0 or dy % gy != 0:
                return float('inf')

            x_prime = dx // gx
            y_prime = dy // gy

            a = (x_prime * inv_q) % n_prime
            b = (y_prime * inv_p) % m_prime

            diff = b - a
            if diff % g_nm != 0:
                return float('inf')

            c = diff // g_nm
            n_double_prime = n_prime // g_nm
            m_double_prime = m_prime // g_nm

            inv_n = safe_inv(n_double_prime, m_double_prime)
            k = (c * inv_n) % m_double_prime

            t = a + k * n_prime
            t %= L

            if t == 0:
                t = L

            return t

        best_t = get_time(0, 0)
        best_idx = 0

        for i in range(1, K):
            Xi = int(next(tokens))
            Yi = int(next(tokens))

            dx = (Xi - X0) % N
            dy = (Yi - Y0) % M

            t = get_time(dx, dy)

            if t < best_t:
                best_t = t
                best_idx = i

        print(best_idx)

if __name__ == '__main__':
    solve()