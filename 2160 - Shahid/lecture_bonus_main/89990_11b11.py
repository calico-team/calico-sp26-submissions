import sys
import heapq
import bisect

def solve() -> None:
    data = sys.stdin.buffer.read().split()
    it = iter(data)
    t = int(next(it))
    out_lines = []

    for _ in range(t):
        n = int(next(it))
        m = int(next(it))
        k = int(next(it))
        grid = [next(it).decode() for _ in range(n)]

        # collect available seats with (r,c) and aura loss
        seats = []
        row_occ = [row.count('#') for row in grid]
        for r in range(n):
            row = grid[r]
            occ_left = 0
            for c, ch in enumerate(row):
                if ch == '-':
                    left = occ_left
                    right = row_occ[r] - occ_left
                    aura = left if left < right else right
                    seats.append((r, c, aura))
                else:
                    occ_left += 1

        if not seats:
            # no available seats (should not happen because k <= #seats)
            continue

        # transform to (u, v) where u = r+c, v = r-c + (m-1)
        offset = m - 1
        points = []          # list of (u, v, aura)
        for r, c, a in seats:
            u = r + c
            v = r - c + offset
            points.append((u, v, a))

        # find max u and v
        max_u = max(p[0] for p in points)
        max_v = max(p[1] for p in points)
        U = max_u + 1
        V = max_v + 1

        # build count grid and aura grid (only for points)
        cnt = [[0] * V for _ in range(U)]
        aura_grid = [[-1] * V for _ in range(U)]   # -1 means no seat
        for u, v, a in points:
            cnt[u][v] = 1
            aura_grid[u][v] = a

        # 2D prefix sum for counts (to find minimal D)
        pre = [[0] * (V + 1) for _ in range(U + 1)]
        for i in range(U):
            row_sum = 0
            for j in range(V):
                row_sum += cnt[i][j]
                pre[i+1][j+1] = pre[i][j+1] + row_sum

        # binary search for minimal side length D (in u-v space)
        lo, hi = 0, max(U, V)
        while lo < hi:
            mid = (lo + hi) // 2
            side = mid
            ok = False
            if side <= U and side <= V:
                for i in range(U - side + 1):
                    for j in range(V - side + 1):
                        total = (pre[i+side][j+side] - pre[i][j+side]
                                 - pre[i+side][j] + pre[i][j])
                        if total >= k:
                            ok = True
                            break
                    if ok:
                        break
            if ok:
                hi = mid
            else:
                lo = mid + 1
        D = lo

        # now find the square of side D that minimizes sum of k smallest auras
        # group points by row u, each row has list of (v, aura) sorted by v
        rows = [[] for _ in range(U)]
        for u, v, a in points:
            rows[u].append((v, a))
        for u in range(U):
            rows[u].sort()

        best_sum = None
        best_seats = []

        # iterate over possible top-left u0
        for u0 in range(U - D + 1):
            # collect all points in rows u0 .. u0+D-1
            # we need to consider v0 sliding window
            # we'll build a list of all (v, aura) in this vertical strip
            strip = []
            for u in range(u0, u0 + D):
                strip.extend(rows[u])
            if len(strip) < k:
                continue
            strip.sort()   # sort by v

            # sliding window over v: left and right pointers
            # we maintain a frequency array of auras for the current v-window
            # and also a total count and sum of k smallest
            # because aura values are small (0..1000), we can use an array of size 1001
            max_aura = m  # aura <= m
            freq = [0] * (max_aura + 1)
            left = 0
            # expand right pointer to first window
            right = 0
            # we will slide v0 over the v coordinates of points
            # for each distinct v0, we consider window [v0, v0+D]
            # we can process in order of v
            while left < len(strip):
                v_left = strip[left][0]
                v_right = v_left + D
                # move right pointer to include all points with v < v_right
                while right < len(strip) and strip[right][0] < v_right:
                    a = strip[right][1]
                    freq[a] += 1
                    right += 1
                # now window contains points with v in [v_left, v_right)
                # but we also need to remove points with v < v_left
                # we will remove them before next iteration
                # compute sum of k smallest auras using freq
                total_count = 0
                s = 0
                for a_val in range(max_aura + 1):
                    cnt_a = freq[a_val]
                    if cnt_a == 0:
                        continue
                    if total_count + cnt_a >= k:
                        need = k - total_count
                        s += need * a_val
                        break
                    else:
                        s += cnt_a * a_val
                        total_count += cnt_a
                # check if this window has at least k points
                if right - left >= k:
                    if best_sum is None or s < best_sum:
                        best_sum = s
                        # collect the actual seats in this window (need the k smallest auras)
                        # we need to output (r,c) not (u,v)
                        # collect all points in the window with their auras
                        candidates = []
                        for idx in range(left, right):
                            v_val, a_val = strip[idx]
                            # recover (r,c)
                            u_val = u0 + (idx // something?) no, we lost u info because strip flattened.
                            # we need to keep u for each point. So we should store (u, v, a) in strip.
                            # Let's rebuild strip with u info
                            pass
                # move left pointer: remove points with v == v_left (since next v_left will be larger)
                while left < len(strip) and strip[left][0] == v_left:
                    a = strip[left][1]
                    freq[a] -= 1
                    left += 1

        # output best_seats
        for r, c in best_seats:
            out_lines.append(f"{r} {c}")

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()