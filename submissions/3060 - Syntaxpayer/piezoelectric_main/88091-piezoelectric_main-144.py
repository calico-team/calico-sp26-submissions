import sys

def solve():
    data = list(map(int, sys.stdin.buffer.read().split()))
    t = data[0]
    idx = 1
    out = []

    for _ in range(t):
        L = data[idx]
        W = data[idx + 1]
        E = data[idx + 2]
        R = data[idx + 3]
        idx += 4

        zia = 2 * (L + W)
        out.append(str(E // (zia * R)))

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()