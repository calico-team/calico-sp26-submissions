from bisect import bisect_left, bisect_right

class BIT:
    def __init__(self, n):
        self.n = n
        self.t = [0] * (n + 1)

    def add(self, i, delta):
        n = self.n
        t = self.t
        while i <= n:
            t[i] += delta
            i += i & -i

    def sum(self, i):
        t = self.t
        s = 0
        while i > 0:
            s += t[i]
            i -= i & -i
        return s

    def kth(self, k):
        idx = 0
        bit = 1 << (self.n.bit_length() - 1)
        t = self.t
        while bit:
            nxt = idx + bit
            if nxt <= self.n and t[nxt] < k:
                idx = nxt
                k -= t[nxt]
            bit >>= 1
        return idx + 1
    
def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    total = N + M - 1
    shift = M - 1

    seats = [[] for _ in range(total)]
    seat_list = []
    aura_vals = []

    for r in range(N):
        row = GRID[r]
        occ = row.count('#')
        left = 0
        for c, ch in enumerate(row):
            if ch == '#':
                left += 1
            else:
                aura = left if left < occ - left else occ - left
                u = r + c
                v = r - c + shift
                seats[u].append(v)
                seat_list.append((u, v, aura, r, c))
                aura_vals.append(aura)

    aura_vals = sorted(set(aura_vals))
    aura_id = {x: i + 1 for i, x in enumerate(aura_vals)}
    A = len(aura_vals)

    row_points = [[] for _ in range(total)]
    col_points = [[] for _ in range(total)]

    for u, v, aura, r, c in seat_list:
        idx = aura_id[aura]
        row_points[u].append((v, aura, idx, r, c))
        col_points[v].append((u, aura, idx))

    row_vs = []
    col_us = []

    for u in range(total):
        row_points[u].sort()
        row_vs.append([x[0] for x in row_points[u]])

    for v in range(total):
        col_points[v].sort()
        col_us.append([x[0] for x in col_points[v]])

    def find_any(d):
        L = total - d
        w = d + 1
        cnt_v = [0] * total
        right_u = -1

        for left_u in range(L):
            lim = left_u + d
            while right_u < lim:
                right_u += 1
                for v in seats[right_u]:
                    cnt_v[v] += 1

            cur = 0
            for i in range(w):
                cur += cnt_v[i]
            if cur >= K:
                return left_u, 0

            for sv in range(1, L):
                cur += cnt_v[sv + w - 1] - cnt_v[sv - 1]
                if cur >= K:
                    return left_u, sv

            for v in seats[left_u]:
                cnt_v[v] -= 1

        return None

    lo, hi = 0, total - 1
    best_d = total - 1
    while lo <= hi:
        mid = (lo + hi) >> 1
        if find_any(mid) is not None:
            best_d = mid
            hi = mid - 1
        else:
            lo = mid + 1

    w = best_d + 1
    L = total - best_d

    bit_cnt = BIT(A)
    bit_sum = BIT(A)

    def add_point(idx, aura):
        bit_cnt.add(idx, 1)
        bit_sum.add(idx, aura)

    def remove_point(idx, aura):
        bit_cnt.add(idx, -1)
        bit_sum.add(idx, -aura)

    def kth_sum(k):
        p = bit_cnt.kth(k)
        cnt_before = bit_cnt.sum(p - 1)
        sum_before = bit_sum.sum(p - 1)
        val = aura_vals[p - 1]
        need = k - cnt_before
        return sum_before + need * val

    cur_cnt = 0

    u0 = 0
    v0 = 0
    v1 = best_d

    for u in range(w):
        arr = row_points[u]
        vals = row_vs[u]
        l = bisect_left(vals, 0)
        r = bisect_right(vals, v1)
        cur_cnt += r - l
        for i in range(l, r):
            aura = arr[i][1]
            idx = arr[i][2]
            add_point(idx, aura)

    best_sum = None
    best_window = None

    cur_v0 = 0

    for cur_u0 in range(L):
        if cur_cnt >= K:
            s = kth_sum(K)
            if best_sum is None or s < best_sum:
                best_sum = s
                best_window = (cur_u0, cur_v0)

        if cur_u0 & 1 == 0:
            while cur_v0 + 1 < L:
                out_v = cur_v0
                in_v = cur_v0 + w
                uu = col_us[out_v]
                arr = col_points[out_v]
                l = bisect_left(uu, cur_u0)
                r = bisect_right(uu, cur_u0 + best_d)
                cur_cnt -= (r - l)
                for i in range(l, r):
                    aura = arr[i][1]
                    idx = arr[i][2]
                    remove_point(idx, aura)

                uu = col_us[in_v]
                arr = col_points[in_v]
                l = bisect_left(uu, cur_u0)
                r = bisect_right(uu, cur_u0 + best_d)
                cur_cnt += (r - l)
                for i in range(l, r):
                    aura = arr[i][1]
                    idx = arr[i][2]
                    add_point(idx, aura)

                cur_v0 += 1
                if cur_cnt >= K:
                    s = kth_sum(K)
                    if best_sum is None or s < best_sum:
                        best_sum = s
                        best_window = (cur_u0, cur_v0)
        else:
            while cur_v0 - 1 >= 0:
                out_v = cur_v0 + best_d
                in_v = cur_v0 - 1
                uu = col_us[out_v]
                arr = col_points[out_v]
                l = bisect_left(uu, cur_u0)
                r = bisect_right(uu, cur_u0 + best_d)
                cur_cnt -= (r - l)
                for i in range(l, r):
                    aura = arr[i][1]
                    idx = arr[i][2]
                    remove_point(idx, aura)

                uu = col_us[in_v]
                arr = col_points[in_v]
                l = bisect_left(uu, cur_u0)
                r = bisect_right(uu, cur_u0 + best_d)
                cur_cnt += (r - l)
                for i in range(l, r):
                    aura = arr[i][1]
                    idx = arr[i][2]
                    add_point(idx, aura)

                cur_v0 -= 1
                if cur_cnt >= K:
                    s = kth_sum(K)
                    if best_sum is None or s < best_sum:
                        best_sum = s
                        best_window = (cur_u0, cur_v0)

        if cur_u0 + 1 == L:
            break

        out_u = cur_u0
        in_u = cur_u0 + w
        left_v = cur_v0
        right_v = cur_v0 + best_d

        arr = row_points[out_u]
        vals = row_vs[out_u]
        l = bisect_left(vals, left_v)
        r = bisect_right(vals, right_v)
        cur_cnt -= (r - l)
        for i in range(l, r):
            aura = arr[i][1]
            idx = arr[i][2]
            remove_point(idx, aura)

        arr = row_points[in_u]
        vals = row_vs[in_u]
        l = bisect_left(vals, left_v)
        r = bisect_right(vals, right_v)
        cur_cnt += (r - l)
        for i in range(l, r):
            aura = arr[i][1]
            idx = arr[i][2]
            add_point(idx, aura)

    u0, v0 = best_window
    v1 = v0 + best_d
    cand = []

    for u in range(u0, u0 + w):
        arr = row_points[u]
        vals = row_vs[u]
        l = bisect_left(vals, v0)
        r = bisect_right(vals, v1)
        for i in range(l, r):
            cand.append((arr[i][1], arr[i][3], arr[i][4]))

    cand.sort()
    return [(cand[i][1], cand[i][2]) for i in range(K)]



def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = []
        for _ in range(N):
            GRID.append(input().strip())
        result = solve(N, M, K, GRID)
        for r, c in result:
            print(f"{r} {c}")


if __name__ == '__main__':
    main()
