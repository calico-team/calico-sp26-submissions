import sys
import math
from io import StringIO


# -------------------- SAMPLE INPUT --------------------
input_data = """\
4
3 10 10 1 1
0 0
2 2
9 9
3 6 8 2 1
1 1
1 5
5 1
3 6 8 2 1
1 1
2 3
4 4
3 5 5 2 3
2 2
0 0
1 4
"""

sys.stdin = StringIO(input_data)
# ------------------------------------------------------


# ---------- Extended GCD ----------
def egcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = egcd(b, a % b)
    return g, y, x - (a // b) * y


# ---------- Modular inverse ----------
def mod_inv(a, m):
    g, x, _ = egcd(a, m)
    return x % m


# ---------- Solve: a * t ≡ b (mod mod) ----------
def solve(a, b, mod):
    g = math.gcd(a, mod)

    if b % g != 0:
        return None

    a //= g
    b //= g
    mod //= g

    inv = mod_inv(a % mod, mod)
    return (inv * b) % mod, mod


# ---------- Merge two congruences using CRT ----------
def crt(a1, m1, a2, m2):
    g = math.gcd(m1, m2)

    if (a2 - a1) % g != 0:
        return None

    m1 //= g
    m2 //= g

    _, s, _ = egcd(m1, m2)

    lcm = m1 * m2 * g
    t = (a1 + (a2 - a1) // g * s % m2 * (m1 * g)) % lcm

    return t, lcm


# ---------- Main logic ----------
def main():
    T = int(input())

    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        asteroids = [tuple(map(int, input().split())) for _ in range(K)]

        start_x, start_y = asteroids[0]

        best_time = float("inf")
        answer = -1

        for i, (x, y) in enumerate(asteroids):

            dx = (x - start_x) % N
            dy = (y - start_y) % M

            x_res = solve(Q, dx, N)
            y_res = solve(P, dy, M)

            if x_res is None or y_res is None:
                continue

            tx, mx = x_res
            ty, my = y_res

            merged = crt(tx, mx, ty, my)
            if merged is None:
                continue

            t, cycle = merged

            # ensure first asteroid is not counted at time 0
            if i == 0 and t == 0:
                t = cycle

            if t < best_time or (t == best_time and i < answer):
                best_time = t
                answer = i

        print(answer)


if __name__ == "__main__":
    main()