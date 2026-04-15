import sys
#why are you not letting me use numpy vro

def main():
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx])
    idx += 1

    for tc in range(t):
        n = int(input[idx])
        m = int(input[idx + 1])
        k = int(input[idx + 2])
        idx += 3

        grid = []
        for i in range(n):
            grid.append(input[idx])
            idx += 1

        seats = []
        for r in range(n):
            for c in range(m):
                if grid[r][c] == "-":
                    seats.append((r, c))

        if k == 1:
            print(seats[0][0], seats[0][1])
            continue

        s = n + m - 1
        w = s + 1
        pre = [0] * (w * w)
        for r, c in seats:
            u = r + c
            vp = r - c + m - 1
            pre[(u + 1) * w + (vp + 1)] = 1

        for i in range(1, w):
            row = i * w
            prev = (i - 1) * w
            for j in range(1, w):
                pre[row + j] += pre[row + j - 1] + pre[prev + j] - pre[prev + j - 1]

        def check(d):
            limit = w - d
            for i in range(limit):
                a = i * w
                b = (i + d) * w
                for j in range(limit):
                    if pre[b + j + d] - pre[a + j + d] - pre[b + j] + pre[a + j] >= k:
                        return i, j
            return None

        lo = 0
        hi = s - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if check(mid + 1) is not None:
                hi = mid
            else:
                lo = mid + 1

        best_d = lo
        u0, v0 = check(best_d + 1)
        count = 0
        for r, c in seats:
            u = r + c
            vp = r - c + m - 1
            if u0 <= u <= u0 + best_d and v0 <= vp <= v0 + best_d:
                print(r, c)
                count += 1
                if count == k:
                    break

main()