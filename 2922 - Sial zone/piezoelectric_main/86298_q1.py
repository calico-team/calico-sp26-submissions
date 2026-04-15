T = int(input("Input: "))

for i in range(T):
    L, W, E, R = map(int, input().split())
    perimeter = 2 * (L + W)
    energy_per_lap = perimeter * R
    laps = E // energy_per_lap
    print(laps)