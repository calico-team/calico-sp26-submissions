def calculate_laps(L, W, E, R):
    return E // (2 * (L + W) * R)



t = int(input())

for _ in range(t):
    L, W, E, R = map(int, input().split())
    print(calculate_laps(L, W, E, R))