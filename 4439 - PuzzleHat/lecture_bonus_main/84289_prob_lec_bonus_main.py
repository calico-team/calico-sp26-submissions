import sys
import bisect
input = sys.stdin.readline

def compute_aura(grid, N, M):
    aura = {}
    for r in range(N):
        row = grid[r]
        left_occ = 0
        left_counts = []
        for c in range(M):
            left_counts.append(left_occ)
            if row[c] == '#':
                left_occ += 1
        right_occ = 0
        for c in range(M - 1, -1, -1):
            if row[c] == '-':
                aura[(r, c)] = min(left_counts[c], right_occ)
            else:
                right_occ += 1
    return aura

def can_fit(seats_uv, K, D):
    n = len(seats_uv)
    left = 0
   
    window_v = []

    for right in range(n):
        u_r, v_r, idx = seats_uv[right]
        bisect.insort(window_v, v_r)

        while seats_uv[right][0] - seats_uv[left][0] > D:
            u_l, v_l, idx_l = seats_uv[left]
            pos = bisect.bisect_left(window_v, v_l)
            window_v.pop(pos)
            left += 1

        if len(window_v) >= K:
            for i in range(len(window_v) - K + 1):
                if window_v[i + K - 1] - window_v[i] <= D:
                    return True

    return False

def find_best_window(seats_uv, K, D, aura, seats, bonus):
    n = len(seats_uv)
    left = 0
   
    window = []  # list of (v, idx)

    best_aura = None
    best_set = None

    for right in range(n):
        u_r, v_r, idx = seats_uv[right]
        bisect.insort(window, (v_r, idx))

        while seats_uv[right][0] - seats_uv[left][0] > D:
            u_l, v_l, idx_l = seats_uv[left]
            pos = bisect.bisect_left(window, (v_l, idx_l))
            window.pop(pos)
            left += 1

        if len(window) < K:
            continue

        for i in range(len(window) - K + 1):
            v_lo = window[i][0]
            v_hi = window[i + K - 1][0]
            if v_hi - v_lo <= D:
                candidates = [window[i + j][1] for j in range(K)]
                if not bonus:
                    return candidates
                total = sum(aura[seats[c]] for c in candidates)
                if best_aura is None or total < best_aura:
                    best_aura = total
                    best_set = candidates
                break

    return best_set

def solve(N, M, K, grid, bonus):
    seats = []
    for r in range(N):
        for c in range(M):
            if grid[r][c] == '-':
                seats.append((r, c))

    
    seats_uv = sorted([(r + c, r - c, i) for i, (r, c) in enumerate(seats)])

   
    lo, hi = 0, 2 * (N + M)
    best_D = hi
    while lo <= hi:
        mid = (lo + hi) // 2
        if can_fit(seats_uv, K, mid):
            best_D = mid
            hi = mid - 1
        else:
            lo = mid + 1

    aura = compute_aura(grid, N, M) if bonus else None
    chosen = find_best_window(seats_uv, K, best_D, aura, seats, bonus)

    for idx in chosen:
        r, c = seats[idx]
        print(r, c)

T = int(input())
for _ in range(T):
    N, M, K = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(input().strip())
    solve(N, M, K, grid, bonus=True)