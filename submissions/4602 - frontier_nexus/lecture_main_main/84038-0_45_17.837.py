import sys
from bisect import bisect_left, bisect_right, insort

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

    # rotate coords: manhattan -> chebyshev
    # u = r+c, v = r-c
    # max(|u1-u2|, |v1-v2|) == manhattan distance
    pts = sorted([(r + c, r - c, r, c, aura) for r, c, aura in seats])
    n = len(pts)

    def check(D):
        # two pointer on u window of size D
        # within window, sliding window on v of size D
        # track v values in a sorted list manually

        best_aura = float('inf')
        best_seats = None

        # sorted list of (v, aura, r, c) maintained with bisect
        win_v = []   # just v values for bisect
        win_data = []  # parallel list of (v, aura, r, c)

        left = 0

        for right in range(n):
            u, v, r, c, aura = pts[right]

            # insert into sorted window
            pos = bisect_left(win_v, v)
            win_v.insert(pos, v)
            win_data.insert(pos, (v, aura, r, c))

            # shrink window from left if u span > D
            while pts[right][0] - pts[left][0] > D:
                lv = pts[left][1]
                lpos = bisect_left(win_v, lv)
                # find exact match (there could be duplicates)
                la = pts[left][4]
                lr = pts[left][2]
                lc = pts[left][3]
                # scan from lpos to find exact entry
                idx = lpos
                while idx < len(win_v) and win_v[idx] == lv:
                    if win_data[idx][1] == la and win_data[idx][2] == lr and win_data[idx][3] == lc:
                        win_v.pop(idx)
                        win_data.pop(idx)
                        break
                    idx += 1
                left += 1

            # sliding window on v inside current win_v
            m = len(win_v)
            lo = 0
            for hi in range(m):
                while win_v[hi] - win_v[lo] > D:
                    lo += 1
                if hi - lo + 1 >= K:
                    segment = win_data[lo:hi+1]
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
        grp, aura = check(mid)
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
    return data


main()