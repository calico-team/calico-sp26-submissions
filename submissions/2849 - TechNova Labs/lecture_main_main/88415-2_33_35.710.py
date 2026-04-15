import sys


def build_prefix(grid):
    rows = len(grid)
    columns = len(grid[0]) if rows else 0
    pref = [[0] * (columns + 1) for _ in range(rows + 1)]

    for r in range(rows):
        rows_running = 0
        for c in range(columns):
            rows_running += grid[r][c]
            pref[r + 1][c + 1] = pref[r][c + 1] + rows_running

    return pref


def My_sum(pref, r1, c1, r2, c2):
    if r1 > r2 or c1 > c2:
        return 0
    return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1]


def solve(N, M, K, GRID):
    """Return K seat coordinates minimizing max Manhattan distance.

    This implementation also uses aura as a tie-break among candidate windows.
    """
    johnny_d_lecture = GRID

    whole_after_seat = []
    for r in range(N):
        row = GRID[r]
        l_block = [0] * M
        r_block = [0] * M

        blocked = 0
        for c in range(M):
            l_block[c] = blocked
            if row[c] == '#':
                blocked += 1

        blocked = 0
        for c in range(M - 1, -1, -1):
            r_block[c] = blocked
            if row[c] == '#':
                blocked += 1

        for c in range(M):
            if row[c] == '-':
                aura = min(l_block[c], r_block[c])
                whole_after_seat.append((r, c, aura))

    if K == 0:
        return []

    side = N + M - 1
    offset = M - 1
    count_grids = [[0] * side for _ in range(side)]
    auras_grids = [[0] * side for _ in range(side)]
    transformative_points = []





    for r, c, w in whole_after_seat:
        u = r + c
        v = r - c + offset
        count_grids[u][v] = 1
        auras_grids[u][v] = w
        transformative_points.append((u, v, r, c, w))

    count_preference = build_prefix(count_grids)
    aura_preference = build_prefix(auras_grids)

    def windows_in_exists(window_size):
        limit = side - window_size
        for u0 in range(limit):
            u1 = u0 + window_size
            for v0 in range(limit):
                v1 = v0 + window_size
                if My_sum(count_preference, u0, v0, u1, v1) >= K:
                    return True
        return False

    lo, hi = 0, side - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if windows_in_exists(mid):
            hi = mid
        else:
            lo = mid + 1
    best_sizes = lo

    best_windows = None
    best_windows_auras = 10**30
    limit = side - best_sizes

    for u0 in range(limit):
        u1 = u0 + best_sizes
        for v0 in range(limit):
            v1 = v0 + best_sizes
            if My_sum(count_preference, u0, v0, u1, v1) < K:
                continue
            total_aura = My_sum(aura_preference, u0, v0, u1, v1)
            if total_aura < best_windows_auras:
                best_windows_auras = total_aura
                best_windows = (u0, u1, v0, v1)

    u0, u1, v0, v1 = best_windows
    candidates = []

    for u, v, r, c, w in transformative_points:
        if u0 <= u <= u1 and v0 <= v <= v1:
            candidates.append((w, r, c))

    candidates.sort()
    return [(r, c) for _, r, c in candidates[:K]]


def read_inp():
    tok = sys.stdin.read().split()
    if not tok:
        return []
    it = iter(tok)
    t = int(next(it))
    out = []
    for _ in range(t):
        n = int(next(it))
        m = int(next(it))
        k = int(next(it))
        g = [next(it) for _ in range(n)]
        out.append((n, m, k, g))
    return out


def main():
    out = []
    for n, m, k, g in read_inp():
        for r, c in solve(n, m, k, g):
            out.append(f"{r} {c}")
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()
