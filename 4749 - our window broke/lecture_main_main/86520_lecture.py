import sys
from collections import defaultdict
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
        res = 0
        while i > 0:
            res += self.bit[i]
            i -= i & -i
        return res
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
def solve(N, M, K, GRID):
    rows = N
    cols = M
    occ_prefix = []
    for r in range(rows):
        row = GRID[r]
        pref = [0] * (cols + 1)
        for c in range(cols):
            pref[c+1] = pref[c] + (1 if row[c] == '#' else 0)
        occ_prefix.append(pref)
    total_occ_per_row = [pref[cols] for pref in occ_prefix]

    points = []
    min_u = float('inf')
    max_u = -float('inf')
    min_v = float('inf')
    max_v = -float('inf')
    for r in range(rows):
        row = GRID[r]
        for c in range(cols):
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
        return [(0,0)] * K

    V_len = max_v - min_v + 1
    v_offset = min_v
    pts = []
    for u, v, w, r, c in points:
        v_idx = v - v_offset
        pts.append((u, v_idx, w, r, c))
    pts.sort(key=lambda x: x[0])
    u_range = max_u - min_u
    v_range = max_v - min_v
    low = 0
    high = max(u_range, v_range)

    def can(D):
        count_v = [0] * V_len
        left = 0
        right = 0
        n_pts = len(pts)
        for u_low in range(min_u, max_u - D + 1):
            while right < n_pts and pts[right][0] <= u_low + D:
                _, v_idx, _, _, _ = pts[right]
                count_v[v_idx] += 1
                right += 1
            while left < n_pts and pts[left][0] < u_low:
                _, v_idx, _, _, _ = pts[left]
                count_v[v_idx] -= 1
                left += 1
            if V_len < D+1:
                continue
            window_sum = sum(count_v[:D+1])
            if window_sum >= K:
                return True
            for v_start in range(1, V_len - D):
                window_sum = window_sum - count_v[v_start-1] + count_v[v_start+D]
                if window_sum >= K:
                    return True
        return False
    while low < high:
        mid = (low + high) // 2
        if can(mid):
            high = mid
        else:
            low = mid + 1
    D_min = low
    u_len = max_u - min_u + 1
    u_offset = min_u
    points_by_u = [[] for _ in range(u_len)]
    for u, v_idx, w, r, c in pts:
        points_by_u[u - u_offset].append((v_idx, w, r, c))
    cur_weight = [-1] * V_len
    u_low = min_u
    for du in range(D_min + 1):
        u_val = u_low + du
        if u_val - u_offset < u_len:
            for (v_idx, w, _, _) in points_by_u[u_val - u_offset]:
                cur_weight[v_idx] = w

    best_sum = float('inf')
    best_u_low = None
    best_v_low = None
    max_weight = M
    v_start_idx = 0
    v_end_idx = V_len - (D_min + 1)
    if v_end_idx < 0:
        pass
    else:
        for u_low in range(min_u, max_u - D_min + 1):
            bit_cnt = BIT(max_weight + 1)
            bit_sum = BIT(max_weight + 1)
            v_low_idx = 0
            for d in range(D_min + 1):
                v_idx = v_low_idx + d
                w = cur_weight[v_idx]
                if w != -1:
                    bit_cnt.add(w, 1)
                    bit_sum.add(w, w)
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
                    best_v_low = min_v + v_low_idx
            for v_low_idx in range(1, v_end_idx + 1):
                old_v = v_low_idx - 1
                w_old = cur_weight[old_v]
                if w_old != -1:
                    bit_cnt.add(w_old, -1)
                    bit_sum.add(w_old, -w_old)
                new_v = v_low_idx + D_min
                w_new = cur_weight[new_v]
                if w_new != -1:
                    bit_cnt.add(w_new, 1)
                    bit_sum.add(w_new, w_new)
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
                        best_v_low = min_v + v_low_idx
            u_remove = u_low
            if u_remove - u_offset < u_len:
                for (v_idx, _, _, _) in points_by_u[u_remove - u_offset]:
                    cur_weight[v_idx] = -1
            u_add = u_low + D_min + 1
            if u_add - u_offset < u_len:
                for (v_idx, w, _, _) in points_by_u[u_add - u_offset]:
                    cur_weight[v_idx] = w
    result = []
    u_low = best_u_low
    v_low = best_v_low
    u_high = u_low + D_min
    v_high = v_low + D_min
    candidates = []
    for (u, v_idx, w, r, c) in pts:
        if u_low <= u <= u_high and v_low <= (v_idx + v_offset) <= v_high:
            candidates.append((w, r, c))
    candidates.sort(key=lambda x: x[0])
    for i in range(K):
        _, r, c = candidates[i]
        result.append((r, c))
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
        grid = []
        for __ in range(N):
            grid.append(next(it))
        seats = solve(N, M, K, grid)
        for r, c in seats:
            out_lines.append(f"{r} {c}")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()