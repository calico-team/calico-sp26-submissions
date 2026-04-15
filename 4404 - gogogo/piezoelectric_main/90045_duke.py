import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out_lines = []
    for _ in range(t):
        L = int(next(it))
        W = int(next(it))
        E = int(next(it))
        R = int(next(it))
        perimeter = 2 * (L + W)
        electricity_per_lap = perimeter * R
        laps = E // electricity_per_lap   # integer division, guaranteed exact
        out_lines.append(str(laps))
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
