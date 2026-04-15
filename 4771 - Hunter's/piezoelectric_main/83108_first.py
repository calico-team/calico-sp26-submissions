def read_input():
    try:
        T = int(input().strip())
    except:
        return

    for _ in range(T):
        L, W, E, R = map(int, input().split())

        triangle_area = 2 * (L + W)
        energy_per_lap = triangle_area * R
        laps = E // energy_per_lap

        print(laps)

if __name__ == "__main__":
    read_input()