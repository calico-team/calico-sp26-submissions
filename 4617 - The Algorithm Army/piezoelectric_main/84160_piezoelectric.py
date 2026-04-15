def main():
    T = int(input())
    for _ in range(T):
        L, W, E, R = map(int, input().split())
        perimeter_area = 2 * (L + W)
        electricity_per_lap = perimeter_area * R
        laps = E // electricity_per_lap
        print(laps)
main()