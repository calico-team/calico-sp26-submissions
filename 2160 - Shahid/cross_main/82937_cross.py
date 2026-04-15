import sys

def solve():
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    out = []

    for _ in range(T):
        N = int(data[idx]); idx += 1
        M = int(data[idx]); idx += 1

        def make_the_criss_cross(N, M):
            grid = []
            for r in range(N):
                row = []
                for c in range(M):
                    row.append(str((2 * r + c) % 5))
                grid.append(' '.join(row))
            return grid

        for line in make_the_criss_cross(N, M):
            out.append(line)

    print('\n'.join(out))

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()
