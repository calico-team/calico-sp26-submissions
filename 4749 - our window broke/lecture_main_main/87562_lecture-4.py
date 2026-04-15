import sys

def solve(N, M, K, GRID):
    occ_prefix = []
    for r in range(N):
        row = GRID[r]
        pref = [0] * (M + 1)
        for c in range(M):
            pref[c + 1] = pref[c] + (1 if row[c] == '#' else 0)
        occ_prefix.append(pref)
    total_occ = [pref[M] for pref in occ_prefix]

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
                right = total_occ[r] - occ_prefix[r][c + 1]
                aura = left if left < right else right
                u = r + c
                v = r - c
                points.append((u, v, aura, r, c))
                if u < min_u: min_u = u
                if u > max_u: max_u = u
                if v < min_v: min_v = v
                if v > max_v: max_v = v

    if not points:
        return [(0, 0)] * K
    points.sort(key=lambda x: x[0])
    u_range = max_u - min_u
    v_range = max_v - min_v
    lo, hi = 0, max(u_range, v_range)
    def can(D):
        v_len = max_v - min_v + 1
        cnt_v = [0] * v_len
        left = 0
        right = 0
        n = len(points)
        for u_low in range(min_u, max_u - D + 1):
            u_high = u_low + D
            while right < n and points[right][0] <= u_high:
                _, v, _, _, _ = points[right]
                cnt_v[v - min_v] += 1
                right += 1
            while left < n and points[left][0] < u_low:
                _, v, _, _, _ = points[left]
                cnt_v[v - min_v] -= 1
                left += 1
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
    v_len = max_v - min_v + 1
    v_off = min_v
    u_len = max_u - min_u + 1
    u_off = min_u
    points_by_u = [[] for _ in range(u_len)]
    for u, v, aura, _, _ in points:
        points_by_u[u - u_off].append((v, aura))

    best_sum = 10**18
    best_u_low = None
    best_v_low = None
    for u_low in range(min_u, max_u - D_min + 1):
        u_high = u_low + D_min
        strip = []
        for u_val in range(u_low, u_high + 1):
            if u_val - u_off < 0 or u_val - u_off >= u_len:
                continue
            strip.extend(points_by_u[u_val - u_off])
        if not strip:
            continue
        strip.sort(key=lambda x: x[0])
        left = 0
        right = 0
        n_strip = len(strip)
        max_aura = M
        bit_cnt = [0] * (max_aura + 2)
        bit_sum = [0] * (max_aura + 2)

        def bit_add(idx, delta):
            i = idx + 1
            while i <= max_aura + 1:
                bit_cnt[i] += delta
                bit_sum[i] += delta * idx
                i += i & -i

        def bit_prefix_cnt(idx):
            i = idx + 1
            s = 0
            while i > 0:
                s += bit_cnt[i]
                i -= i & -i
            return s

        def bit_prefix_sum(idx):
            i = idx + 1
            s = 0
            while i > 0:
                s += bit_sum[i]
                i -= i & -i
            return s
        v_low = min_v
        v_high = v_low + D_min
        while right < n_strip and strip[right][0] <= v_high:
            _, aura = strip[right]
            bit_add(aura, 1)
            right += 1
        total = bit_prefix_cnt(max_aura)
        if total >= K:
            need = K
            lo_aura, hi_aura = 0, max_aura
            while lo_aura < hi_aura:
                mid_aura = (lo_aura + hi_aura) // 2
                if bit_prefix_cnt(mid_aura) >= need:
                    hi_aura = mid_aura
                else:
                    lo_aura = mid_aura + 1
            thresh = lo_aura
            cnt_less = bit_prefix_cnt(thresh - 1) if thresh > 0 else 0
            sum_less = bit_prefix_sum(thresh - 1) if thresh > 0 else 0
            cur_sum = sum_less + (need - cnt_less) * thresh
            if cur_sum < best_sum:
                best_sum = cur_sum
                best_u_low = u_low
                best_v_low = v_low
                if best_sum == 0:
                    break
        for v_low in range(min_v + 1, max_v - D_min + 1):
            v_high = v_low + D_min
            while left < right and strip[left][0] < v_low:
                _, aura = strip[left]
                bit_add(aura, -1)
                left += 1
            while right < n_strip and strip[right][0] <= v_high:
                _, aura = strip[right]
                bit_add(aura, 1)
                right += 1
            total = bit_prefix_cnt(max_aura)
            if total >= K:
                need = K
                lo_aura, hi_aura = 0, max_aura
                while lo_aura < hi_aura:
                    mid_aura = (lo_aura + hi_aura) // 2
                    if bit_prefix_cnt(mid_aura) >= need:
                        hi_aura = mid_aura
                    else:
                        lo_aura = mid_aura + 1
                thresh = lo_aura
                cnt_less = bit_prefix_cnt(thresh - 1) if thresh > 0 else 0
                sum_less = bit_prefix_sum(thresh - 1) if thresh > 0 else 0
                cur_sum = sum_less + (need - cnt_less) * thresh
                if cur_sum < best_sum:
                    best_sum = cur_sum
                    best_u_low = u_low
                    best_v_low = v_low
                    if best_sum == 0:
                        break
        if best_sum == 0:
            break
    u_low = best_u_low
    u_high = u_low + D_min
    v_low = best_v_low
    v_high = v_low + D_min
    candidates = []
    for u, v, aura, r, c in points:
        if u_low <= u <= u_high and v_low <= v <= v_high:
            candidates.append((aura, r, c))
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