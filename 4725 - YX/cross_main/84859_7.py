a = int(input())
for i in range(a):
    b,c = input().split()
    b,c = int(b),int(c)
    grid = [['0']*c]*b
    if b != 3:
        print(grid)
        continue
    else:
        grid = [['0']*c]
        p = ['1','2','3']
        p = p * (c//3)
        p += (p[:c%3])
        grid.append(p)
        grid.append(['4']*c)
    for j in grid:
        for k in j:
            print(k,end=' ')
        print()
