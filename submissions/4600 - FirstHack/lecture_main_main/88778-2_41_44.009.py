from itertools import combinations

def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """

    avail = []
    for r in range(N):
        for c in range(M):
            if GRID[r][c] == '-':
                avail.append((r, c))

    if K == 1:
        return [avail[0]]

    def man(a, b):
        return abs(a[0]-b[0]) + abs(a[1]-b[1])

    def check(D):
        # for each seat as anchor, count how many seats within D
        # seats are sorted by row then col
        for i, (r, c) in enumerate(avail):
            group = []
            for j in range(i, len(avail)):
                r2, c2 = avail[j]
                # early exit: if row diff alone exceeds D no point continuing
                if r2 - r > D:
                    break
                if man((r,c), (r2,c2)) <= D:
                    group.append((r2,c2))
            if len(group) >= K:
                # verify all pairs within group <= D
                # just take first K and verify
                cands = group[:K]
                ok = True
                for a in range(len(cands)):
                    for b in range(a+1, len(cands)):
                        if man(cands[a], cands[b]) > D:
                            ok = False
                            break
                    if not ok:
                        break
                if ok:
                    return cands
        return None

    # binary search on D
    lo, hi = 0, 2*(N+M)
    best = None
    while lo <= hi:
        mid = (lo+hi)//2
        res = check(mid)
        if res is not None:
            best = res
            hi = mid - 1
        else:
            lo = mid + 1

    return best

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
