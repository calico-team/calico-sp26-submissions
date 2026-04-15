from math import gcd


def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0

    gcd_value, coefficient_a, coefficient_b = extended_gcd(b, a % b)

    return gcd_value, coefficient_b, coefficient_a - (a // b) * coefficient_b


def time_to_hit_target(laser_start_x, laser_start_y,
                       target_x, target_y,
                       grid_width, grid_height,
                       step_move_right, step_move_up):

    horizontal_distance = (target_x - laser_start_x) % grid_width
    vertical_distance = (target_y - laser_start_y) % grid_height

    gcd_horizontal, inverse_step_right, _ = extended_gcd(step_move_right % grid_width, grid_width)

    if horizontal_distance % gcd_horizontal != 0:
        return 10**18

    time_along_x = (horizontal_distance // gcd_horizontal * inverse_step_right) % (grid_width // gcd_horizontal)
    cycle_length_x = grid_width // gcd_horizontal

    gcd_vertical, inverse_step_up, _ = extended_gcd(step_move_up % grid_height, grid_height)

    if vertical_distance % gcd_vertical != 0:
        return 10**18

    time_along_y = (vertical_distance // gcd_vertical * inverse_step_up) % (grid_height // gcd_vertical)
    cycle_length_y = grid_height // gcd_vertical

    common_cycle_gcd = gcd(cycle_length_x, cycle_length_y)

    if (time_along_x - time_along_y) % common_cycle_gcd != 0:
        return 10**18

    full_cycle_time = cycle_length_x * cycle_length_y // common_cycle_gcd

    current_time = time_along_x % full_cycle_time

    while current_time % cycle_length_y != time_along_y % cycle_length_y:
        current_time += cycle_length_x
        if current_time > full_cycle_time:
            return 10**18

    if current_time == 0:
        current_time = full_cycle_time

    return current_time


total_scenarios = int(input())

for scenario in range(total_scenarios):

    number_of_asteroids, world_width, world_height, vertical_step, horizontal_step = map(int, input().split())

    asteroid_coordinates = []

    for _ in range(number_of_asteroids):
        position_x, position_y = map(int, input().split())
        asteroid_coordinates.append((position_x, position_y))

    laser_start_x = asteroid_coordinates[0][0]
    laser_start_y = asteroid_coordinates[0][1]

    full_cycle_time = world_width * world_height // gcd(world_width, world_height)

    best_time_to_hit = 10**18
    asteroid_index_hit_first = -1

    index = 0
    while index < len(asteroid_coordinates):

        target_x = asteroid_coordinates[index][0]
        target_y = asteroid_coordinates[index][1]

        if index == 0:
            time_required = full_cycle_time
        else:
            time_required = time_to_hit_target(
                laser_start_x, laser_start_y,
                target_x, target_y,
                world_width, world_height,
                horizontal_step, vertical_step
            )

        if time_required < best_time_to_hit:
            best_time_to_hit = time_required
            asteroid_index_hit_first = index

        index += 1

    print(asteroid_index_hit_first)