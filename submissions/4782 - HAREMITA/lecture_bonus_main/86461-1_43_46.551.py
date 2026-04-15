import sys
from collections import defaultdict
input = sys.stdin.readline

def solve():
    N, M, K = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(input().strip())
    
    # Precompute available seats per row
    row_avail = [[] for _ in range(N)]
    for r in range(N):
        for c in range(M):
            if grid[r][c] == '-':
                row_avail[r].append(c)
    
    # Compute aura loss for each available seat
    aura = [[0]*M for _ in range(N)]
    for r in range(N):
        row = grid[r]
        prefix = [0] * (M + 1)
        for c in range(M):
            prefix[c+1] = prefix[c] + (1 if row[c] == '#' else 0)
        for c in row_avail[r]:
            left_occ = prefix[c]
            right_occ = prefix[M] - prefix[c+1]
            aura[r][c] = min(left_occ, right_occ)
    
    # Feasibility check: can we find K seats with max pairwise manhattan <= D?
    def feasible(D):
        col_count = [0] * M
        r_lo = 0
        for r_hi in range(N):
            for c in row_avail[r_hi]:
                col_count[c] += 1
            while r_hi - r_lo > D:
                for c in row_avail[r_lo]:
                    col_count[c] -= 1
                r_lo += 1
            col_span = D - (r_hi - r_lo)
            if col_span >= M - 1:
                # All columns allowed, just check total in band
                total = sum(col_count)
                if total >= K:
                    return True
                continue
            # Sliding window
            ws = sum(col_count[:col_span+1])
            if ws >= K:
                return True
            for cl in range(1, M):
                cr = cl + col_span
                ws -= col_count[cl-1]
                if cr < M:
                    ws += col_count[cr]
                if ws >= K:
                    return True
        return False
    
    # Binary search for minimum D
    lo, hi = 0, (N-1) + (M-1)
    while lo < hi:
        mid = (lo + hi) // 2
        if feasible(mid):
            hi = mid
        else:
            lo = mid + 1
    
    ans_D = lo
    
    # Find optimal answer with bonus (min aura sum)
    best_aura_sum = float('inf')
    best_seats = None
    
    col_count = [0] * M
    r_lo = 0
    
    for r_hi in range(N):
        for c in row_avail[r_hi]:
            col_count[c] += 1
        while r_hi - r_lo > ans_D:
            for c in row_avail[r_lo]:
                col_count[c] -= 1
            r_lo += 1
        
        col_span = ans_D - (r_hi - r_lo)
        
        if col_span >= M - 1:
            seats = []
            for r in range(r_lo, r_hi + 1):
                for c in row_avail[r]:
                    seats.append((aura[r][c], r, c))
            if len(seats) >= K:
                seats.sort()
                total = sum(s[0] for s in seats[:K])
                if total < best_aura_sum:
                    best_aura_sum = total
                    best_seats = [(s[1], s[2]) for s in seats[:K]]
            continue
        
        prefix = [0] * (M + 1)
        for c in range(M):
            prefix[c+1] = prefix[c] + col_count[c]
        
        for cl in range(M):
            cr = cl + col_span
            if cr >= M:
                break
            ws = prefix[cr+1] - prefix[cl]
            if ws >= K:
                seats = []
                for r in range(r_lo, r_hi + 1):
                    for c in row_avail[r]:
                        if cl <= c <= cr:
                            seats.append((aura[r][c], r, c))
                seats.sort()
                total = sum(s[0] for s in seats[:K])
                if total < best_aura_sum:
                    best_aura_sum = total
                    best_seats = [(s[1], s[2]) for s in seats[:K]]
    
    out = []
    for (r, c) in best_seats:
        out.append(f"{r} {c}")
    sys.stdout.write("\n".join(out) + "\n")

def read_your_input():
    T = int(input())
    for _ in range(T):
        solve()

johnny_d_lecture = True

read_your_input()