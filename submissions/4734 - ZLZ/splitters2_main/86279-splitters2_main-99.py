import sys
input = sys.stdin.readline

def solve():
    T = int(input())
    for _ in range(T):
        XG, YG, XM, YM = map(int, input().split())

        dx = XG - XM
        dy = YG - YM

        # 曼哈顿距离
        d = abs(dx) + abs(dy)

        ans = 0

        # 枚举 x 的有效范围（严格有限）
        LIM = d

        for x in range(-LIM, LIM + 1):
            # 对 y 求范围（直接线性推）
            # 这里不再二分，而是利用单调性扫描

            lo = -LIM
            hi = LIM

            # 找第一个满足的 y
            while lo <= hi:
                mid = (lo + hi) // 2
                if 7*(abs(x)+abs(mid)) < 2*(abs(x-dx)+abs(mid-dy)):
                    hi = mid - 1
                else:
                    lo = mid + 1

            L = lo

            if L > LIM:
                continue

            # 找最后一个满足的 y
            lo = L
            hi = LIM

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

if __name__ == "__main__":
    solve()