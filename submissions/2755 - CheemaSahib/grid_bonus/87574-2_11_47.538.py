import sys

def solve():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    t = next(it)
    out = []

    for _ in range(t):
        n = next(it)
        the_two_tower_heights = [next(it) for _ in range(n)]

        l = [0] * n
        r = [0] * n
        l[0] = r[0] = the_two_tower_heights[0]

        for i in range(1, n):
            x = the_two_tower_heights[i]
            if x < l[i - 1]:
                l[i] = x
                r[i] = l[i - 1]
            elif x > r[i - 1]:
                l[i] = r[i - 1]
                r[i] = x
            else:
                l[i] = r[i] = x

        b = [0] * n
        b[-1] = l[-1]

        for i in range(n - 2, -1, -1):
            x = b[i + 1]
            if x < l[i]:
                b[i] = l[i]
            elif x > r[i]:
                b[i] = r[i]
            else:
                b[i] = x

        out.append(" ".join(map(str, b)))

    sys.stdout.write("\n".join(out))

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()
