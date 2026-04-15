t = int(input())

for _ in range(t):

    k, n, m, p, q = map(int, input().split())
    spots = {}
    sx, sy = 0, 0

    for i in range(k):
        x, y = map(int, input().split())

        if i == 0:
            sx, sy = x, y

        if (x, y) not in spots:
            spots[(x, y)] = i

    cx, cy = sx, sy

    while True:
        cx = (cx + q) % n
        cy = (cy + p) % m

        if (cx, cy) in spots:
            print(spots[(cx, cy)])
            break
