import math
import sys


def ints_from_stdin():
    data = sys.stdin.buffer.read()
    num = 0
    sign = 1
    in_num = False

    for b in data:
        if 48 <= b <= 57:
            num = num * 10 + (b - 48)
            in_num = True
        elif b == 45:
            sign = -1
        else:
            if in_num:
                yield sign * num
                num = 0
                sign = 1
                in_num = False

    if in_num:
        yield sign * num


def combine_congruences(r1, m1, r2, m2):
    g = math.gcd(m1, m2)
    diff = r2 - r1

    if diff % g != 0:
        return None, None

    m1_reduced = m1 // g
    m2_reduced = m2 // g

    if m2_reduced == 1:
        k = 0
    else:
        inv = pow(m1_reduced, -1, m2_reduced)
        k = (diff // g) * inv % m2_reduced

    modulus = m1 * m2_reduced
    value = (r1 + m1 * k) % modulus
    return value, modulus


def first_hit_index(k, n, m, p, q, asteroids):
    x0, y0 = asteroids[0]

    gx = math.gcd(q, n)
    gy = math.gcd(p, m)

    x_period = n // gx
    y_period = m // gy

    inv_q = 0 if x_period == 1 else pow(q // gx, -1, x_period)
    inv_p = 0 if y_period == 1 else pow(p // gy, -1, y_period)

    period = x_period // math.gcd(x_period, y_period) * y_period

    best_index = 0
    best_time = period

    for idx, (x, y) in enumerate(asteroids):
        dx = x - x0
        dy = y - y0

        if dx % gx != 0 or dy % gy != 0:
            continue

        tx = 0 if x_period == 1 else ((dx // gx) * inv_q) % x_period
        ty = 0 if y_period == 1 else ((dy // gy) * inv_p) % y_period

        t0, step = combine_congruences(tx, x_period, ty, y_period)
        if t0 is None:
            continue

        # The initial position at t = 0 does not count as a hit.
        hit_time = step if t0 == 0 else t0

        if hit_time < best_time or (hit_time == best_time and idx < best_index):
            best_time = hit_time
            best_index = idx

    return best_index


def main():
    it = iter(ints_from_stdin())

    try:
        t = next(it)
    except StopIteration:
        return

    out = []

    for _ in range(t):
        k = next(it)
        n = next(it)
        m = next(it)
        p = next(it)
        q = next(it)

        asteroids = [(next(it), next(it)) for _ in range(k)]

        out.append(str(first_hit_index(k, n, m, p, q, asteroids)))

    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
