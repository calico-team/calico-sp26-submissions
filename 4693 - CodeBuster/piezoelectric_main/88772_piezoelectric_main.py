T = int(input())
    
for _ in range(T):
    L, W, E, R = map(int, input().split())
    # print(L, W, E, R)
    perameter = 2 * (L + W)
    # print(perameter)
    energy_per_lap = R * perameter
    # print(energy_per_lap)
    laps = E // energy_per_lap
    print(laps)