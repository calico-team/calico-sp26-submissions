import sys
import bisect
from collections import deque

def solve():
    line = sys.stdin.readline().split()
    if not line:
        return
    N, M, K = map(int, line)

    grid = [sys.stdin.readline().strip() for _ in range(N)]

    seats = []
    for r in range(N):
        row = grid[r]
        left = [0]*M
        cnt = 0
        for c in range(M):
            if row[c] == '#':
                cnt += 1
            left[c] = cnt

        right = [0]*M
        cnt = 0
        for c in range(M-1, -1, -1):
            if row[c] == '#':
                cnt += 1
            right[c] = cnt

        for c in range(M):
            if row[c] == '-':
                aura = min(left[c], right[c])
                u = r + c
                v = r - c
                seats.append((u, v, aura, r, c))

    seats.sort()
    A = len(seats)

    # Check feasibility for distance D
    def can(D, need_best=False):
        vlist = []
        aura_list = []
        best = None
        l = 0

        for r in range(A):
            while seats[r][0] - seats[l][0] > D:
                idx = bisect.bisect_left(vlist, (seats[l][1], seats[l][2], seats[l][3], seats[l][4]))
                vlist.pop(idx)
                l += 1

            bisect.insort(vlist, (seats[r][1], seats[r][2], seats[r][3], seats[r][4]))

            i = 0
            for j in range(len(vlist)):
                while vlist[j][0] - vlist[i][0] > D:
                    i += 1
                if j - i + 1 >= K:
                    if not need_best:
                        return True
                    candidate = sorted(vlist[i:j+1], key=lambda x: x[1])[:K]
                    total_aura = sum(x[1] for x in candidate)
                    if best is None or total_aura < best[0]:
                        best = (total_aura, candidate)

        return best if need_best else False

    # Binary search minimal D
    lo, hi = 0, 2*(N+M)
    while lo < hi:
        mid = (lo + hi) // 2
        if can(mid):
            hi = mid
        else:
            lo = mid + 1

    # Retrieve optimal seats with minimal aura
    _, answer = can(lo, need_best=True)

    for _, _, r, c in answer:
        print(r, c)


def main():
    T = int(sys.stdin.readline())
    for _ in range(T):
        solve()

if __name__ == "__main__":
    main()