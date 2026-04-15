import numpy as np
from collections import defaultdict


def compute_aura(GRID, r, c):
    row = GRID[r]
    M = len(row)
    left = sum(1 for j in range(c) if row[j] == '#')
    right = sum(1 for j in range(c + 1, M) if row[j] == '#')
    return min(left, right)


def solve(N, M, K, GRID):
    VO = M - 1
    UM = N + M - 1
    VM = N + M - 1

    seats = []
    for r in range(N):
        for c in range(M):
            if GRID[r][c] == '-':
                u = r + c
                v = r - c + VO
                a = compute_aura(GRID, r, c)
                seats.append((u, v, r, c, a))

    A = len(seats)
    if A == 0:
        return []

    sg = np.zeros((UM, VM), dtype=np.int32)
    for u, v, r, c, a in seats:
        sg[u, v] += 1

    pf = np.zeros((UM + 1, VM + 1), dtype=np.int32)
    pf[1:, 1:] = np.cumsum(np.cumsum(sg, axis=0), axis=1)

    def box_sums(D, p):
        D1 = D + 1
        ue = max(1, UM - D)
        ve = max(1, VM - D)
        u2 = min(D1 + ue, UM + 1)
        v2 = min(D1 + ve, VM + 1)
        return p[D1:u2, D1:v2] - p[0:ue, D1:v2] - p[D1:u2, 0:ve] + p[0:ue, 0:ve]

    def can_fit(D, p):
        return bool(np.any(box_sums(D, p) >= K))

    lo, hi = 0, N + M
    while lo < hi:
        mid = (lo + hi) // 2
        if can_fit(mid, pf):
            hi = mid
        else:
            lo = mid + 1

    best_d = lo

    by_aura = sorted(range(A), key=lambda i: seats[i][4])

    def make_pf(t):
        sg2 = np.zeros((UM, VM), dtype=np.int32)
        for i in by_aura[:t]:
            sg2[seats[i][0], seats[i][1]] += 1
        pf2 = np.zeros((UM + 1, VM + 1), dtype=np.int32)
        pf2[1:, 1:] = np.cumsum(np.cumsum(sg2, axis=0), axis=1)
        return pf2

    lo2, hi2 = K, A + 1
    while lo2 < hi2:
        mid = (lo2 + hi2) // 2
        if can_fit(best_d, make_pf(mid)):
            hi2 = mid
        else:
            lo2 = mid + 1

    t_star = lo2
    pf_t = make_pf(t_star)
    bs = box_sums(best_d, pf_t)
    valid_pos = np.argwhere(bs >= K)

    sat = defaultdict(list)
    for i in by_aura[:t_star]:
        u, v, r, c, a = seats[i]
        sat[(u, v)].append(a)

    best_aura_sum = float('inf')
    best_box = None

    for us_v, vs_v in valid_pos:
        ul = int(us_v)
        uh = ul + best_d
        vl = int(vs_v)
        vh = vl + best_d
        auras = []
        for u in range(ul, min(uh + 1, UM)):
            for v in range(vl, min(vh + 1, VM)):
                auras.extend(sat[(u, v)])
        if len(auras) >= K:
            auras.sort()
            s = sum(auras[:K])
            if s < best_aura_sum:
                best_aura_sum = s
                best_box = (ul, uh, vl, vh)

    ul, uh, vl, vh = best_box
    eligible = sorted(
        (seats[i][4], seats[i][2], seats[i][3])
        for i in by_aura[:t_star]
        if ul <= seats[i][0] <= uh and vl <= seats[i][1] <= vh
    )
    return [(r, c) for a, r, c in eligible[:K]]


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
