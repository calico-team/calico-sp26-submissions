k, n, m, p, q = map(int, input().split())
t = [[int(i) for i in input().split()] for j in range(k)]
a, b = p, q
while not ([a, b] in t):
    a += p
    b += q
    a %= m - 1
    b %= n - 1
print(t.index([a, b]))