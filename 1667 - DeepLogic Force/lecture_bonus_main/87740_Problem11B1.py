johnny_d_lecture = True


def solve(N, M, K, GRID):
    empty = [(r, c) for r in range(N) for c in range(M) if GRID[r][c] == '-']

    # compute aura loss for every empty seat
    aura = {}
    for r in range(N):
        row = GRID[r]
        left = [0] * M
        cnt = 0
        for c in range(M):
            left[c] = cnt
            if row[c] == '#':
                cnt += 1
        right = [0] * M
        cnt = 0
        for c in range(M - 1, -1, -1):
            right[c] = cnt
            if row[c] == '#':
                cnt += 1
        for c in range(M):
            if row[c] == '-':
                aura[(r, c)] = min(left[c], right[c])

    if K == 1:
        best = min(empty, key=lambda s: aura[s])
        return [best]

    # transform to (u, v) = (r+c, r-c+M-1), manhattan -> chebyshev
    U = N + M - 1
    V = N + M - 1

    seat = [[0] * V for _ in range(U)]
    aur = [[0] * V for _ in range(U)]
    for (r, c) in empty:
        u = r + c
        v = r - c + M - 1
        seat[u][v] = 1
        aur[u][v] = aura[(r, c)]

    # prefix sum of seat counts
    PS = [[0] * (V + 1) for _ in range(U + 1)]
    for i in range(U):
        for j in range(V):
            PS[i + 1][j + 1] = seat[i][j] + PS[i + 1][j] + PS[i][j + 1] - PS[i][j]

    def rect(u1, v1, u2, v2):
        if u2 >= U: u2 = U - 1
        if v2 >= V: v2 = V - 1
        return PS[u2 + 1][v2 + 1] - PS[u1][v2 + 1] - PS[u2 + 1][v1] + PS[u1][v1]

    def feasible(D):
        for u0 in range(U):
            for v0 in range(V):
                if rect(u0, v0, u0 + D, v0 + D) >= K:
                    return True
        return False

    # binary search smallest D
    lo, hi = 0, U + V
    while lo < hi:
        mid = (lo + hi) // 2
        if feasible(mid):
            hi = mid
        else:
            lo = mid + 1
    D = lo

    # among all valid windows, pick the K seats with smallest total aura loss
    best_total = None
    best_pick = None
    for u0 in range(U):
        for v0 in range(V):
            if rect(u0, v0, u0 + D, v0 + D) >= K:
                ue = min(u0 + D, U - 1)
                ve = min(v0 + D, V - 1)
                cand = []
                for u in range(u0, ue + 1):
                    for v in range(v0, ve + 1):
                        if seat[u][v]:
                            cand.append((aur[u][v], u, v))
                cand.sort()
                picked = cand[:K]
                total = sum(x[0] for x in picked)
                if best_total is None or total < best_total:
                    best_total = total
                    best_pick = picked

    result = []
    for _, u, v in best_pick:
        # u = r+c, v = r-c+M-1  =>  r = (u+v-M+1)/2, c = (u-v+M-1)/2
        r = (u + v - M + 1) // 2
        c = (u - v + M - 1) // 2
        result.append((r, c))
    return result


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = [input().strip() for _ in range(N)]
        for r, c in solve(N, M, K, GRID):
            print(f"{r} {c}")


def read_your_input():
    import sys
    return sys.stdin.readline


if __name__ == '__main__':
    main()