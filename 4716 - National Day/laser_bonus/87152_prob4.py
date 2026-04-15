#1
#3 6 8 2 1
#1 1
#1 5
#5 1
t = int(input())
for _ in range(t):
    win = False
    asts = []
    kmnpq = input().split()
    k = int(kmnpq[0])
    m = int(kmnpq[1])
    n = int(kmnpq[2])
    p = int(kmnpq[3])
    q = int(kmnpq[4])

    xy = input().split()
    x = int(xy[0])
    y = int(xy[1])
    asts.append([x,y])
    for i in range(1,k):
        ast = input().split()
        asts.append(ast)
        asts[-1][0] = int(asts[-1][0])
        asts[-1][1] = int(asts[-1][1])

    while not win:
        x = (x + q) % m
        y = (y + p) % n
        for i in range(k):
            if asts[i][0] == x and asts[i][1] == y:
                print(i)
                win = True
                break
