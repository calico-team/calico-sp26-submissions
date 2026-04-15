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
        w = s + 1
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

        seats_by_u = sorted(seats, key=lambda rc: rc[0] + rc[1])

        best_sum = None
        best_set = None
        lp = 0
        rp = 0
        active = []
        for i in range(limit):
            while rp < len(seats_by_u) and seats_by_u[rp][0] + seats_by_u[rp][1] <= i + best_d:
                active.append(seats_by_u[rp])
                rp += 1
            new_active = []
            for rc in active:
                if rc[0] + rc[1] >= i:
                    new_active.append(rc)
            active = new_active
            #dude making me slide the window
            #simpleman code > complex

            a = i * w
            b = (i + d) * w
            for j in range(limit):
                if pre[b + j + d] - pre[a + j + d] - pre[b + j] + pre[a + j] >= k:
                    inside = []
                    for r, c in active:
                        vp = r - c + m - 1
                        if j <= vp <= j + best_d:
                            inside.append((aura[(r, c)], r, c))
                    inside.sort()
                    chosen = inside[:k]
                    total = 0
                    for x in chosen:
                        total += x[0]
                    if best_sum is None or total < best_sum:
                        best_sum = total
                        best_set = chosen

        for x in best_set:
            print(x[1], x[2])

main()