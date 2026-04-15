def read_your_input():
    import sys
    return sys.stdin.read().strip().split()

data = read_your_input()
t = int(data[0])
idx = 1

for _ in range(t):
    L = int(data[idx]); W = int(data[idx+1])
    E = int(data[idx+2]); R = int(data[idx+3])
    idx += 4

    triangle_area = 2 * (L + W)  # perimeter
    energy_per_lap = triangle_area * R
    laps = E // energy_per_lap

    print(laps)