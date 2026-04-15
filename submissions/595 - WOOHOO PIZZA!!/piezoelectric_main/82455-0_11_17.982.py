import sys
inp = [line.strip() for line in sys.stdin]

for line in inp[1:]:
    L, W, E, R = map(int, line.split())

    laps = 0
    elec = 0
    while elec < E:
        elec += (2*L + 2*W) * R
        laps += 1
    print(laps)

