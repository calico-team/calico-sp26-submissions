import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    xg, yg, xm, ym = map(int, input().split())
    D = abs(xg-xm) + abs(yg-ym)
    R = 5*D//7 + 15

    x1 = min(xg, xm -R) - 2
    y1 = min(yg, ym -R) - 2
    x2 = max(xg, xm +R) + 2
    y2 = max(yg, ym +R) + 2
    W = x2 -x1 + 1
    H = y2 -y1 + 1

    gx = xg -x1
    gy = yg -y1
    cx = xm -x1
    cy = ym -y1

    sz = W *H
    dist = [-1] *sz
    for j in range(H):
        dist[j] =0; dist[(W-1)*H +j] = 0
    for i in range(W):
        dist[i*H] = 0; dist[i*H +H-1] =0

    dist[cx*H +cy] = -2
    dist[gx*H +gy] =0
    q = deque([gx*H +gy])
    ans = 1

    while q:
        ci = q.popleft()
        d =dist[ci]; nd = d +1
        x = ci //H; y = ci -x *H

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
        if 1 <=ix <=W-2:
            bm = R -abs(a)
            base = ix *H
            for b in range(-bm, bm+1):
                iy = cy +b
                if 1 <=iy <=H-2:
                    if dist[base +iy] ==-1:
                        ans +=1

    print(ans)
