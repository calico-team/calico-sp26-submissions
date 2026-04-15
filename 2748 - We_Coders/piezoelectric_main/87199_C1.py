import sys


def solve():
    garden_data = sys.stdin.read().strip().split()
    if not garden_data:
        return

    total_cases = int(garden_data[0])
    flower_index = 1
    answers = []

    for _ in range(total_cases):
        garden_length = int(garden_data[flower_index])
        garden_width = int(garden_data[flower_index + 1])
        needed_flowers = int(garden_data[flower_index + 2])
        flowers_per_step = int(garden_data[flower_index + 3])
        flower_index += 4

        garden_boundary = 2 * (garden_length + garden_width)
        flowers_per_round = garden_boundary * flowers_per_step

        rounds_needed = needed_flowers // flowers_per_round

        answers.append(str(rounds_needed))

    sys.stdout.write("\n".join(answers))


if __name__ == "__main__":
    solve()