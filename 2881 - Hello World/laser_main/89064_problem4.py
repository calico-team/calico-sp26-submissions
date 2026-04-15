def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    gcd_value, x1, y1 = extended_gcd(b, a % b)
    return gcd_value, y1, x1 - (a // b) * y1
def mod_inverse(value, mod):
    gcd_value, x, _ = extended_gcd(value, mod)
    if gcd_value != 1:
        return None
    return x % mod
def combine_congruences(a1, m1, a2, m2):
    gcd_value, x, _ = extended_gcd(m1, m2)
    difference = a2 - a1
    if difference % gcd_value != 0:
        return None, None
    step = m2 // gcd_value
    move = (difference // gcd_value * x) % step
    merged_mod = m1 // gcd_value * m2
    merged_value = (a1 + m1 * move) % merged_mod
    return merged_value, merged_mod
def first_time_to_hit(start_x, start_y, asteroid_x, asteroid_y, width, height, move_y, move_x):
    dx = (asteroid_x - start_x) % width
    dy = (asteroid_y - start_y) % height
    gcd_x = __import__("math").gcd(move_x, width)
    if dx % gcd_x != 0:
        return None
    gcd_y = __import__("math").gcd(move_y, height)
    if dy % gcd_y != 0:
        return None
    reduced_move_x = move_x // gcd_x
    reduced_width = width // gcd_x
    reduced_dx = dx // gcd_x
    time_x = (reduced_dx * mod_inverse(reduced_move_x, reduced_width)) % reduced_width
    reduced_move_y = move_y // gcd_y
    reduced_height = height // gcd_y
    reduced_dy = dy // gcd_y
    time_y = (reduced_dy * mod_inverse(reduced_move_y, reduced_height)) % reduced_height
    hit_time, cycle_length = combine_congruences(time_x, reduced_width, time_y, reduced_height)
    if hit_time is None:
        return None
    if hit_time == 0:
        hit_time = cycle_length
    return hit_time
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
        best_time = None
        lazarbeam = 0
        for index, (asteroid_x, asteroid_y) in enumerate(asteroids):
            hit_time = first_time_to_hit(start_x, start_y, asteroid_x, asteroid_y, width, height, move_y, move_x)
            if hit_time is None:
                continue
            if best_time is None or hit_time < best_time:
                best_time = hit_time
                best_index = index
                lazarbeam = hit_time
        print(best_index)
def read_input():
    solve()
read_input()