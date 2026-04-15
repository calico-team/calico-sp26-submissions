import sys
input = sys.stdin.readline

def read4():
    while True:
        line = input().strip()
        if not line:
            continue
        parts = list(map(int, line.split()))
        if len(parts) == 4:
            return parts

def solve():
    T = int(input())
    for _ in range(T):
        XG, YG, XM, YM = read4()

        dx = XG - XM
        dy = YG - YM

        ans = 0
        LIM = abs(dx) + abs(dy)

        for x in range(-LIM, LIM + 1):
            lo, hi = -LIM, LIM

            while lo <= hi:
                mid = (lo + hi) // 2
                if 7*(abs(x)+abs(mid)) < 2*(abs(x-dx)+abs(mid-dy)):
                    hi = mid - 1
                else:
                    lo = mid + 1
            L = lo

            if L > LIM:
                continue

            lo, hi = L, LIM
            while lo <= hi:
                mid = (lo + hi) // 2
                if 7*(abs(x)+abs(mid)) < 2*(abs(x-dx)+abs(mid-dy)):
                    lo = mid + 1
                else:
                    hi = mid - 1
            R = hi

            if L <= R:
                ans += (R - L + 1)

        print(ans)

solve()