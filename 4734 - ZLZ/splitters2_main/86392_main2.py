import sys
input = sys.stdin.readline

def solve():
    T = int(input())
    for _ in range(T):
        XG, YG, XM, YM = map(int, input().split())

        dx = XG - XM
        dy = YG - YM

        LIM = abs(dx) + abs(dy)

        ans = 0

        # 双指针初始化
        L = -LIM
        R = -LIM

        for x in range(-LIM, LIM + 1):
            # 移动 L（找到第一个合法 y）
            while L <= LIM and not (7*(abs(x)+abs(L)) < 2*(abs(x-dx)+abs(L-dy))):
                L += 1

            if L > LIM:
                continue

            # 保证 R 至少在 L
            if R < L:
                R = L

            # 扩展 R（找到最后一个合法 y）
            while R + 1 <= LIM and (7*(abs(x)+abs(R+1)) < 2*(abs(x-dx)+abs(R+1-dy))):
                R += 1

            ans += (R - L + 1)

        print(ans)

if __name__ == "__main__":
    solve()