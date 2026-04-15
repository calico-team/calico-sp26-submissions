import sys
from collections import defaultdict
input = sys.stdin.readline


def compute_aura(GRID, r, c):
    row = GRID[r]
    M = len(row)
    left = sum(1 for j in range(c) if row[j] == '#')
    right = sum(1 for j in range(c + 1, M) if row[j] == '#')
    return min(left, right)


def build_prefix(sg, UM, VM):
    pf = [[0] * (VM + 1) for _ in range(UM + 1)]
    for i in range(1, UM + 1):
        row_sum = 0
        for j in range(1, VM + 1):
            row_sum += sg[i - 1][j - 1]
            pf[i][j] = pf[i - 1][j] + row_sum
    return pf


def can_fit(D, pf, UM, VM, K):
    D1 = D + 1
    for ui in range(D1, UM + 1):
        u0 = ui - D1
        for vi in range(D1, VM + 1):
            v0 = vi - D1
            s = pf[ui][vi] - pf[u0][vi] - pf[ui][v0] + pf[u0][v0]
            if s >= K:
                return True
    return False


def find_valid_boxes(D, pf, UM, VM, K):
    D1 = D + 1
    boxes = []
    for ui in range(D1, UM + 1):
        u0 = ui - D1
        for vi in range(D1, VM + 1):
            v0 = vi - D1
            s = pf[ui][vi] - pf[u0][vi] - pf[ui][v0] + pf[u0][v0]
            if s >= K:
                boxes.append((u0, ui - 1, v0, vi - 1))
    return boxes


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

    sg = [[0] * VM for _ in range(UM)]
    for u, v, r, c, a in seats:
        sg[u][v] += 1

    pf = build_prefix(sg, UM, VM)

    lo, hi = 0, N + M
    while lo < hi:
        mid = (lo + hi) // 2
        if can_fit(mid, pf, UM, VM, K):
            hi = mid
        else:
            lo = mid + 1

    best_d = lo

    by_aura = sorted(range(A), key=lambda i: seats[i][4])

    def make_pf(t):
        sg2 = [[0] * VM for _ in range(UM)]
        for i in by_aura[:t]:
            sg2[seats[i][0]][seats[i][1]] += 1
        return build_prefix(sg2, UM, VM)

    lo2, hi2 = K, A + 1
    while lo2 < hi2:
        mid = (lo2 + hi2) // 2
        if can_fit(best_d, make_pf(mid), UM, VM, K):
            hi2 = mid
        else:
            lo2 = mid + 1

    t_star = lo2
    pf_t = make_pf(t_star)
    valid_boxes = find_valid_boxes(best_d, pf_t, UM, VM, K)

    sat = defaultdict(list)
    for i in by_aura[:t_star]:
        u, v, r, c, a = seats[i]
        sat[(u, v)].append(a)

    best_aura_sum = float('inf')
    best_box = None

    for ul, uh, vl, vh in valid_boxes:
        auras = []
        for u in range(ul, min(uh + 1, UM)):
            for v in range(vl, min(vh + 1, VM)):
                if (u, v) in sat:
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
