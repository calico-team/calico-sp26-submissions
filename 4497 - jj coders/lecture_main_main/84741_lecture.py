import sys
import bisect

def compute_aura_losses(grid, N, M):
    loss = {}
    for r in range(N):
        row = grid[r]
        prefix = [0] * (M + 1)
        for c in range(M):
            prefix[c+1] = prefix[c] + (1 if row[c] == '#' else 0)
        for c in range(M):
            if row[c] == '-':
                left_occ  = prefix[c]
                right_occ = prefix[M] - prefix[c+1]
                loss[(r, c)] = min(left_occ, right_occ)
    return loss

def solve(N, M, K, grid):
    avail = []
    for r in range(N):
        for c in range(M):
            if grid[r][c] == '-':
                avail.append((r, c))

    loss = compute_aura_losses(grid, N, M)

    if K == 1:
        best = min(avail, key=lambda s: loss[s])
        return [best]

    # Transform to Chebyshev coords: u = r+c, v = r-c
    # Manhattan(A,B) = max(|uA-uB|, |vA-vB|) in (u,v) space
    avail_sorted = sorted(avail, key=lambda s: s[0]+s[1])
    us = [s[0]+s[1] for s in avail_sorted]
    vs = [s[0]-s[1] for s in avail_sorted]
    n = len(avail_sorted)

    # Sorted list implementation using bisect (stores (v, idx) tuples)
    class SortedList:
        def __init__(self):
            self.data = []
        def add(self, val):
            bisect.insort(self.data, val)
        def remove(self, val):
            i = bisect.bisect_left(self.data, val)
            del self.data[i]
        def __len__(self):
            return len(self.data)
        def __getitem__(self, i):
            return self.data[i]
        def tolist(self):
            return self.data[:]

    def check(D):
        sl = SortedList()
        left = 0
        for right in range(n):
            sl.add((vs[right], right))
            while us[right] - us[left] > D:
                sl.remove((vs[left], left))
                left += 1
            if len(sl) >= K:
                arr = sl.tolist()
                for i in range(len(arr) - K + 1):
                    if arr[i + K - 1][0] - arr[i][0] <= D:
                        return True
        return False

    lo, hi = 0, (N - 1) + (M - 1)
    while lo < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1

    best_D = lo

    # Find best K seats minimizing total aura loss
    best_total_loss = None
    best_seats = None

    sl = SortedList()
    left = 0

    for right in range(n):
        sl.add((vs[right], right))
        while us[right] - us[left] > best_D:
            sl.remove((vs[left], left))
            left += 1

        if len(sl) >= K:
            arr = sl.tolist()  # sorted by (v, idx)
            m = len(arr)
            losses_arr = [loss[avail_sorted[arr[i][1]]] for i in range(m)]

            # Sliding window of size K
            window_sum = sum(losses_arr[:K])
            if arr[K-1][0] - arr[0][0] <= best_D:
                if best_total_loss is None or window_sum < best_total_loss:
                    best_total_loss = window_sum
                    best_seats = [avail_sorted[arr[j][1]] for j in range(K)]
            for i in range(1, m - K + 1):
                window_sum += losses_arr[i + K - 1] - losses_arr[i - 1]
                if arr[i + K - 1][0] - arr[i][0] <= best_D:
                    if best_total_loss is None or window_sum < best_total_loss:
                        best_total_loss = window_sum
                        best_seats = [avail_sorted[arr[j][1]] for j in range(i, i + K)]

    return best_seats


def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    out = []
    for _ in range(T):
        N, M, K = int(data[idx]), int(data[idx+1]), int(data[idx+2])
        idx += 3
        grid = []
        for i in range(N):
            grid.append(data[idx].decode()); idx += 1
        result = solve(N, M, K, grid)
        for r, c in result:
            out.append(f"{r} {c}")
    sys.stdout.write('\n'.join(out) + '\n')

if __name__ == '__main__':
    main()