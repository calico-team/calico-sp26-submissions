import sys
input = sys.stdin.readline


def solve():
    xg, yg, xm, ym = map(int, input().split())
    gx = xg - xm
    gy = yg - ym
    D = abs(gx) + abs(gy)

    if D == 0:
        print(1)
        return

    # 7*dm < 2*dg, and dg >= D - dm => 9*dm < 2*D => dm <= (2*D-1)//9
    max_dm = (2 * D - 1) // 9
    bound = max_dm + abs(gy) + 1

    count = 0

    for x in range(-max_dm, max_dm + 1):
        R = 2 * abs(x - gx) - 7 * abs(x)
        # Need f(y) = 7|y| - 2|y-gy| < R
        # f is unimodal with min at y=0, value -2|gy|
        if -2 * abs(gy) >= R:
            continue

        # Binary search upper bound: largest y >= 0 with f(y) < R
        # For y >= 0, f is non-decreasing
        lo, hi = 0, bound
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if 7 * mid - 2 * abs(mid - gy) < R:
                lo = mid
            else:
                hi = mid - 1
        y_hi = lo

        # Binary search lower bound: smallest y <= 0 with f(y) < R
        # For y <= 0, f is non-increasing (as y increases toward 0)
        lo, hi = -bound, 0
        while lo < hi:
            mid = (lo + hi) // 2
            if 7 * (-mid) - 2 * abs(mid - gy) < R:
                hi = mid
            else:
                lo = mid + 1
        y_lo = lo

        # Verify boundaries
        if 7 * abs(y_hi) - 2 * abs(y_hi - gy) >= R:
            y_hi -= 1
        if 7 * abs(y_lo) - 2 * abs(y_lo - gy) >= R:
            y_lo += 1

        if y_lo > y_hi:
            continue
        count += y_hi - y_lo + 1

    print(count)


def main():
    T = int(input())
    for _ in range(T):
        solve()


if __name__ == '__main__':
    main()
