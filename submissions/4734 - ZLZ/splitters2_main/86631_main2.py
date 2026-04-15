import sys

def solve():
    T = int(input())
    for _ in range(T):
        while True:
            line = sys.stdin.readline()
            if not line:  # ⭐ 防 EOF
                return
            parts = line.split()
            if len(parts) == 4:
                XG, YG, XM, YM = map(int, parts)
                break

        dx = XG - XM
        dy = YG - YM

        LIM = abs(dx) + abs(dy)
        ans = 0

        L = -LIM
        R = -LIM

        for x in range(-LIM, LIM + 1):
            while L <= LIM and not (7*(abs(x)+abs(L)) < 2*(abs(x-dx)+abs(L-dy))):
                L += 1

            if L > LIM:
                continue

            if R < L:
                R = L

            while R + 1 <= LIM and (7*(abs(x)+abs(R+1)) < 2*(abs(x-dx)+abs(R+1-dy))):
                R += 1

            ans += (R - L + 1)

        print(ans)

solve()