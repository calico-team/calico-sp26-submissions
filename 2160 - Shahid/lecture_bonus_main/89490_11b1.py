import sys
import heapq

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
                    aura = min(left, right)
                    seats.append((r, c, aura))
                elif ch == '#':
                    occ_left += 1

        # transform to (u, v) where u = r+c, v = r-c + (m-1)
        offset = m - 1
        points = []  # list of (u, v, aura)
        for r, c, aura in seats:
            u = r + c
            v = r - c + offset
            points.append((u, v, aura))

        if not points:
            # no seats, but problem guarantees K <= available seats
            continue

        # find max u and v
        max_u = max(p[0] for p in points)
        max_v = max(p[1] for p in points)
        U = max_u + 1
        V = max_v + 1

        # build count grid (1 if seat exists)
        cnt = [[0] * V for _ in range(U)]
        aura_grid = [[-1] * V for _ in range(U)]  # -1 means no seat
        for u, v, a in points:
            cnt[u][v] = 1
            aura_grid[u][v] = a

        # 2D prefix sum for counts
        pre = [[0] * (V + 1) for _ in range(U + 1)]
        for i in range(U):
            row_sum = 0
            for j in range(V):
                row_sum += cnt[i][j]
                pre[i + 1][j + 1] = pre[i][j + 1] + row_sum

        # binary search for minimal D (side length in u,v space)
        lo, hi = 0, max(U, V)
        while lo < hi:
            mid = (lo + hi) // 2
            side = mid
            ok = False
            if side <= U and side <= V:
                for i in range(U - side + 1):
                    for j in range(V - side + 1):
                        total = (pre[i + side][j + side] - pre[i][j + side]
                                 - pre[i + side][j] + pre[i][j])
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
        # now find the square with minimal sum of k smallest aura
        best_sum = None
        best_seats = []

        # Precompute for each row u the list of (v, aura) sorted by v
        row_points = [[] for _ in range(U)]
        for u, v, a in points:
            row_points[u].append((v, a))
        for u in range(U):
            row_points[u].sort()

        # iterate over all squares of side D
        for i in range(U - D + 1):
            # For each i, we will collect all points in rows i..i+D-1
            # We can maintain a sliding window over columns
            # But for simplicity, we iterate over all j and collect points
            # using binary search in each row
            for j in range(V - D + 1):
                # collect all points in rectangle [i, i+D-1] x [j, j+D-1]
                pts = []
                for u in range(i, i + D):
                    # find points with v in [j, j+D-1]
                    row = row_points[u]
                    # binary search
                    lo_v = j
                    hi_v = j + D - 1
                    left = bisect_left(row, (lo_v, -1))
                    right = bisect_right(row, (hi_v, 10**9)) - 1
                    for idx in range(left, right + 1):
                        pts.append(row[idx][1])
                if len(pts) < k:
                    continue
                # find sum of k smallest
                if k == 1:
                    s = min(pts)
                else:
                    # use nth_element via heap
                    heap = [-x for x in pts[:k]]
                    heapq.heapify(heap)
                    for val in pts[k:]:
                        if -heap[0] > val:
                            heapq.heapreplace(heap, -val)
                    s = -sum(heap)
                if best_sum is None or s < best_sum:
                    best_sum = s
                    # store coordinates of the k smallest seats in this square
                    # we need to output actual (r,c)
                    # collect all points in square with their (r,c,aura)
                    candidates = []
                    for u in range(i, i + D):
                        lo_v = j
                        hi_v = j + D - 1
                        left = bisect_left(row_points[u], (lo_v, -1))
                        right = bisect_right(row_points[u], (hi_v, 10**9)) - 1
                        for idx in range(left, right + 1):
                            v_val, aura_val = row_points[u][idx]
                            # recover (r,c) from u, v
                            # u = r+c, v = r-c+offset => r = (u+v-offset)//2, c = (u-v+offset)//2
                            r = (u + v_val - offset) // 2
                            c = (u - v_val + offset) // 2
                            candidates.append((aura_val, r, c))
                    # select k smallest by aura
                    candidates.sort()
                    best_seats = [(r, c) for _, r, c in candidates[:k]]

        # output
        for r, c in best_seats:
            out_lines.append(f"{r} {c}")

    sys.stdout.write("\n".join(out_lines))

# helper for binary search
def bisect_left(arr, x):
    lo, hi = 0, len(arr)
    while lo < hi:
        mid = (lo + hi) // 2
        if arr[mid][0] < x[0]:
            lo = mid + 1
        else:
            hi = mid
    return lo

def bisect_right(arr, x):
    lo, hi = 0, len(arr)
    while lo < hi:
        mid = (lo + hi) // 2
        if arr[mid][0] <= x[0]:
            lo = mid + 1
        else:
            hi = mid
    return lo

if __name__ == "__main__":
    solve()