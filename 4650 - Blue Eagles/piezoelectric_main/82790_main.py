t = int(input())
for _ in range(t):
    l, w, e ,r = map(int, input().split())
    perimeter = 2 * (l + w)
    energy_per_lap = perimeter * r
    laps = e // energy_per_lap
    print(laps)