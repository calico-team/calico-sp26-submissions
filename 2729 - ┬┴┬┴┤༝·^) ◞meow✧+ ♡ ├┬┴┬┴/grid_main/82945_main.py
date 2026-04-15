tn = int(input())
for _ in range(tn):
    n = int(input())
    a = list(map(int, input().split()))
    b = a[::]
    for i, x in list(enumerate(a))[1:]:

        def cost(x, i):
            return abs(b[i - 1] - x) + abs(a[i] - x)

        if cost(b[i - 1], i) < cost(x, i):
            b[i] = b[i - 1]
    print(*b)
