t = int(input())
for i in range(t):
    tmp = list(map(int, input().split(' ')))
    k, n, m, p, q = tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]
    l = []
    for j in range(k):
        l.append(list(map(int, input().split(' '))))
    x, y = l[0][0], l[0][1]
    l.pop(0)
    x1, y1 = x, y
    flag = True
    while [x1, y1] not in l:
        x1 += p
        y1 += q
        if x1 > n - 1:
            x1 = x1 - (n - 1)
        if y1 > m - 1:
            y1 = y1 - (m - 1)
        if x1 == x and y1 == y:
            flag = False
            break
    if not flag:
        print(0)
    else:
        print(l.index([x1, y1]) + 1)
