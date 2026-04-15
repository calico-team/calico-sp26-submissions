import sys

def censor_this_please(a, b):
    j = 0
    m = len(b)
    ans = []

    for ch in a:
        if j < m and ch == b[j]:
            ans.append(ch)
            j += 1
        else:
            ans.append('#')

    return ''.join(ans)

def read_your_input():
    return sys.stdin.read()

def solve():
    s = read_your_input().split()
    t = int(s[0])
    i = 1
    out = []

    for _ in range(t):
        a = s[i]
        b = s[i + 1]
        i += 2
        out.append(censor_this_please(a, b))

    sys.stdout.write('\n'.join(out))

if __name__ == "__main__":
    solve()
