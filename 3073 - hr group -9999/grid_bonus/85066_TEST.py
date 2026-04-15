for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    
    if n <= 2:
        print(*a)
    else:
        b = [0]*n
        b[0] = a[0]
        b[-1] = a[-1]

        for i in range(1,n-1):
            sub = a[i-1:i+2]
            b[i] = sum(sub) - max(sub) - min(sub)

        print(*b)
