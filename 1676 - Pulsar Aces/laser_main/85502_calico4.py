for i in range(int(input())):
    k, m, n, q, p = map(int, input().split())
    t = [[int(i) for i in input().split()] for j in range(k)]
    a, b = t[0][0] + p, t[0][1] + q
    while not ([a, b] in t):
        print(a, b)
        a += p
        b += q
        a %= m
        b %= n
    print(t.index([a, b]))