import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, p, r, k = map(int, input().split())
    e = list(map(int, input().split()))
    a = p
    ok = True
    for i in range(n):
        a -= e[i]
        if a < 0:
            ok = False
            break
        if (i + 1) % k == 0:
            a += r
    print("nah i'd win" if ok else "nah i'd lose")
