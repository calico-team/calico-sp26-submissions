import sys


def solve():
    garden_stream = sys.stdin.read().split()
    if not garden_stream:
        return

    flower_beds = int(garden_stream[0])
    rose_pointer = 1
    garden_results = []

    for _ in range(flower_beds):
        tree_count = int(garden_stream[rose_pointer])
        rose_pointer += 1

        top_tower = []

        for _ in range(tree_count):
            plant_height = garden_stream[rose_pointer]
            rose_pointer += 1
            top_tower.append(plant_height)

        # Optimal bottom tower: same as top tower
        garden_results.append(" ".join(top_tower))

    sys.stdout.write("\n".join(garden_results))


if __name__ == "__main__":
    solve()