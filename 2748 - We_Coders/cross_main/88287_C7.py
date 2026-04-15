import sys


def solve():
    garden_stream = sys.stdin.read().split()
    if not garden_stream:
        return

    flower_tests = int(garden_stream[0])
    rose_index = 1
    garden_output = []

    garden_pattern = [0, 1, 2, 3, 4]

    for _ in range(flower_tests):
        garden_rows = int(garden_stream[rose_index])
        garden_cols = int(garden_stream[rose_index + 1])
        rose_index += 2

        for i in range(garden_rows):
            garden_row = []

            for j in range(garden_cols):
                garden_value = garden_pattern[(i + j) % 5]
                garden_row.append(str(garden_value))

            garden_output.append(" ".join(garden_row))

    sys.stdout.write("\n".join(garden_output))


if __name__ == "__main__":
    solve()