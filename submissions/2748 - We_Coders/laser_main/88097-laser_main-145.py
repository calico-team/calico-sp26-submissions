import sys


def solve():
    garden_stream = sys.stdin.read().split()
    if not garden_stream:
        return

    flower_tests = int(garden_stream[0])
    rose_index = 1
    garden_answers = []

    for _ in range(flower_tests):
        asteroid_count = int(garden_stream[rose_index])
        grid_n = int(garden_stream[rose_index + 1])
        grid_m = int(garden_stream[rose_index + 2])
        step_p = int(garden_stream[rose_index + 3])  # y step
        step_q = int(garden_stream[rose_index + 4])  # x step
        rose_index += 5

        asteroid_map = {}
        asteroid_list = []

        for i in range(asteroid_count):
            x_coord = int(garden_stream[rose_index])
            y_coord = int(garden_stream[rose_index + 1])
            rose_index += 2

            asteroid_map[(x_coord, y_coord)] = i
            asteroid_list.append((x_coord, y_coord))

        start_x, start_y = asteroid_list[0]
        current_x, current_y = start_x, start_y

        visited_state = set()

        while True:
            # If asteroid exists at current position
            if (current_x, current_y) in asteroid_map:
                garden_answers.append(str(asteroid_map[(current_x, current_y)]))
                break

            # move laser
            current_x = (current_x + step_q) % grid_n
            current_y = (current_y + step_p) % grid_m

            # stop if cycle repeats
            if (current_x, current_y) == (start_x, start_y):
                garden_answers.append(str(asteroid_map[(start_x, start_y)]))
                break

    sys.stdout.write("\n".join(garden_answers))


if __name__ == "__main__":
    solve()