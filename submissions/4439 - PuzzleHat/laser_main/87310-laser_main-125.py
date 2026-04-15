from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def mod_inverse(a, m):
    _, x, _ = extended_gcd(a % m, m)
    return x % m

def solve_main(k, n, m, p, q, asteroids):
    sx, sy = asteroids[0]
    amap = {}
    for i in range(1, k):
        xi, yi = asteroids[i]
        if (xi, yi) not in amap:
            amap[(xi, yi)] = i

    x, y = sx, sy
    seen = set()
    while True:
        x = (x + q) % n
        y = (y + p) % m
        state = (x, y)
        if state in seen:
            return 0
        seen.add(state)
        if state in amap:
            return amap[state]

def solve_bonus(k, n, m, p, q, asteroids):
    lazarbeam = {}
    sx, sy = asteroids[0]

    for i in range(1, k):
        xi, yi = asteroids[i]
        dx = (xi - sx) % n
        dy = (yi - sy) % m

        gq = gcd(q, n)
        if dx % gq != 0:
            continue
        n2 = n // gq
        q2 = q // gq
        dx2 = dx // gq
        inv_q2 = mod_inverse(q2, n2)
        tx = (dx2 * inv_q2) % n2
        period_x = n2

        gp = gcd(p, m)
        if dy % gp != 0:
            continue
        m2 = m // gp
        p2 = p // gp
        dy2 = dy // gp
        inv_p2 = mod_inverse(p2, m2)
        ty = (dy2 * inv_p2) % m2
        period_y = m2

        g = gcd(period_x, period_y)
        if (ty - tx) % g != 0:
            continue
        lcm_xy = period_x * period_y // g
        inv_px = mod_inverse(period_x // g, period_y // g)
        t = tx + period_x * (((ty - tx) // g % (period_y // g)) * inv_px % (period_y // g))
        t = t % lcm_xy
        if t == 0:
            t = lcm_xy

        if i not in lazarbeam or t < lazarbeam[i]:
            lazarbeam[i] = t

    if not lazarbeam:
        return 0

    best = min(lazarbeam, key=lazarbeam.get)
    return best

def read_your_input():
    t = int(input())
    for _ in range(t):
        k, n, m, p, q = map(int, input().split())
        asteroids = []
        for _ in range(k):
            x, y = map(int, input().split())
            asteroids.append((x, y))
        if k <= 100 and n <= 1000 and m <= 1000:
            print(solve_main(k, n, m, p, q, asteroids))
        else:
            print(solve_bonus(k, n, m, p, q, asteroids))

read_your_input()
