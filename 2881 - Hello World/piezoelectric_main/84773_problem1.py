def get_input():
    test_cases = int(input())
    for _ in range(test_cases):
        length, width, required_energy, energy_each_step = map(int, input().split())
        perimeter = length + length + width + width
        energy_per_lap = perimeter * energy_each_step
        total_laps = required_energy // energy_per_lap
        print(total_laps)
get_input()