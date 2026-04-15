import sys


def solve():
    garden_stream = sys.stdin.read().splitlines()
    if not garden_stream:
        return

    flower_cases = int(garden_stream[0].strip())
    blossom_index = 1
    garden_results = []

    for _ in range(flower_cases):
        garden_a = garden_stream[blossom_index].strip()
        garden_b = garden_stream[blossom_index + 1].strip()
        blossom_index += 2

        rose_pointer = 0
        rose_length = len(garden_b)

        garden_output = []

        for petal in garden_a:
            if rose_pointer < rose_length and petal == garden_b[rose_pointer]:
                garden_output.append(petal)
                rose_pointer += 1
            else:
                garden_output.append('#')

        garden_results.append("".join(garden_output))

    sys.stdout.write("\n".join(garden_results))


if __name__ == "__main__":
    solve()