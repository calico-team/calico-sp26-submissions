tn = int(input())
for _ in range(tn):
    n = int(input())
    a = list(map(int, input().split()))
    b = a[::]
    for i in range(1, n - 1):
        if b[i] > b[i - 1] and b[i] > b[i + 1]:
            b[i] = max(b[i - 1], b[i + 1])
        if b[i] < b[i - 1] and b[i] < b[i + 1]:
            b[i] = min(b[i - 1], b[i + 1])
    print(*b)
