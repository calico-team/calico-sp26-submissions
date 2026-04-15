def solve(K, N, M, P, Q, X, Y):
    """
    Find the index of the first asteroid hit by the laser.

    K: Number of asteroids
    N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """
    def extended_gcd(a, b):
        if a == 0:
            return b, 0, 1
        g, x1, y1 = extended_gcd(b % a, a)
        return g, y1 - (b // a) * x1, x1

    def normalize(value, modulus):
        return value % modulus

    def solve_congruence(step, modulus, offset):
        g, inv_step, _ = extended_gcd(step, modulus)
        if offset % g != 0:
            return None, None
        period = modulus // g
        remainder = normalize(inv_step * (offset // g), period)
        return remainder, period

    def crt(r1, m1, r2, m2):
        g, inv_m1, _ = extended_gcd(m1, m2)
        if (r2 - r1) % g != 0:
            return None, None
        step = normalize(inv_m1 * ((r2 - r1) // g), m2 // g)
        result = normalize(r1 + step * m1, m1 // g * m2)
        return result, m1 // g * m2

    start_x, start_y = X[0], Y[0]
    best_index = -1
    best_time = float('inf')

    for i in range(K):
        offset_x = normalize(X[i] - start_x, N)
        offset_y = normalize(Y[i] - start_y, M)

        time_x, cycle_x = solve_congruence(Q, N, offset_x)
        if time_x is None:
            continue

        time_y, cycle_y = solve_congruence(P, M, offset_y)
        if time_y is None:
            continue

        combined_time, full_period = crt(time_x, cycle_x, time_y, cycle_y)
        if combined_time is None:
            continue

        if combined_time == 0:
            combined_time = full_period

        if combined_time < best_time:
            best_time = combined_time
            best_index = i

    return best_index


def main():
    test_case_count = int(input())
    for _ in range(test_case_count):
        header = input().split()
        num_asteroids = int(header[0])
        grid_n = int(header[1])
        grid_m = int(header[2])
        jump_p = int(header[3])
        jump_q = int(header[4])

        asteroid_x = []
        asteroid_y = []
        for _ in range(num_asteroids):
            coords = input().split()
            asteroid_x.append(int(coords[0]))
            asteroid_y.append(int(coords[1]))

        print(solve(num_asteroids, grid_n, grid_m, jump_p, jump_q, asteroid_x, asteroid_y))


if __name__ == '__main__':
    main()