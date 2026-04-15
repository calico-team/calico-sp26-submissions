t = int(input())
for i in range(t):
    drawing = []
    x,y = map(int,input().split())
    for j in range(x):
        row = []
        if j % 5 == 0:
            m = y // 5
            e = y % 5
            row += [0,1,2,3,4] * m
            for w in range(e):
                row += [w]
        elif j % 5 == 1:
            m = y // 5
            e = y % 5
            row += [3,4,0,1,2] * m
            for w in range(e):
                n = w + 3
                if n >= 5:
                    n = n % 5
                row += [n]
        elif j % 5 == 2:
            m = y // 5
            e = y % 5
            row += [1,2,3,4,0] * m
            for w in range(e):
                n = w + 1
                if n >= 5:
                    n = n % 5
                row += [n]
        elif j % 5 == 3:
            m = y // 5
            e = y % 5
            row += [4,0,1,2,3] * m
            for w in range(e):
                n = w + 4
                if n >= 5:
                    n = n % 5
                row += [n]
        elif j % 5 == 4:
            m = y // 5
            e = y % 5
            row += [2,3,4,0,1] * m
            for w in range(e):
                n = w + 2
                if n >= 5:
                    n = n % 5
                row += [n]
        drawing.append(row)
    for row in drawing:
        print(*row)              