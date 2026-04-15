from bisect import bisect_left, bisect_right
import heapq
from collections import defaultdict

class KSmallest:
    def __init__(self, k):
        self.k = k
        self.small = []
        self.large = []
        self.delayed = defaultdict(int)
        self.small_size = 0
        self.large_size = 0
        self.small_sum = 0

    def _prune_small(self):
        while self.small:
            x = -self.small[0]
            if self.delayed[x]:
                self.delayed[x] -= 1
                heapq.heappop(self.small)
            else:
                break

    def _prune_large(self):
        while self.large:
            x = self.large[0]
            if self.delayed[x]:
                self.delayed[x] -= 1
                heapq.heappop(self.large)
            else:
                break

    def _balance(self):
        self._prune_small()
        self._prune_large()

        while self.small_size > self.k:
            self._prune_small()
            x = -heapq.heappop(self.small)
            self.small_size -= 1
            self.small_sum -= x
            heapq.heappush(self.large, x)
            self.large_size += 1
            self._prune_small()

        while self.small_size < self.k and self.large_size > 0:
            self._prune_large()
            x = heapq.heappop(self.large)
            self.large_size -= 1
            heapq.heappush(self.small, -x)
            self.small_size += 1
            self.small_sum += x
            self._prune_large()

        self._prune_small()
        self._prune_large()

    def add(self, x):
        if self.small_size < self.k:
            heapq.heappush(self.small, -x)
            self.small_size += 1
            self.small_sum += x
        else:
            self._prune_small()
            if self.small and x < -self.small[0]:
                y = -heapq.heapreplace(self.small, -x)
                self.small_sum += x - y
                heapq.heappush(self.large, y)
                self.large_size += 1
            else:
                heapq.heappush(self.large, x)
                self.large_size += 1
        self._balance()

    def remove(self, x):
        self._prune_small()
        if self.small and x <= -self.small[0]:
            self.small_size -= 1
            self.small_sum -= x
            self.delayed[x] += 1
            if self.small and x == -self.small[0]:
                self._prune_small()
        else:
            self.large_size -= 1
            self.delayed[x] += 1
            if self.large and x == self.large[0]:
                self._prune_large()
        self._balance()

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
        for c, ch in enumerate(row):
            if ch == '#':
                left += 1
            else:
                aura = min(left, occ - left)
                u = r + c
                v = r - c + shift
                seats[u].append(v)
                points[u].append((v, aura, r, c))

    for u in range(total):
        points[u].sort()

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

            cur = sum(cnt_v[:w])
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

    best_sum = None
    best_window = None

    for left_u in range(L):
        cols = [[] for _ in range(total)]
        cnt_v = [0] * total

        for u in range(left_u, left_u + w):
            for v, aura, r, c in points[u]:
                cols[v].append(aura)
                cnt_v[v] += 1

        cur = sum(cnt_v[:w])
        ds = KSmallest(K)

        for v in range(w):
            for aura in cols[v]:
                ds.add(aura)

        if cur >= K:
            s = ds.small_sum
            if best_sum is None or s < best_sum:
                best_sum = s
                best_window = (left_u, 0)

        for sv in range(1, L):
            out_v = sv - 1
            in_v = sv + w - 1

            cur += cnt_v[in_v] - cnt_v[out_v]

            for aura in cols[out_v]:
                ds.remove(aura)
            for aura in cols[in_v]:
                ds.add(aura)

            if cur >= K:
                s = ds.small_sum
                if best_sum is None or s < best_sum:
                    best_sum = s
                    best_window = (left_u, sv)

    u0, v0 = best_window
    v1 = v0 + best_d
    cand = []

    for u in range(u0, u0 + w):
        arr = points[u]
        l = bisect_left(arr, (v0, -1, -1, -1))
        r = bisect_right(arr, (v1, 10**18, 10**18, 10**18))
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
