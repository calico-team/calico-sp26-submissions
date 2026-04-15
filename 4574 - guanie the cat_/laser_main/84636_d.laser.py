for T in range(int(input())):
    k, n, m, p, q = [int(i) for i in input().split()]
    min_id = 0
    min_score = n*m + 1
    locs = {}
    for j in range(k):
        tx, ty = [int(i) for i in input().split()]
        if j == 0:
            cx, cy = tx, ty
        locs[(tx, ty)] = j
    while True:
        cx, cy = (cx + 1) % n, (cy + p) % m
        t = (cx, cy)
        if t in locs:
            break
    print(locs[t])