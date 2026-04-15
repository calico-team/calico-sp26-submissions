import sys


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        N = int(next(it))
        M = int(next(it))
        for r in range(N):
            row = [(2 * r + c) % 5 for c in range(M)]
            out_lines.append(" ".join(map(str, row)))
    sys.stdout.write("\n".join(out_lines) + "\n")


if __name__ == "__main__":
    main()
