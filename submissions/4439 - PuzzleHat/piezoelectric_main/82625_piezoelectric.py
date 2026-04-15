def solve(L, W, E, R):
    perimeter = 2 * (L + W)
    electricity_per_lap = perimeter * R
    laps = E // electricity_per_lap
    return laps

T = int(input())
for _ in range(T):
    L, W, E, R = map(int, input().split())
    print(solve(L, W, E, R))