t = int(input())
for i in range(t):
    drawing = []
    x,y = map(int,input().split())
    t = True
    for j in range(x):
        row = []
        if j % 2 == 0:
            if t == True:
                m = y // 5
                e = y % 5
                row += [0,1,2,3,4] * m
                for w in range(e):
                    row += [w]
                t = False
            else:
                m = y // 5
                e = y % 5
                row += [1,2,3,4,0] * m
                for w in range(e):
                    n = w + 1
                    if n >= 5:
                        n = n % 5
                    row += [n]
                t = True
        else:
            m = y // 5
            e = y % 5
            row += [3,4,0,1,2] * m
            for w in range(e):
                n = w + 3
                if n >= 5:
                    n = n % 5
                row += [n]
        drawing.append(row)
    for row in drawing:
        print(*row)
