import sys
import math

def solve():
    def get_tokens():
        for line in sys.stdin:
            for token in line.split():
                yield token

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

        x0 = int(next(tokens))
        y0 = int(next(tokens))

        gx = math.gcd(Q, N)
        nx = N // gx
        q_inv_nx = pow((Q // gx) % nx, -1, nx) if nx > 1 else 0

        gy = math.gcd(P, M)
        my = M // gy
        p_inv_my = pow((P // gy) % my, -1, my) if my > 1 else 0

        gxy = math.gcd(nx, my)
        m_prime = my // gxy
        nx_inv = pow((nx // gxy) % m_prime, -1, m_prime) if m_prime > 1 else 0

        L = nx * m_prime

        min_t = L
        best_idx = 0

        for i in range(1, K):
            x = int(next(tokens))
            y = int(next(tokens))

            dx = (x - x0) % N
            dy = (y - y0) % M

            if dx % gx != 0 or dy % gy != 0:
                continue

            tx = ((dx // gx) * q_inv_nx) % nx if nx > 1 else 0
            ty = ((dy // gy) * p_inv_my) % my if my > 1 else 0

            if (ty - tx) % gxy != 0:
                continue

            k = (((ty - tx) // gxy) * nx_inv) % m_prime if m_prime > 1 else 0

            t = tx + k * nx
            t = t % L

            if t == 0:
                t = L

            if t < min_t:
                min_t = t
                best_idx = i

        print(best_idx)

if __name__ == '__main__':
    solve()