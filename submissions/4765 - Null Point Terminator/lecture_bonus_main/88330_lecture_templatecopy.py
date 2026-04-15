def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    total = N + M - 1
    shift = M - 1

    points = [[] for _ in range(total)]
    max_aura = 0

    for r in range(N):
        row = GRID[r]
        occ = row.count('#')
        left = 0
        for c in range(M):
            ch = row[c]
            if ch == '#':
                left += 1
            else:
                aura = left if left < occ - left else occ - left
                u = r + c
                v = r - c + shift
                points[u].append((v, aura, r, c))
                if aura > max_aura:
                    max_aura = aura

    for u in range(total):
        points[u].sort()

    def find_any(d):
        cnt_v = [0] * total
        right_u = -1
        w = d + 1
        L = total - d

        for left_u in range(L):
            lim = left_u + d
            while right_u < lim:
                right_u += 1
                for v, _, _, _ in points[right_u]:
                    cnt_v[v] += 1

            cur = sum(cnt_v[:w])
            if cur >= K:
                return True

            for sv in range(1, L):
                cur += cnt_v[sv + w - 1] - cnt_v[sv - 1]
                if cur >= K:
                    return True

            for v, _, _, _ in points[left_u]:
                cnt_v[v] -= 1

        return False

    lo, hi = 0, total - 1
    best_d = total - 1
    while lo <= hi:
        mid = (lo + hi) >> 1
        if find_any(mid):
            best_d = mid
            hi = mid - 1
        else:
            lo = mid + 1

    L = total - best_d
    w = best_d + 1
    cnt_v = [0] * total
    curr_col_aura = [[0] * (max_aura + 1) for _ in range(total)]
    right_u = -1
    best_sum = None
    best_window = None

    def window_k_sum(freq):
        rem = K
        s = 0
        for aura_val, count in enumerate(freq):
            if not count:
                continue
            if count >= rem:
                s += aura_val * rem
                return s
            s += aura_val * count
            rem -= count
        return s

    for left_u in range(L):
        lim = left_u + best_d
        while right_u < lim:
            right_u += 1
            for v, aura, _, _ in points[right_u]:
                cnt_v[v] += 1
                curr_col_aura[v][aura] += 1

        freq = [0] * (max_aura + 1)
        cur = 0
        for v in range(w):
            cur += cnt_v[v]
            row = curr_col_aura[v]
            for aura_val, count in enumerate(row):
                if count:
                    freq[aura_val] += count

        if cur >= K:
            s = window_k_sum(freq)
            if best_sum is None or s < best_sum:
                best_sum = s
                best_window = (left_u, 0)

        for v0 in range(1, L):
            remove_v = v0 - 1
            add_v = v0 + w - 1
            cur += cnt_v[add_v] - cnt_v[remove_v]
            row = curr_col_aura[remove_v]
            for aura_val, count in enumerate(row):
                if count:
                    freq[aura_val] -= count
            row = curr_col_aura[add_v]
            for aura_val, count in enumerate(row):
                if count:
                    freq[aura_val] += count

            if cur >= K:
                s = window_k_sum(freq)
                if best_sum is None or s < best_sum:
                    best_sum = s
                    best_window = (left_u, v0)

        for v, aura, _, _ in points[left_u]:
            cnt_v[v] -= 1
            curr_col_aura[v][aura] -= 1

    if best_window is None:
        result = []
        for r in range(N):
            row = GRID[r]
            for c in range(M):
                if row[c] == '-':
                    result.append((r, c))
                    if len(result) == K:
                        return result
        return result

    u0, v0 = best_window
    v1 = v0 + best_d
    cand = []
    for u in range(u0, u0 + best_d + 1):
        for v, aura, r, c in points[u]:
            if v0 <= v <= v1:
                cand.append((aura, r, c))

    cand.sort()
    return [(r, c) for _, r, c in cand[:K]]


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
