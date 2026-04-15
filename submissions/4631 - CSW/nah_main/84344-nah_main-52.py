f = int(input())
for s in range(f):
    k = list(map(int,input().split()))
    n = k[0]
    p = k[1]
    r = k[2]
    k = k[3]
    e = list(map(int,input().split()))
    t = 0
    for i in range(n):
        p -= e[i]
        t += 1
        if p < 0:
            print("nah i'd lose")
            break
        if t == k:
            p += r
            t = 0
    if p >= 0:
        print("nah i'd win")