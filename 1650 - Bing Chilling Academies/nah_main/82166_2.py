def solve():
    n, p, r, k = map(int, input().split())
    e = list(map(int, input().split()))

    for i in range(n):
        if i % k == 0 and i != 0:
            p += r
        p -= e[i]
        if p < 0:
            print("nah i'd lose")
            return
    print("nah i'd win")


t = int(input())
for _ in range(t):
    solve()
