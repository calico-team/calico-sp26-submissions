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
    

    def check(D):
        pts = sorted(avail, key=lambda p: (p[0]+p[1]))
        us = [r+c for r,c in pts]
        vs = [r-c for r,c in pts]
        n = len(pts)

        left = 0
        for right in range(n):
            while us[right] - us[left] > D:
                left += 1
            # valid u-window: [left..right]
            window = list(range(left, right+1))
            sv = sorted(window, key=lambda i: vs[i])
            l2 = 0
            for r2 in range(len(sv)):
                while vs[sv[r2]] - vs[sv[l2]] > D:
                    l2 += 1
                if r2 - l2 + 1 >= K:
                    return [pts[sv[l2+x]] for x in range(K)]
        return None

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
