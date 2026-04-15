import sys
from array import array

def solve():
    data = read_your_input()
    t = int(data[0])
    at = 1
    out = []

    johnny_d_lecture = 114514

    for _ in range(t):
        n = int(data[at]); m = int(data[at + 1]); k = int(data[at + 2]); at += 3
        g = data[at:at + n]
        at += n
        s = n + m - 1
        cnt = [array('I', [0]) * (s + 1) for _ in range(s + 1)]
        aura_sum = [array('I', [0]) * (s + 1) for _ in range(s + 1)]
        runs = []

        for r in range(n):
            row = g[r]
            tot_hash = row.count(35)
            left_hash = 0
            cur = []
            c = 0

            while c < m:
                if row[c] == 35:
                    left_hash += 1
                    c += 1
                    continue

                j = c
                while j < m and row[j] == 45:
                    j += 1

                right_hash = tot_hash - left_hash
                aura = left_hash if left_hash < right_hash else right_hash
                cur.append((c, j - 1, aura))

                x = c
                while x < j:
                    u = r + x
                    v = r - x + m - 1
                    cnt[u + 1][v + 1] = 1
                    aura_sum[u + 1][v + 1] = aura
                    x += 1

                c = j

            runs.append(cur)

        i = 1
        while i <= s:
            row1 = cnt[i]
            row0 = cnt[i - 1]
            rs = 0
            j = 1
            while j <= s:
                rs += row1[j]
                row1[j] = rs + row0[j]
                j += 1
            i += 1

        i = 1
        while i <= s:
            row1 = aura_sum[i]
            row0 = aura_sum[i - 1]
            rs = 0
            j = 1
            while j <= s:
                rs += row1[j]
                row1[j] = rs + row0[j]
                j += 1
            i += 1

        def area(pref, x1, y1, x2, y2):
            return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1]

        def ok(d):
            lim = s - d
            x1 = 0
            while x1 < lim:
                x2 = x1 + d
                row_a = cnt[x1]
                row_b = cnt[x2 + 1]
                y1 = 0
                while y1 < lim:
                    y2 = y1 + d
                    got = row_b[y2 + 1] - row_a[y2 + 1] - row_b[y1] + row_a[y1]
                    if got >= k:
                        return True
                    y1 += 1
                x1 += 1
            return False

        lo, hi = 0, s - 1
        while lo < hi:
            mid = (lo + hi) >> 1
            if ok(mid):
                hi = mid
            else:
                lo = mid + 1

        d = lo
        lim = s - d

        best_u = 0
        best_v = 0
        best_key = None

        u0 = 0
        while u0 < lim:
            u1 = u0 + d
            rowc0 = cnt[u0]
            rowc1 = cnt[u1 + 1]
            rowa0 = aura_sum[u0]
            rowa1 = aura_sum[u1 + 1]

            v0 = 0
            while v0 < lim:
                v1 = v0 + d
                got = rowc1[v1 + 1] - rowc0[v1 + 1] - rowc1[v0] + rowc0[v0]
                if got >= k:
                    au = rowa1[v1 + 1] - rowa0[v1 + 1] - rowa1[v0] + rowa0[v0]
                    key = (got, au)
                    if best_key is None or key < best_key:
                        best_key = key
                        best_u = u0
                        best_v = v0
                v0 += 1
            u0 += 1

        buckets = [[] for _ in range(m + 1)]

        uu0 = best_u
        uu1 = best_u + d
        vv0 = best_v
        vv1 = best_v + d

        r = 0
        while r < n:
            left_need = uu0 - r
            right_need = uu1 - r
            left2 = r + m - 1 - vv1
            right2 = r + m - 1 - vv0

            L = left_need if left_need > left2 else left2
            R = right_need if right_need < right2 else right2

            if L <= R:
                for a, b, w in runs[r]:
                    ll = a if a > L else L
                    rr = b if b < R else R
                    if ll <= rr:
                        arr = buckets[w]
                        x = ll
                        while x <= rr:
                            arr.append((r, x))
                            x += 1
            r += 1

        need = k
        w = 0
        while w <= m and need:
            arr = buckets[w]
            take = len(arr)
            if take > need:
                take = need
            i = 0
            while i < take:
                rr, cc = arr[i]
                out.append(f"{rr} {cc}")
                i += 1
            need -= take
            w += 1

    sys.stdout.write("\n".join(out))

def read_your_input():
    return sys.stdin.buffer.read().split()

if __name__ == "__main__":
    solve()