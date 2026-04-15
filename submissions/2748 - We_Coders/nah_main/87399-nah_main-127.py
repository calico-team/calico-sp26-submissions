import sys


def solve():
    garden_stream = sys.stdin.buffer.read().split()
    if not garden_stream:
        return

    flower_it = iter(garden_stream)
    total_gardens = int(next(flower_it))
    final_blooms = []

    for _ in range(total_gardens):
        total_plants = int(next(flower_it))
        garden_energy = int(next(flower_it))
        sunlight_restore = int(next(flower_it))
        bloom_limit = int(next(flower_it))

        plant_powers = [int(next(flower_it)) for _ in range(total_plants)]

        bloomed_count = 0
        garden_alive = True

        for plant_power in plant_powers:
            # Not enough energy to defeat plant
            if garden_energy < plant_power:
                garden_alive = False
                break

            # Defeat plant
            garden_energy -= plant_power
            bloomed_count += 1

            # Restore energy after K defeats
            if bloomed_count == bloom_limit:
                garden_energy += sunlight_restore
                bloomed_count = 0

        if garden_alive:
            final_blooms.append("nah i’d win")
        else:
            final_blooms.append("nah i’d lose")

    sys.stdout.write("\n".join(final_blooms))


if __name__ == "__main__":
    solve()