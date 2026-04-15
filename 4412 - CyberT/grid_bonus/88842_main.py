import sys
input = sys.stdin.readline
time = int(input())
for _ in range(time):
    n = int(input())
    a = list(map(int, input().split()))
    ok = True
    for i in range(1, n):
        if a[i] < a[i-1]:
            ok = False
            break
    if ok:
        print(*a)
    else:
        mn = min(a)
        res = []
        for i in range(n):
            res.append(mn)
        print(*res)
def read_your_input():
    pass