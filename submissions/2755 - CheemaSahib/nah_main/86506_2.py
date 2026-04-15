import sys

def solve():
    a = list(map(int, sys.stdin.buffer.read().split()))
    t = a[0]
    j = 1
    ans = []
    dylan_power = 0

    for _ in range(t):
        n = a[j]
        p = a[j + 1]
        r = a[j + 2]
        k = a[j + 3]
        j += 4

        dylan_power = p
        ok = True

        for i in range(1, n + 1):
            p -= a[j]
            j += 1

            if p < 0:
                ok = False
                j += n - i
                break

            if i % k == 0:
                p += r

        if ok:
            ans.append("nah i'd win")
        else:
            ans.append("nah i'd lose")

    sys.stdout.write("\n".join(ans))

if __name__ == "__main__":
    solve()

def read_your_input():
    return sys.stdin.buffer.read()
