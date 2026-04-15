a = int(input())

for _ in range(a):
    b, c = map(int, input().split())

    for i in range(b):

      
        if i == 0:
            if c % 2 == 1:
                print(*([0] * c))
            else:
                print(*[(1 if j % 2 == 0 else 0) for j in range(c)])

       
        elif i == b - 1:
            if c % 2 == 1:
                print(*([4] * c))
            else:
                mid = c // 2
                print(*([4] * mid + [0] * mid))

      
        else:
            print(*list(range(1, c + 1)))