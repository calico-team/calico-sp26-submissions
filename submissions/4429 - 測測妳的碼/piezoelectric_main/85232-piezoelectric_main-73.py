import sys

def solve():
    try:
        line = sys.stdin.readline()
        if not line:
            return
        t = int(line.strip())
    except ValueError:
        return

    for _ in range(t):
        try:
            l, w, e, r = map(int, sys.stdin.readline().split())
            perimeter = 2 * (l + w)
            energy_per_lap = perimeter * r
            laps = e // energy_per_lap
            print(laps)
        except ValueError:
            break

if __name__ == "__main__":
    solve()



