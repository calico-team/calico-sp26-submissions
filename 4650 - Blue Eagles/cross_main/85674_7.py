import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out_lines = []
    a, b = 1, 2
    for _ in range(T):
        N = int(next(it))
        M = int(next(it))
        for r in range(N):
            row = [(a * r + b * c) % 5 for c in range(M)]
            out_lines.append(' '.join(map(str, row)))
    sys.stdout.write('\n'.join(out_lines))

if __name__ == "__main__":
    solve()
