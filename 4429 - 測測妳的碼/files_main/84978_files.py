import sys

def solve():
    data = sys.stdin.read().split()
    if not data: return
    t = int(data[0])
    curr = 1
    for _ in range(t):
        a = data[curr]
        b = data[curr+1]
        curr += 2
        ans = list(a)
        b_ptr = 0
        for i in range(len(a)):
            if b_ptr < len(b) and a[i] == b[b_ptr]:
                b_ptr += 1
            else:
                ans[i] = '#'
        print("".join(ans))

if __name__ == '__main__':
    solve()