t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    v = list(set(a))
    res = a[:]
    best = 10**18

    for x in v:
        for y in v:
            for z in v:
                b = [x, y, z][:n]
                s = 0
                for i in range(n):
                    s += abs(a[i] - b[i])
                for i in range(n - 1):
                    s += abs(b[i] - b[i + 1])
                if s < best:
                    best = s
                    res = b[:]
    print(*res)
