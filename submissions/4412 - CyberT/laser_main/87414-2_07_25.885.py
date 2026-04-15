import sys
def solve():
    import sys
    input = sys.stdin.readline
    def extended_gcd(a, b):
        if b == 0:
            return (a, 1, 0)
        g, x, y = extended_gcd(b, a % b)
        return (g, y, x - (a // b) * y)
    def modinv(a, m):
        g, x, y = extended_gcd(a, m)
        return x % m
    def crt(a1, m1, a2, m2):
        g, x, y = extended_gcd(m1, m2)
        if (a2 - a1) % g != 0:
            return None, None
        lcm = m1 // g * m2
        t = (a1 + (a2 - a1) // g * x % (m2 // g) * m1) % lcm
        return t, lcm
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        asteroids = [tuple(map(int, input().split())) for _ in range(K)]
        x0, y0 = asteroids[0]
        answer_step = None
        answer_index = 0
        import math
        for i in range(K):
            xi, yi = asteroids[i]
            dif_x = (xi - x0) % N
            dif_y = (yi - y0) % M
            g1 = math.gcd(Q, N)
            if dif_x % g1 != 0:
                continue
            mod_x = N // g1
            inv_q = modinv(Q // g1, mod_x)
            step_x = (dif_x // g1 * inv_q) % mod_x
            g2 = math.gcd(P, M)
            if dif_y % g2 != 0:
                continue
            mod_y = M // g2
            inv_p = modinv(P // g2, mod_y)
            step_y = (dif_y // g2 * inv_p) % mod_y
            t, lcm = crt(step_x, mod_x, step_y, mod_y)
            if t is None:
                continue
            if t == 0:
                if i == 0:
                    t = lcm
                else:
                    continue
            if answer_step is None or t < answer_step:
                answer_step = t
                answer_index = i
        print(answer_index)
def read_your_input():
    solve()
if __name__ == "__main__":
    read_your_input()