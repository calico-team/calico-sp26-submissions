import sys
from collections import deque

def main():
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx])
    idx += 1

    out = []
    for tc in range(t):
        xg = int(input[idx])
        yg = int(input[idx + 1])
        xm = int(input[idx + 2])
        ym = int(input[idx + 3])
        idx += 4

        dgm = abs(xg - xm) + abs(yg - ym)
        box = dgm + 30
        side = 2 * box + 1
        owner = bytearray(side * side)

        owner[(xm - xm + box) * side + (ym - ym + box)] = 2
        owner[(xg - xm + box) * side + (yg - ym + box)] = 1

        gq = deque()
        mq = deque()
        gq.append((2, xg, yg))
        mq.append((7, xm, ym))

        count = 1
        bx_lo = xm - box
        bx_hi = xm + box
        by_lo = ym - box
        by_hi = ym + box
        ox = -xm + box
        oy = -ym + box

        ow = owner
        gq_pop = gq.popleft
        gq_app = gq.append
        mq_pop = mq.popleft
        mq_app = mq.append

        cutoff = 7 * (dgm + 30)
        while mq:
            if mq[0][0] > cutoff:
                break
            if gq and gq[0][0] <= mq[0][0]:
                tick, x, y = gq_pop()
                nt = tick + 2
                nx = x + 1
                if nx <= bx_hi:
                    p = (nx + ox) * side + (y + oy)
                    if ow[p] == 0:
                        ow[p] = 1
                        gq_app((nt, nx, y))
                nx = x - 1
                if nx >= bx_lo:
                    p = (nx + ox) * side + (y + oy)
                    if ow[p] == 0:
                        ow[p] = 1
                        gq_app((nt, nx, y))
                ny = y + 1
                if ny <= by_hi:
                    p = (x + ox) * side + (ny + oy)
                    if ow[p] == 0:
                        ow[p] = 1
                        gq_app((nt, x, ny))
                ny = y - 1
                if ny >= by_lo:
                    p = (x + ox) * side + (ny + oy)
                    if ow[p] == 0:
                        ow[p] = 1
                        gq_app((nt, x, ny))
            else:
                tick, x, y = mq_pop()
                nt = tick + 7
                nx = x + 1
                if nx <= bx_hi:
                    p = (nx + ox) * side + (y + oy)
                    if ow[p] == 0:
                        ow[p] = 2
                        count += 1
                        mq_app((nt, nx, y))
                nx = x - 1
                if nx >= bx_lo:
                    p = (nx + ox) * side + (y + oy)
                    if ow[p] == 0:
                        ow[p] = 2
                        count += 1
                        mq_app((nt, nx, y))
                ny = y + 1
                if ny <= by_hi:
                    p = (x + ox) * side + (ny + oy)
                    if ow[p] == 0:
                        ow[p] = 2
                        count += 1
                        mq_app((nt, x, ny))
                ny = y - 1
                if ny >= by_lo:
                    p = (x + ox) * side + (ny + oy)
                    if ow[p] == 0:
                        ow[p] = 2
                        count += 1
                        mq_app((nt, x, ny))

        out.append(str(count))
        #for crying out loud

    sys.stdout.write('\n'.join(out) + '\n')

main()