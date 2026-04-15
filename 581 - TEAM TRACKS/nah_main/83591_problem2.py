t = int(input())
for i in range(t):
    n, p, r, k = map(int, input().split())
    cur = list(map(int, input().split()))
    fail = False
    cnt = 0
    for j in range(n):
        p -= cur[j]
        if p < 0:
            fail = True
            break
        cnt += 1
        if cnt % k == 0:
            p += r
    if fail:
        print("nah i'd lose")
    else:
        print("nah i'd win")
