import sys

def solve():
    a = sys.stdin.read().split()

    if not a:
        return

    t = int(a[0])
    i = 1

    for _ in range(t):
        b = int(a[i])
        c = int(a[i+1])
        d = int(a[i+2])
        e = int(a[i+3])
        i += 4

        p = 2 * (b + c)
        g = p * e
        n = d // g
        print(n)

if __name__ == "__main__":
    solve()