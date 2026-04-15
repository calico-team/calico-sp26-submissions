import sys

def solve(N, M, K, GRID):
    occ_prefix = []
    for r in range(N):
        row = GRID[r]
        pref = [0] * (M + 1)
        for c in range(M):
            pref[c+1] = pref[c] + (1 if row[c] == '#' else 0)
        occ_prefix.append(pref)
    total_occ_per_row = [pref[M] for pref in occ_prefix]
    points = []
    min_u = 10**9
    max_u = -10**9
    min_v = 10**9
    max_v = -10**9
    for r in range(N):
        row = GRID[r]
        for c in range(M):
            if row[c] == '-':
                left = occ_prefix[r][c]
                right = total_occ_per_row[r] - occ_prefix[r][c+1]
                aura = min(left, right)
                u = r + c
                v = r - c
                points.append((u, v, aura, r, c))
                if u < min_u: min_u = u
                if u > max_u: max_u = u
                if v < min_v: min_v = v
                if v > max_v: max_v = v

    if not points:
        return [(0, 0)] * K
    u_range = max_u - min_u
    v_range = max_v - min_v
    lo, hi = 0, max(u_range, v_range)
    u_len = max_u - min_u + 1
    u_offset = min_u
    pts_by_u = [[] for _ in range(u_len)]
    for u, v, w, r, c in points:
        pts_by_u[u - u_offset].append((v, w, r, c))
    def can(D):
        v_len = max_v - min_v + 1
        v_off = min_v
        cnt_v = [0] * v_len
        pts_sorted = sorted(points, key=lambda x: x[0])
        left_u = 0
        right_u = 0
        n_pts = len(pts_sorted)
        if D >= u_range:
            u_starts = [min_u]
        else:
            u_starts = range(min_u, max_u - D + 1)
        for u_low in u_starts:
            u_high = u_low + D
            while right_u < n_pts and pts_sorted[right_u][0] <= u_high:
                _, v, _, _, _ = pts_sorted[right_u]
                cnt_v[v - v_off] += 1
                right_u += 1
            while left_u < n_pts and pts_sorted[left_u][0] < u_low:
                _, v, _, _, _ = pts_sorted[left_u]
                cnt_v[v - v_off] -= 1
                left_u += 1
            if D >= v_range:
                if sum(cnt_v) >= K:
                    return True
            else:
                window_sum = sum(cnt_v[:D+1])
                if window_sum >= K:
                    return True
                for v_low in range(1, v_len - D):
                    window_sum = window_sum - cnt_v[v_low-1] + cnt_v[v_low+D]
                    if window_sum >= K:
                        return True
        return False

    while lo < hi:
        mid = (lo + hi) // 2
        if can(mid):
            hi = mid
        else:
            lo = mid + 1
    D_min = lo
    max_aura = M
    v_len = max_v - min_v + 1
    v_off = min_v
    class BIT:
        def __init__(self, size):
            self.n = size
            self.bit = [0] * (size + 1)
        def add(self, idx, delta):
            i = idx + 1
            while i <= self.n:
                self.bit[i] += delta
                i += i & -i
        def sum(self, idx):
            i = idx + 1
            s = 0
            while i > 0:
                s += self.bit[i]
                i -= i & -i
            return s
        def total(self):
            return self.sum(self.n - 1)
        def kth(self, k):
            idx = 0
            bit_mask = 1 << (self.n.bit_length())
            while bit_mask:
                nxt = idx + bit_mask
                if nxt <= self.n and self.bit[nxt] < k:
                    k -= self.bit[nxt]
                    idx = nxt
                bit_mask >>= 1
            return idx
    points_sorted = sorted(points, key=lambda x: x[0])
    pts_by_u = [[] for _ in range(u_len)]
    for u, v, w, r, c in points:
        pts_by_u[u - u_offset].append((v, w, r, c))

    best_sum = 10**18
    best_u_low = None
    best_v_low = None

    if D_min >= u_range:
        u_starts = [min_u]
    else:
        u_starts = range(min_u, max_u - D_min + 1)

    for u_low in u_starts:
        u_high = u_low + D_min
        u_points = []
        for u_val in range(u_low, u_high + 1):
            idx = u_val - u_offset
            if 0 <= idx < u_len:
                for v, w, r, c in pts_by_u[idx]:
                    u_points.append((v, w, r, c))
        if not u_points:
            continue
        u_points.sort(key=lambda x: x[0])
        left = 0
        right = 0
        bit_cnt = BIT(max_aura + 1)
        bit_sum = BIT(max_aura + 1)
        v_low = min_v
        v_high = v_low + D_min
        while right < len(u_points) and u_points[right][0] <= v_high:
            _, w, _, _ = u_points[right]
            bit_cnt.add(w, 1)
            bit_sum.add(w, w)
            right += 1
        total = bit_cnt.total()
        if total >= K:
            need = K
            idx_1based = bit_cnt.kth(need)
            w_thresh = idx_1based - 1
            cnt_less = bit_cnt.sum(w_thresh - 1) if w_thresh > 0 else 0
            sum_less = bit_sum.sum(w_thresh - 1) if w_thresh > 0 else 0
            cur_sum = sum_less + (need - cnt_less) * w_thresh
            if cur_sum < best_sum:
                best_sum = cur_sum
                best_u_low = u_low
                best_v_low = v_low
        if D_min < v_range:
            for v_low in range(min_v + 1, max_v - D_min + 1):
                v_high = v_low + D_min
                while left < right and u_points[left][0] < v_low:
                    _, w, _, _ = u_points[left]
                    bit_cnt.add(w, -1)
                    bit_sum.add(w, -w)
                    left += 1
                while right < len(u_points) and u_points[right][0] <= v_high:
                    _, w, _, _ = u_points[right]
                    bit_cnt.add(w, 1)
                    bit_sum.add(w, w)
                    right += 1
                total = bit_cnt.total()
                if total >= K:
                    need = K
                    idx_1based = bit_cnt.kth(need)
                    w_thresh = idx_1based - 1
                    cnt_less = bit_cnt.sum(w_thresh - 1) if w_thresh > 0 else 0
                    sum_less = bit_sum.sum(w_thresh - 1) if w_thresh > 0 else 0
                    cur_sum = sum_less + (need - cnt_less) * w_thresh
                    if cur_sum < best_sum:
                        best_sum = cur_sum
                        best_u_low = u_low
                        best_v_low = v_low
    u_low = best_u_low
    v_low = best_v_low
    u_high = u_low + D_min
    v_high = v_low + D_min
    candidates = []
    for u, v, w, r, c in points:
        if u_low <= u <= u_high and v_low <= v <= v_high:
            candidates.append((w, r, c))
    candidates.sort(key=lambda x: x[0])
    result = [(r, c) for _, r, c in candidates[:K]]
    return result

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        N = int(next(it))
        M = int(next(it))
        K = int(next(it))
        grid = [next(it) for __ in range(N)]
        seats = solve(N, M, K, grid)
        for r, c in seats:
            out_lines.append(f"{r} {c}")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()