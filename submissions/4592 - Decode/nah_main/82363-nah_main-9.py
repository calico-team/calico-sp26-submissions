t = int(input())
for _ in range(t):
    n, p, r, k = map(int, input().split())
    curses = list(map(int, input().split()))
    failed = False
    for i in range(n):
        p -= curses[i]
        if p < 0:
            print("nah i'd lose")
            failed = True
            break
        if (i + 1) % k == 0:
            p += r
    if not failed:
        print("nah i'd win")
