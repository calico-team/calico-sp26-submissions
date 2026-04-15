import sys


def solve():
    input = sys.stdin.read
    data = input().splitlines()

    t = int(data[0])
    idx = 1

    for _ in range(t):
        line = data[idx]
        idx += 1
        line_split = line.split(" ")
        width = int(line_split[0])
        height = int(line_split[1])
        electricity_needed = int(line_split[2])
        electricity_per_meter = int(line_split[3])
        print(line)
        electricity_per_lap = 2 * (width + height) * electricity_per_meter
        print(electricity_per_lap // electricity_needed)



if __name__ == "__main__":
    solve()