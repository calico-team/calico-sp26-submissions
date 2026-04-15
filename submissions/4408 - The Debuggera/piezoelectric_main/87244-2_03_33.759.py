import sys


def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        L = int(next(it))
        W = int(next(it))
        E = int(next(it))
        R = int(next(it))
        P = 2 * (L + W)
        out.append(str(E // (P * R)))
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()
