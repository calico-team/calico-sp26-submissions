import sys

def solve():
    a = read_your_input()
    t = a[0]
    i = 1
    ans = []

    for _ in range(t):
        l = a[i]
        w = a[i + 1]
        e = a[i + 2]
        r = a[i + 3]
        i += 4

        triangle_area = 2 * (l + w)
        ans.append(str(e // (triangle_area * r)))

    sys.stdout.write("\n".join(ans))

def read_your_input():
    return list(map(int, sys.stdin.buffer.read().split()))

if __name__ == "__main__":
    solve()
