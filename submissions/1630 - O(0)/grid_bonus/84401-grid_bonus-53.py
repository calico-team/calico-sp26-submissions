t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(a[0])
        continue
    b = []
    for j in range(n):
        if j ==0:
            b.append(a[0])
        elif j == n - 1:
            b.append(a[n-1])
        else:
            b.append(sorted([a[j-1], a[j],a[j+1]])[1])
    print(*b)