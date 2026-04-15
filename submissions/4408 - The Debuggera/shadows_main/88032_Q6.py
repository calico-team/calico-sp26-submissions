import sys


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        N = int(next(it))
        s1 = [next(it) for _ in range(N)]
        s2 = [next(it) for _ in range(N)]
        vmax = 0
        vmin = 0
        for i in range(N):
            L = s1[i].count("#")
            R = s2[i].count("#")
            vmax += L * R
            vmin += max(L, R)
        out.append(f"{vmax} {vmin}")
    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
