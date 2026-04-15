t = int(input())
for i in range(t):
    drawing = []
    x,y = map(int,input().split())
    t = True
    for j in range(x):
        row = []
        if j % 2 == 0:
            if t == True:
                row += [3] * y
                t = False
            else:
                row += [4] * y
                t = True
        else:
            m = y // 3
            e = y % 3
            row += [0,1,2] * m
            for w in range(e):
                row += [w]
        drawing.append(row)
    for row in drawing:
        print(*row)
