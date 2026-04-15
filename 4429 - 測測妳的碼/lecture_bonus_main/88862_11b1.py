import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T = int(input_data[0])
    idx = 1
    out = []
    for _ in range(T):
        N = int(input_data[idx])
        M = int(input_data[idx + 1])
        K = int(input_data[idx + 2])
        idx += 3
        grid = input_data[idx: idx + N]
        idx += N
        seats = []
        for r in range(N):
            row = grid[r]
            pref_hash = [0] * M
            suff_hash = [0] * M
            curr = 0
            for c in range(M):
                pref_hash[c] = curr
                if row[c] == '#': curr += 1
            curr = 0
            for c in range(M - 1, -1, -1):
                suff_hash[c] = curr
                if row[c] == '#': curr += 1
            for c in range(M):
                if row[c] == '-':
                    aura = min(pref_hash[c], suff_hash[c])
                    u = r + c
                    v = r - c + M - 1
                    seats.append((r, c, aura, u, v))
        max_U = N + M - 2
        max_V = N + M - 2
        pref = [[0] * (max_V + 2) for _ in range(max_U + 2)]
        for s in seats:
            pref[s[3] + 1][s[4] + 1] += 1
        for i in range(1, max_U + 2):
            for j in range(1, max_V + 2):
                pref[i][j] = pref[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]

        def get_sum(u1, v1, u2, v2):
            if u1 > u2 or v1 > v2: return 0
            u1 = u1 if u1 > 0 else 0
            v1 = v1 if v1 > 0 else 0
            u2 = u2 if u2 < max_U else max_U
            v2 = v2 if v2 < max_V else max_V
            return pref[u2 + 1][v2 + 1] - pref[u1][v2 + 1] - pref[u2 + 1][v1] + pref[u1][v1]

        unique_u = sorted(list(set(s[3] for s in seats)))
        unique_v = sorted(list(set(s[4] for s in seats)))
        D_star = max_U
        for u in unique_u:
            for v in unique_v:
                while D_star > 0:
                    cand_D = D_star - 1
                    if get_sum(u, v, u + cand_D, v + cand_D) >= K:
                        D_star = cand_D
                    else:
                        break
        seats_by_u = [[] for _ in range(max_U + 1)]
        for s in seats:
            seats_by_u[s[3]].append(s)
        best_aura_sum = float('inf')
        best_seats = []

        for u in unique_u:
            for v in unique_v:
                if get_sum(u, v, u + D_star, v + D_star) >= K:
                    if get_sum(u, v, u, v + D_star) > 0 and get_sum(u, v, u + D_star, v) > 0:
                        current_seats = []
                        for curr_u in range(u, min(u + D_star, max_U) + 1):
                            for s in seats_by_u[curr_u]:
                                if v <= s[4] <= v + D_star:
                                    current_seats.append(s)
                        current_seats.sort(key=lambda x: x[2])
                        cand = current_seats[:K]
                        curr_aura = sum(x[2] for x in cand)
                        if curr_aura < best_aura_sum:
                            best_aura_sum = curr_aura
                            best_seats = cand
        for s in best_seats:
            out.append(f"{s[0]} {s[1]}")
    print('\n'.join(out))

if __name__ == '__main__':
    sys.setrecursionlimit(2500)
    solve()