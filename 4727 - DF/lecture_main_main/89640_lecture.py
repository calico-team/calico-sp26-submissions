import sys


def build_prefix(count_grid):
    h = len(count_grid)
    w = len(count_grid[0])
    pref = [[0] * (w + 1) for _ in range(h + 1)]
    for i in range(h):
        row_pref = pref[i + 1]
        prev_pref = pref[i]
        row = count_grid[i]
        s = 0
        for j in range(w):
            s += row[j]
            row_pref[j + 1] = prev_pref[j + 1] + s
    return pref


def rect_sum(pref, r1, c1, r2, c2):
    return (
        pref[r2 + 1][c2 + 1]
        - pref[r1][c2 + 1]
        - pref[r2 + 1][c1]
        + pref[r1][c1]
    )


def solve_one(n, m, k, grid):
    empty = []
    size = n + m - 1
    v_off = m - 1

    count_grid = [[0] * size for _ in range(size)]

    for r in range(n):
        row = grid[r]
        for c in range(m):
            if row[c] == '-':
                u = r + c
                v = r - c + v_off
                empty.append((r, c, u, v))
                count_grid[u][v] = 1

    pref = build_prefix(count_grid)

    def exists(d):
        lim = size - d
        for u0 in range(lim):
            u1 = u0 + d
            row_pref_top = u0
            row_pref_bot = u1
            for v0 in range(lim):
                v1 = v0 + d
                if rect_sum(pref, row_pref_top, v0, row_pref_bot, v1) >= k:
                    return True
        return False

    lo, hi = 0, size - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if exists(mid):
            hi = mid
        else:
            lo = mid + 1
    best_d = lo

    lim = size - best_d
    best_box = None
    for u0 in range(lim):
        u1 = u0 + best_d
        for v0 in range(lim):
            v1 = v0 + best_d
            if rect_sum(pref, u0, v0, u1, v1) >= k:
                best_box = (u0, v0, u1, v1)
                break
        if best_box is not None:
            break

    u0, v0, u1, v1 = best_box
    ans = []
    for r, c, u, v in empty:
        if u0 <= u <= u1 and v0 <= v <= v1:
            ans.append((r, c))
            if len(ans) == k:
                break

    return ans


def main():
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out = []
    for _ in range(t):
        n = int(next(it))
        m = int(next(it))
        k = int(next(it))
        grid = [next(it) for _ in range(n)]
        ans = solve_one(n, m, k, grid)
        for r, c in ans:
            out.append(f"{r} {c}")
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()