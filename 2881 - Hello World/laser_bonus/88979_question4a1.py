from math import gcd
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1
def modular_inverse(number, mod):
    g, x, _ = extended_gcd(number, mod)
    if g != 1:
        return None
    return x % mod
def merge_equations(remainder1, mod1, remainder2, mod2):
    g, x, _ = extended_gcd(mod1, mod2)
    difference = remainder2 - remainder1
    if difference % g != 0:
        return None, None
    step = mod2 // g
    shift = (difference // g * x) % step
    combined_mod = mod1 // g * mod2
    combined_remainder = (remainder1 + mod1 * shift) % combined_mod
    return combined_remainder, combined_mod
def get_hit_time(start_x, start_y, target_x, target_y, width, height, move_y, move_x):
    x_gap = (target_x - start_x) % width
    y_gap = (target_y - start_y) % height
    x_gcd = gcd(move_x, width)
    if x_gap % x_gcd != 0:
        return None
    y_gcd = gcd(move_y, height)
    if y_gap % y_gcd != 0:
        return None
    reduced_move_x = move_x // x_gcd
    reduced_width = width // x_gcd
    reduced_x_gap = x_gap // x_gcd
    x_time = (reduced_x_gap * modular_inverse(reduced_move_x, reduced_width)) % reduced_width
    reduced_move_y = move_y // y_gcd
    reduced_height = height // y_gcd
    reduced_y_gap = y_gap // y_gcd
    y_time = (reduced_y_gap * modular_inverse(reduced_move_y, reduced_height)) % reduced_height
    first_time, cycle_length = merge_equations(x_time, reduced_width, y_time, reduced_height)
    if first_time is None:
        return None
    if first_time == 0:
        first_time = cycle_length
    return first_time
def solve():
    test_cases = int(input())
    for _ in range(test_cases):
        asteroid_count, width, height, move_y, move_x = map(int, input().split())
        asteroids = []
        for _ in range(asteroid_count):
            x, y = map(int, input().split())
            asteroids.append((x, y))
        start_x, start_y = asteroids[0]
        best_index = 0
        lazarbeam = None
        for index, (target_x, target_y) in enumerate(asteroids):
            hit_time = get_hit_time(start_x, start_y, target_x, target_y, width, height, move_y, move_x)
            if hit_time is None:
                continue
            if lazarbeam is None or hit_time < lazarbeam:
                lazarbeam = hit_time
                best_index = index
        print(best_index)
def read_your_input():
    solve()
read_your_input()