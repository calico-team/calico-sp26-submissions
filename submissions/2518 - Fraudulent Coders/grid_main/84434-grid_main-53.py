import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    d = {}
    best = (0, 0)
    for j in range(n):
        if arr[j] in d:
            d[arr[j]] += 1
            if d[arr[j]] > best[1]:
                best = (arr[j], d[arr[j]])
        else:
            d[arr[j]] = 1
    if best == (0, 0):
        print(*arr)
    else:
        print((str(best[0]) + " ") * n)
    
    