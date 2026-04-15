import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    xg, yg, xm, ym = map(int, input().split())
    D = abs(xg-xm) + abs(yg-ym)
    R = 3*D//4 + 10

    W = 2*R + 3
    H = 2*R +3
    sz = W *H

    gx = xg -xm + R + 1
    gy = yg -ym + R + 1
    cx = R +1
    cy = R+1

    dist = [-1] *sz
    for j in range(H):
        dist[j] =0
        dist[(W-1)*H +j] = 0
    for i in range(W):
        dist[i*H] =0
        dist[i*H +H-1] = 0

    mi = cx*H +cy
    dist[mi] = -2

    gi = gx*H +gy
    dist[gi] =0
    q = deque([gi])
    ans = 1

    while q:
        ci = q.popleft()
        d =dist[ci]
        nd = d +1
        x = ci //H
        y = ci -x *H

        ni = ci+1
        if dist[ni] ==-1:
            dm = abs(x-cx) +abs(y+1-cy)
            if 7*dm <2*nd:
                dist[ni] = -2; ans +=1
            else:
                dist[ni] =nd; q.append(ni)

        ni = ci-1
        if dist[ni] ==-1:
            dm = abs(x-cx) + abs(y-1-cy)
            if 7*dm <2*nd:
                dist[ni] =-2; ans +=1
            else:
                dist[ni] = nd; q.append(ni)

        ni = ci+H
        if dist[ni]==-1:
            dm = abs(x+1-cx) +abs(y-cy)
            if 7*dm<2*nd:
                dist[ni] =-2; ans +=1
            else:
                dist[ni] = nd; q.append(ni)

        ni = ci-H
        if dist[ni] ==-1:
            dm = abs(x-1-cx) +abs(y-cy)
            if 7*dm< 2*nd:
                dist[ni] = -2; ans+=1
            else:
                dist[ni] =nd; q.append(ni)

    for a in range(-R, R+1):
        ix = cx +a
        bm = R -abs(a)
        base = ix *H
        for b in range(-bm, bm+1):
            if dist[base +cy + b] ==-1:
                ans +=1

    print(ans)
