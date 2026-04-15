import sys
import numpy as np

def main():
    input = sys.stdin.read().split()
    #luh meeeee
    idx = 0
    t = int(input[idx])
    idx += 1

    for tc in range(t):
        n = int(input[idx])
        m = int(input[idx + 1])
        k = int(input[idx + 2])
        idx += 3

        grid = []
        for tc1 in range(n):
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

        S = n + m - 1
        cnt = np.zeros((S, S), dtype=np.int32)
        for r, c in seats:
            cnt[r + c, r - c + m - 1] += 1

        pre = np.zeros((S + 1, S + 1), dtype=np.int32)
        pre[1:, 1:] = np.cumsum(np.cumsum(cnt, axis=0), axis=1)
        #flip you rohaan
        lo = 0
        hi = S - 1
        while lo < hi:
            mid = (lo + hi) // 2
            d = mid + 1
            w = pre[d:, d:] - pre[:-d, d:] - pre[d:, :-d] + pre[:-d, :-d]
            if np.max(w) >= k:
                hi = mid
            else:
                lo = mid + 1

        best_d = lo
        d = best_d + 1
        w = pre[d:, d:] - pre[:-d, d:] - pre[d:, :-d] + pre[:-d, :-d]
        match = np.argwhere(w >= k)
        u0 = int(match[0][0])
        v0 = int(match[0][1])

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