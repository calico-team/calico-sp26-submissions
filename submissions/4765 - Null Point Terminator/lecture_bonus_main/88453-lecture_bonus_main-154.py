from bisect import bisect_left, bisect_right
import heapq
def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    total = N + M - 1
    shift = M - 1
    seats = [[] for _ in range(total)]

    for r in range(N):
        row = GRID[r]
        base = shift + r
        for c in range(M):
            if row[c] == '-':
                u = r + c
                v = base - c
                seats[u].append(v)

    def find_window(d):
        w = d + 1
        L = total - d
        cnt_v = [0] * total
        right_u = -1

        for left_u in range(L):
            lim = left_u + d
            while right_u < lim:
                right_u += 1
                for v in seats[right_u]:
                    cnt_v[v] += 1

            cur = 0
            for i in range(w):
                cur += cnt_v[i]
            if cur >= K:
                return left_u, 0

            for sv in range(1, L):
                cur += cnt_v[sv + w - 1] - cnt_v[sv - 1]
                if cur >= K:
                    return left_u, sv

            for v in seats[left_u]:
                cnt_v[v] -= 1

        return None

    lo, hi = 0, total - 1
    best_d = total - 1
    best_win = (0, 0)

    while lo <= hi:
        mid = (lo + hi) >> 1
        win = find_window(mid)
        if win is not None:
            best_d = mid
            best_win = win
            hi = mid - 1
        else:
            lo = mid + 1

    u0, v0 = best_win
    ans = []
    for r in range(N):
        row = GRID[r]
        base = shift + r
        for c in range(M):
            if row[c] == '-':
                u = r + c
                v = base - c
                if u0 <= u <= u0 + best_d and v0 <= v <= v0 + best_d:
                    ans.append((r, c))
                    if len(ans) == K:
                        return ans

    return ans


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
