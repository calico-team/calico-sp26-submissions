import sys

def make_the_criss_cross(n, m):
    g = []
    for i in range(n):
        r = []
        for j in range(m):
            r.append((i + 2 * j) % 5)
        g.append(r)
    return g

def read_your_input():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    t = next(it)
    w = sys.stdout.write

    for _ in range(t):
        n = next(it)
        m = next(it)

        s = []
        for i in range(5):
            r = []
            for j in range(m):
                r.append(str((i + 2 * j) % 5))
            s.append(" ".join(r))

        for i in range(n):
            w(s[i % 5])
            w("\n")

if __name__ == "__main__":
    read_your_input()
