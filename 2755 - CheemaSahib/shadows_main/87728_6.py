import sys

jugs_cave_image = 0

def solve():
    rd = sys.stdin.buffer.readline
    t = int(rd())
    out = []

    for _ in range(t):
        n = int(rd())
        a = [0] * n

        for i in range(n):
            a[i] = rd().count(b'#')

        mx = 0
        mn = 0

        for i in range(n):
            b = rd().count(b'#')
            mx += a[i] * b
            mn += a[i] if a[i] > b else b

        out.append(f"{mx} {mn}")

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()

def read_your_input():
    return sys.stdin.buffer.readline()
