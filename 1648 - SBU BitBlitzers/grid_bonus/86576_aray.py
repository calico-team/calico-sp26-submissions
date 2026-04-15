
t= int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    b = a.copy()
    for i in range(1,n-1):
        if b[i]<min(b[i-1],b[i+1]):
            b[i] = min(b[i-1],b[i+1])
        elif b[i]>max(b[i-1],b[i+1]):
            b[i] = max(b[i-1],b[i+1])
    print(*b)

