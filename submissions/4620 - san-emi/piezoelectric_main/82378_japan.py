T = int(input())

for _ in range(T):
    L, W, E, R = map(int, input().split())
    perimeter = 2 * (L + W)
    energy_lap = perimeter * R
    laps = E // energy_lap
    print(laps)