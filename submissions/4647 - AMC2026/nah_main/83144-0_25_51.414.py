#CALICO-2026-Problem-2
T = int(input())
for i in range(T):
    a = input().split()
    n = int(a[0])
    p = int(a[1])
    r = int(a[2])
    k = int(a[3])
    eList = input().split()
    cnt = 0
    for i in eList:
        cnt += 1
        p -= int(i)
        #print(p)
        if p < 0:
            print("nah i'd lose")
            break
        if cnt % k == 0:
            p += r
    if p >= 0:
        print("nah i'd win")
