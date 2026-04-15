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
        aura = {}
        #i called it :sob:
        for r in range(n):
            row = grid[r]
            left = [0] * m
            cnt = 0
            for c in range(m):
                left[c] = cnt
                if row[c] == "#":
                    cnt += 1
            right = [0] * m
            cnt = 0
            for c in range(m - 1, -1, -1):
                right[c] = cnt
                if row[c] == "#":
                    cnt += 1
            for c in range(m):
                if row[c] == "-":
                    seats.append((r, c))
                    aura[(r, c)] = min(left[c], right[c])

        if k == 1:
            best = min(seats, key=lambda s: aura[s])
            print(best[0], best[1])
            continue

        s = n + m - 1
        w = set + 1
        pre = [0] * (w * w)
        for r, c in seats:
            pre[(r + c + 1) * w + (r - c + m)] = 1
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
                        return True
            return False

        lo = 0
        hi = s - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if check(mid + 1):
                hi = mid
            else:
                lo = mid + 1

        best_d = lo
        d = best_d + 1
        limit = w - d

        best_sum = None
        best_set = None
        for i in range(limit):
            a = i * w
            b = (i + d) * w
            for j in range(limit):
                if pre[b + j + d] - pre[a + j + d] - pre[b + j] + pre[a + j] >= k:
                    inside = []
                    for r, c in seats:
                        u = r + c
                        vp = r - c + m - 1
                        if i <= u <= i + best_d and j <= vp <= j + best_d:
                            inside.append((aura[(r, c)], r, c))
                    inside.sort()
                    chosen = inside[:k]
                    s = 0
                    for x in chosen:
                        s += x[0]
                    if best_sum is None or s < best_sum:
                        best_sum = s
                        best_set = chosen

        for x in best_set:
            print(x[1], x[2])

main()