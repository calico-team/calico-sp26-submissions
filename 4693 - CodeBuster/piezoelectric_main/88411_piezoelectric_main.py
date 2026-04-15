with open("1.in", "r") as f:
    T = f.readlines()
    
for i in range(int(T[0])):
    L, W, E, R = map(int, T[i + 1].split())
    # print(L, W, E, R)
    perameter = 2 * (L + W)
    # print(perameter)
    energy_per_lap = R * perameter
    # print(energy_per_lap)
    laps = E // energy_per_lap
    print(laps)