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
    points = [[] for _ in range(total)]

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
                seats[u].append(v)
                points[u].append((v, aura, r, c))

    only_v = []
    for u in range(total):
        points[u].sort()
        only_v.append([x[0] for x in points[u]])

    def find_any(d):
        L = total - d
        w = d + 1
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
    while lo <= hi:
        mid = (lo + hi) >> 1
        if find_any(mid) is not None:
            best_d = mid
            hi = mid - 1
        else:
            lo = mid + 1

    L = total - best_d
    w = best_d + 1

    def calc_window_sum(u0, v0, cur_best):
        v1 = v0 + best_d
        heap = []
        s = 0

        for u in range(u0, u0 + best_d + 1):
            arr = points[u]
            vals = only_v[u]
            l = bisect_left(vals, v0)
            r = bisect_right(vals, v1)
            for i in range(l, r):
                a = arr[i][1]
                if len(heap) < K:
                    heapq.heappush(heap, -a)
                    s += a
                else:
                    worst = -heap[0]
                    if a < worst:
                        s += a - worst
                        heapq.heapreplace(heap, -a)

        return s

    best_sum = None
    best_window = None

    cnt_v = [0] * total
    right_u = -1

    for left_u in range(L):
        lim = left_u + best_d
        while right_u < lim:
            right_u += 1
            for v in seats[right_u]:
                cnt_v[v] += 1

        cur = 0
        for i in range(w):
            cur += cnt_v[i]
        if cur >= K:
            s = calc_window_sum(left_u, 0, best_sum)
            if best_sum is None or s < best_sum:
                best_sum = s
                best_window = (left_u, 0)

        for sv in range(1, L):
            cur += cnt_v[sv + w - 1] - cnt_v[sv - 1]
            if cur >= K:
                s = calc_window_sum(left_u, sv, best_sum)
                if best_sum is None or s < best_sum:
                    best_sum = s
                    best_window = (left_u, sv)

        for v in seats[left_u]:
            cnt_v[v] -= 1

    u0, v0 = best_window
    v1 = v0 + best_d
    cand = []

    for u in range(u0, u0 + best_d + 1):
        arr = points[u]
        vals = only_v[u]
        l = bisect_left(vals, v0)
        r = bisect_right(vals, v1)
        for i in range(l, r):
            cand.append((arr[i][1], arr[i][2], arr[i][3]))

    cand.sort()
    return [(cand[i][1], cand[i][2]) for i in range(K)]



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
