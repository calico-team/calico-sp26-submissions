from math import gcd

def find_gcd_extended(num1, num2):
    if num2 == 0:
        return num1, 1, 0
    common, coeff1, coeff2 = find_gcd_extended(num2, num1 % num2)
    return common, coeff2, coeff1 - (num1 // num2) * coeff2

def crack_congruence(slope, target, cycle):
    common, inverse, _ = find_gcd_extended(slope % cycle, cycle)
    if target % common != 0:
        return None
    reduced_cycle = cycle // common
    answer = (inverse * (target // common)) % reduced_cycle
    return answer, reduced_cycle

def merge_remainders(rem1, cycle1, rem2, cycle2):
    common, inverse, _ = find_gcd_extended(cycle1, cycle2)
    if (rem2 - rem1) % common != 0:
        return None
    new_cycle = cycle1 // common * cycle2
    new_rem = (rem1 + cycle1 * ((rem2 - rem1) // common * inverse % (cycle2 // common))) % new_cycle
    return new_rem, new_cycle

total_cases = int(input())

for _ in range(total_cases):
    num_targets, map_width, map_height, vertical_step, horizontal_step = map(int, input().split())

    space_rocks = []
    for i in range(num_targets):
        rock_x, rock_y = map(int, input().split())
        space_rocks.append((rock_x, rock_y))

    home_x, home_y = space_rocks[0]
    lazarbeam = None
    best_time = None
    winner_idx = None

    for position, (rock_x, rock_y) in enumerate(space_rocks):
        needed_x = (rock_x - home_x) % map_width
        needed_y = (rock_y - home_y) % map_height

        attempt_x = crack_congruence(horizontal_step, needed_x, map_width)
        if attempt_x is None:
            continue
        time_x, period_x = attempt_x

        attempt_y = crack_congruence(vertical_step, needed_y, map_height)
        if attempt_y is None:
            continue
        time_y, period_y = attempt_y

        combined = merge_remainders(time_x, period_x, time_y, period_y)
        if combined is None:
            continue

        hit_time, full_period = combined

        if hit_time == 0:
            hit_time = full_period

        if best_time is None or hit_time < best_time:
            best_time = hit_time
            winner_idx = position

    print(winner_idx)

def read_your_input():
    return map(int, input().split())