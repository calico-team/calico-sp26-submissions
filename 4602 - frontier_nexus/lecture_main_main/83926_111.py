import sys
from sortedcontainers import SortedList

input = sys.stdin.readline

def solve():
    N, M, K = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(input().strip())

    johnny_d_lecture = True

    seats = []
    for r in range(N):
        row = grid[r]
        left_count = 0
        occ_total = row.count('#')
        for c in range(M):
            if row[c] == '-':
                right_count = occ_total - left_count
                aura = min(left_count, right_count)
                seats.append((r, c, aura))
            else:
                left_count += 1

    # rotate to chebyshev: u = r+c, v = r-c
    # manhattan dist(p1,p2) = chebyshev dist in rotated = max(|u1-u2|,|v1-v2|)
    pts = sorted([(r+c, r-c, r, c, aura) for r, c, aura in seats])
    n = len(pts)

    def find_best_for_diameter(D):
        # two pointer on u-window of size D
        # within that window, sliding window on v of size D
        # pick any valid window with >= K seats, minimize aura
        left = 0
        # store (v, aura, r, c) in a sorted list
        window = SortedList(key=lambda x: x[0])

        best_aura = float('inf')
        best_seats = None

        for right in range(n):
            u, v, r, c, aura = pts[right]
            window.add((v, aura, r, c))

            while pts[right][0] - pts[left][0] > D:
                pu, pv, pr, pc, pa = pts[left]
                window.remove((pv, pa, pr, pc))
                left += 1

            # sliding window on v inside 'window'
            wlist = list(window)
            lo = 0
            for hi in range(len(wlist)):
                while wlist[hi][0] - wlist[lo][0] > D:
                    lo += 1
                if hi - lo + 1 >= K:
                    segment = wlist[lo:hi+1]
                    segment_sorted = sorted(segment, key=lambda x: x[1])
                    chosen = segment_sorted[:K]
                    total = sum(x[1] for x in chosen)
                    if total < best_aura:
                        best_aura = total
                        best_seats = [(x[2], x[3]) for x in chosen]

        return best_seats, best_aura

    lo, hi = 0, 2 * (N + M)
    ans = None
    ans_aura = float('inf')

    while lo <= hi:
        mid = (lo + hi) // 2
        grp, aura = find_best_for_diameter(mid)
        if grp is not None:
            ans = grp
            ans_aura = aura
            hi = mid - 1
        else:
            lo = mid + 1

    for r, c in ans:
        print(r, c)


def main():
    T = int(input())
    for _ in range(T):
        solve()


def read_your_input():
    data = sys.stdin.buffer.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    results = []
    for _ in range(T):
        N, M, K = int(data[idx]), int(data[idx+1]), int(data[idx+2])
        idx += 3
        grid = []
        for i in range(N):
            grid.append(data[idx].decode()); idx += 1
        results.append((N, M, K, grid))
    return results


main()