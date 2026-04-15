x = int(input())

for _ in range(x):
    y, z = map(int, input().split())

    for i in range(y):
        if i == 0:
            if z % 2:
                print(*[0]*z)
            else:
                print(*[(j+1)%2 for j in range(z)])
        elif i == y-1:
            if z % 2:
                print(*[4]*z)
            else:
                print(*([4]*(z//2) + [0]*(z//2)))
        else:
            print(*range(1, z+1))