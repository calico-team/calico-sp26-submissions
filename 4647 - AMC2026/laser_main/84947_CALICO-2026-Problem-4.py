#CALICO-2026-Problem-4
t = int(input())
for i in range(t):
    a = input().split()
    k = int(a[0])
    n = int(a[1])
    m = int(a[2])
    p = int(a[3])
    q = int(a[4])
    aList = []
    for i in range(k):
        a = input().split()
        a[0] = int(a[0])
        a[1] = int(a[1])
        aList.append(a)
    x, y = aList[0][0], aList[0][1]
    while True:
        x += q
        y += p
        #print(x, y)
        if x >= n:
            x = x - n
        if y >= m:
            y = y - m
        #print(x, y)
        if [x, y] in aList:
            print(aList.index([x, y]))
            break
