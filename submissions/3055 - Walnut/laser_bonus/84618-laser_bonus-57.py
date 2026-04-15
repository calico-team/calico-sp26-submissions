from math import gcd
def merge(a, n, b, m):
    shared = gcd(n, m)
    if (b - a) % shared != 0:
        return None
    left = n // shared
    right = m // shared
    cycle = left * m
    if right == 1:
        step = 0
    else:
        step = ((b - a) // shared) * pow(left, -1, right) % right
    spot = (a + n * step) % cycle
    return spot, cycle
tests = int(input())
for _ in range(tests):
    k, n, m, p, q = map(int, input().split())
    startx, starty = map(int, input().split())
    sharedchangex = gcd(q, n)
    sharedchangey = gcd(p, m)
    spanx = n // sharedchangex
    spany = m // sharedchangey
    inversex = pow(q // sharedchangex, -1, spanx) if spanx > 1 else 0
    inversey = pow(p // sharedchangey, -1, spany) if spany > 1 else 0
    period = spanx // gcd(spanx, spany) * spany
    best = 0
    soonest = period
    for j in range(1, k):
        x, y = map(int, input().split())
        changex = (x - startx) % n
        if changex % sharedchangex != 0:
            continue
        changey = (y - starty) % m
        if changey % sharedchangey != 0:
            continue
        needx = (changex // sharedchangex) * inversex % spanx if spanx > 1 else 0
        needy = (changey // sharedchangey) * inversey % spany if spany > 1 else 0
        joined = merge(needx, spanx, needy, spany)
        if joined is None:
            continue
        spot, cycle = joined
        time = cycle if spot == 0 else spot
        if time < soonest or (time == soonest and j < best):
            soonest = time
            best = j
    print(best)