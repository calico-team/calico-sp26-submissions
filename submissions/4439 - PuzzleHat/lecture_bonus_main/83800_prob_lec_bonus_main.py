import sys
from sortedcontainers import SortedList
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

def find_best_window(seats_uv, K, D, aura, seats, bonus):
    # seats_uv: list of (u, v, original_index), sorted by u
    n = len(seats_uv)
    left = 0
    # sliding window on u: maintain sorted list of v values in window
    sl = SortedList()  # stores (v, original_index)
    
    best_aura = None
    best_set = None
    found = False

    for right in range(n):
        u_r, v_r, idx = seats_uv[right]
        sl.add((v_r, idx))

        # shrink left pointer so u window fits in D
        while seats_uv[right][0] - seats_uv[left][0] > D:
            u_l, v_l, idx_l = seats_uv[left]
            sl.remove((v_l, idx_l))
            left += 1

        if len(sl) < K:
            continue

        # check consecutive K items in sl by v value
        sl_list = list(sl)
        for i in range(len(sl_list) - K + 1):
            v_lo = sl_list[i][0]
            v_hi = sl_list[i + K - 1][0]
            if v_hi - v_lo <= D:
                found = True
                if not bonus:
                    return [sl_list[i + j][1] for j in range(K)]
                # bonus: track minimum aura
                candidates = [sl_list[i + j][1] for j in range(K)]
                total = sum(aura[seats[idx]] for idx in candidates)
                if best_aura is None or total < best_aura:
                    best_aura = total
                    best_set = candidates
                break  # inner consecutive windows with same i start are subsets; move on

    if bonus:
        return best_set
    return None

def can_fit(seats_uv, K, D):
    n = len(seats_uv)
    left = 0
    sl = SortedList()

    for right in range(n):
        u_r, v_r, idx = seats_uv[right]
        sl.add((v_r, idx))

        while seats_uv[right][0] - seats_uv[left][0] > D:
            u_l, v_l, idx_l = seats_uv[left]
            sl.remove((v_l, idx_l))
            left += 1

        if len(sl) >= K:
            sl_list = list(sl)
            for i in range(len(sl_list) - K + 1):
                if sl_list[i + K - 1][0] - sl_list[i][0] <= D:
                    return True

    return False

def solve(N, M, K, grid, bonus):
    seats = []
    for r in range(N):
        for c in range(M):
            if grid[r][c] == '-':
                seats.append((r, c))

    # Manhattan -> Chebyshev rotation: u = r+c, v = r-c
    seats_uv = sorted([(r + c, r - c, i) for i, (r, c) in enumerate(seats)])

    # binary search on the answer D
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