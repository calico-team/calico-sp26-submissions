t = int(input())
for _ in range(t):
    k, n, m, p, q = map(int, input().split())
    ast = [tuple(map(int, input().split())) for _ in range(k)]
    x0, y0 = ast[0]
    best = float('inf')
    ans = 0
    for i in range(k):
        x, y = ast[i]
        dx = (x - x0) % n
        inv = pow(q, -1, n)
        k1 = (dx * inv) % n