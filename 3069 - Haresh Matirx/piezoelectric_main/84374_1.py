import sys

def solve():
    d = sys.stdin.read().split()

    if not d:
        return

    t = int(d[0])
    i = 1

    for _ in range(t):
        l = int(d[i])
        w = int(d[i+1])
        e = int(d[i+2])
        r = int(d[i+3])
        i += 4

        p = 2 * (l + w)
        g = p * r
        n = e // g
        print(n)

if __name__ == "__main__":
    solve()