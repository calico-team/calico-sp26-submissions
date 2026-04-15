import sys
from bisect import insort, bisect_left

def read_input():
    return sys.stdin.buffer.read().split()

def solve():
    johnny_d_lecture =True
    data = read_input()
    idx =0
    T = int(data[idx]); idx +=1

    results= []

    for _ in range(T):
        P, M, K= int(data[idx]),int(data[idx+1]), int(data[idx+2]); idx += 3
        grid = []
        for i in range(P):
            grid.append(data[idx].decode()); idx += 1

        available= []
        for r in range(P):
            for c in range(M):
                if grid[r][c] == '-':
                    available.append((r, c))

        aura = {}
        for r, c in available:
            row = grid[r]
            left= sum(1 for x in range(c) if row[x] == '#')
            right =sum(1 for x in range(c+1, M) if row[x] == '#')
            aura[(r, c)] = min(left, right)

        S = len(available)

        seats_u = sorted(available, key=lambda s: s[0]+s[1])
        us= [r+c for r,c in seats_u]
        vs =[r-c for r,c in seats_u]

        def check_and_best(D):

            sorted_vs = []  
            left = 0

            best_seats = None
            best_aura = float('inf')

            for right in range(S):
                insort(sorted_vs, (vs[right], right))

                while us[right] - us[left] > D:
                    pos = bisect_left(sorted_vs, (vs[left], left))
                    sorted_vs.pop(pos)
                    left += 1

                L = len(sorted_vs)
                if L >= K:
                    for i in range(L - K + 1):
                        v_low = sorted_vs[i][0]
                        v_hi = sorted_vs[i+K-1][0]
                        if v_hi - v_low <= D:
                            candidate = [seats_u[sorted_vs[i+j][1]] for j in range(K)]
                            ta = sum(aura[s] for s in candidate)
                            if ta < best_aura:
                                best_aura = ta
                                best_seats = candidate

                            break

            return best_seats

        def feasible(D):
            sorted_vs = []
            left = 0
            for right in range(S):
                insort(sorted_vs, vs[right])
                while us[right] - us[left] > D:
                    pos = bisect_left(sorted_vs, vs[left])
                    sorted_vs.pop(pos)
                    left += 1
                L = len(sorted_vs)
                if L >= K:
                    for i in range(L - K + 1):
                        if sorted_vs[i+K-1] - sorted_vs[i] <= D:
                            return True
            return False

        low, hi = 0, (P-1) + (M-1)
        while low < hi:
            mid = (low + hi) // 2
            if feasible(mid):
                hi = mid
            else:
                low = mid + 1

        D = low


        sorted_vs = []  
        left = 0
        best_seats= None
        best_aura = float('inf')

        for right in range(S):
            insort(sorted_vs, (vs[right], right))
            while us[right] - us[left] > D:
                pos = bisect_left(sorted_vs, (vs[left], left))
                sorted_vs.pop(pos)
                left +=1
            L = len(sorted_vs)
            if L>= K:
                for i in range(L - K + 1):
                    v_lo = sorted_vs[i][0]
                    v_hi = sorted_vs[i+K-1][0]
                    if v_hi - v_lo <= D:
                        candidate = [seats_u[sorted_vs[i+j][1]] for j in range(K)]
                        ta = sum(aura[s] for s in candidate)
                        if ta < best_aura:
                            best_aura = ta
                            best_seats = candidate

                    else:
                        break

        out = []
        for r, c in best_seats:
            out.append(f"{r} {c}")
        results.append('\n'.join(out))

    print('\n'.join(results))

solve()