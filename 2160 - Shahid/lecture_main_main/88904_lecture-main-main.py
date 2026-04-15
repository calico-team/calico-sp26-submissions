
import sys

def solve() -> None:
    data = sys.stdin.read().split()
    it = iter(data)
    t = int(next(it))
    out_lines = []

    for _ in range(t):
        N = int(next(it))
        M = int(next(it))
        K = int(next(it))

        grid = [next(it).strip() for _ in range(N)]

        # collect all available seats (dash)
        seats = []
        for r in range(N):
            row = grid[r]
            for c in range(M):
                if row[c] == '-':
                    seats.append((r, c))

        # transform to (u, v) coordinates: u = r+c, v = r-c + (M-1)
        Umax = N + M - 1
        Vmax = N + M - 1
        v_offset = M - 1

        # mapping (u, v) -> (r, c) and aura loss
        point_map = {}
        aura = {}
        occ_per_row = [row.count('#') for row in grid]

        for r, c in seats:
            u = r + c
            v = r - c + v_offset
            point_map[(u, v)] = (r, c)
            left = grid[r][:c].count('#')
            right = occ_per_row[r] - left
            aura[(u, v)] = min(left, right)

        # count grid (binary: 1 if seat exists)
        cnt = [[0] * Vmax for _ in range(Umax)]
        for u, v in point_map:
            cnt[u][v] = 1

        # 2D prefix sum for counts
        pre = [[0] * (Vmax + 1) for _ in range(Umax + 1)]
        for i in range(Umax):
            row_sum = 0
            for j in range(Vmax):
                row_sum += cnt[i][j]
                pre[i + 1][j + 1] = pre[i][j + 1] + row_sum

        # binary search for minimal diameter D
        lo, hi = 0, N + M
        while lo < hi:
            mid = (lo + hi) // 2
            side = mid          # inclusive side length
            found = False
            if side <= Umax and side <= Vmax:
                for u0 in range(Umax - side + 1):
                    for v0 in range(Vmax - side + 1):
                        u1 = u0 + side - 1
                        v1 = v0 + side - 1
                        total = (pre[u1 + 1][v1 + 1] - pre[u0][v1 + 1]
                                 - pre[u1 + 1][v0] + pre[u0][v0])
                        if total >= K:
                            found = True
                            break
                    if found:
                        break
            if found:
                hi = mid
            else:
                lo = mid + 1

        D_opt = lo
        side = D_opt

        # find any square of side D_opt containing at least K seats
        best = None
        for u0 in range(Umax - side + 1):
            for v0 in range(Vmax - side + 1):
                u1 = u0 + side - 1
                v1 = v0 + side - 1
                total = (pre[u1 + 1][v1 + 1] - pre[u0][v1 + 1]
                         - pre[u1 + 1][v0] + pre[u0][v0])
                if total >= K:
                    # collect all seats inside this square
                    pts = []
                    for u in range(u0, u1 + 1):
                        for v in range(v0, v1 + 1):
                            if (u, v) in point_map:
                                pts.append(point_map[(u, v)])
                    best = pts[:K]
                    break
            if best:
                break

        for r, c in best:
            out_lines.append(f"{r} {c}")

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
