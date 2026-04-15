import sys
from bisect import insort, bisect_left, bisect_right

def solve():
    data = sys.stdin.buffer.read().decode().split()
    pos = 0
    def rd():
        nonlocal pos
        v = data[pos]; pos += 1; return v

    T = int(rd())
    out = []
    for _ in range(T):
        N, M, K = int(rd()), int(rd()), int(rd())
        grid = [rd() for _ in range(N)]

        seats = []  # (u, v, r, c, aura)
        for r in range(N):
            row = grid[r]
            # prefix occupied from left
            lo_arr = [0]*M
            cnt = 0
            for c in range(M):
                if row[c] == '#': cnt += 1
                lo_arr[c] = cnt
            # prefix occupied from right
            ro_arr = [0]*M
            cnt = 0
            for c in range(M-1, -1, -1):
                if row[c] == '#': cnt += 1
                ro_arr[c] = cnt
            for c in range(M):
                if row[c] == '-':
                    left_o = lo_arr[c-1] if c > 0 else 0
                    right_o = ro_arr[c+1] if c < M-1 else 0
                    aura = min(left_o, right_o)
                    seats.append((r+c, r-c, r, c, aura))

        S = len(seats)
        if K == 1:
            best = min(seats, key=lambda x: x[4])
            out.append(f"{best[2]} {best[3]}")
            continue

        seats.sort()

        def check(D):
            best_sum = float('inf')
            best_chosen = None
            j = 0
            # win stores (v, aura, index) sorted by v
            win_v = []
            win_a = []
            win_idx = []
            for i in range(S):
                u_i, v_i, r_i, c_i, a_i = seats[i]
                p = bisect_left(win_v, v_i)
                win_v.insert(p, v_i)
                win_a.insert(p, a_i)
                win_idx.insert(p, i)
                while seats[j][0] < u_i - D:
                    vj = seats[j][1]
                    p2 = bisect_left(win_v, vj)
                    # find exact match
                    while p2 < len(win_v) and win_idx[p2] != j:
                        p2 += 1
                    win_v.pop(p2)
                    win_a.pop(p2)
                    win_idx.pop(p2)
                    j += 1
                wlen = len(win_v)
                if wlen >= K:
                    for p in range(wlen - K + 1):
                        if win_v[p+K-1] - win_v[p] > D:
                            continue
                        # find rightmost q with v-range <= D
                        lo2, hi2, best_q = p+K-1, wlen-1, p+K-1
                        while lo2 <= hi2:
                            mid = (lo2+hi2)//2
                            if win_v[mid] - win_v[p] <= D:
                                best_q = mid; lo2 = mid+1
                            else:
                                hi2 = mid-1
                        # pick K with smallest aura from p..best_q
                        sub = sorted(range(p, best_q+1), key=lambda x: win_a[x])
                        s = sum(win_a[sub[q]] for q in range(K))
                        if s < best_sum:
                            best_sum = s
                            best_chosen = [win_idx[sub[q]] for q in range(K)]
            return best_chosen

        lo, hi = 0, N+M-2
        ans_idx = None
        while lo <= hi:
            mid = (lo+hi)//2
            res = check(mid)
            if res is not None:
                ans_idx = res
                hi = mid - 1
            else:
                lo = mid + 1

        for i in ans_idx:
            out.append(f"{seats[i][2]} {seats[i][3]}")

    sys.stdout.write('\n'.join(out) + '\n')

solve()
