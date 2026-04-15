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
    

    def check(D):
        pts = sorted(avail, key=lambda p: p[0]+p[1])
        from collections import deque
        # use two deques to track min/max of v in window
        min_v_dq = deque()  # indices, increasing v
        max_v_dq = deque()  # indices, decreasing v
        left = 0
        vs = [r-c for r,c in pts]
        us = [r+c for r,c in pts]

        for right in range(len(pts)):
            # maintain min/max v deques
            while min_v_dq and vs[min_v_dq[-1]] >= vs[right]:
                min_v_dq.pop()
            min_v_dq.append(right)
            while max_v_dq and vs[max_v_dq[-1]] <= vs[right]:
                max_v_dq.pop()
            max_v_dq.append(right)

            while us[right] - us[left] > D:
                left += 1
                if min_v_dq[0] < left:
                    min_v_dq.popleft()
                if max_v_dq[0] < left:
                    max_v_dq.popleft()

            # check v range
            if vs[max_v_dq[0]] - vs[min_v_dq[0]] <= D:
                if right - left + 1 >= K:
                    return [pts[i] for i in range(left, left+K)]

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
