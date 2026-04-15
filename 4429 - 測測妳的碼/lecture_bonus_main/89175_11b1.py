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
        M = int(input_data[idx+1])
        K = int(input_data[idx+2])
        idx += 3
        grid = input_data[idx : idx+N]
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
            for c in range(M-1, -1, -1):
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
                pref[i][j] = pref[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]
        unique_u = sorted(list(set(s[3] for s in seats)))
        unique_v = sorted(list(set(s[4] for s in seats)))
        D_star = max_U
        for u in unique_u:
            for v in unique_v:
                while D_star > 0:
                    cand = D_star - 1
                    u2 = u + cand
                    if u2 > max_U: u2 = max_U
                    v2 = v + cand
                    if v2 > max_V: v2 = max_V
                    s = pref[u2+1][v2+1] - pref[u][v2+1] - pref[u2+1][v] + pref[u][v]
                    if s >= K:
                        D_star = cand
                    else:
                        break
        seats_by_u = [[] for _ in range(max_U + 1)]
        for s in seats:
            seats_by_u[s[3]].append(s)
        best_aura_sum = float('inf')
        best_seats = []
        found_optimal = False
        for u in unique_u:
            if found_optimal: break
            for v in unique_v:
                u2 = u + D_star
                if u2 > max_U: u2 = max_U
                v2 = v + D_star
                if v2 > max_V: v2 = max_V
                s_total = pref[u2+1][v2+1] - pref[u][v2+1] - pref[u2+1][v] + pref[u][v]
                if s_total >= K:
                    top = (pref[u+1][v2+1] - pref[u][v2+1] - pref[u+1][v] + pref[u][v]) > 0
                    if not top: continue
                    left = (pref[u2+1][v+1] - pref[u][v+1] - pref[u2+1][v] + pref[u][v]) > 0
                    if not left: continue
                    bottom = (pref[u2+1][v2+1] - pref[u2][v2+1] - pref[u2+1][v] + pref[u2][v]) > 0
                    right = (pref[u2+1][v2+1] - pref[u][v2+1] - pref[u2+1][v2] + pref[u][v2]) > 0
                    if bottom or right:
                        current_seats = [s for curr_u in range(u, u2 + 1)
                                           for s in seats_by_u[curr_u]
                                           if v <= s[4] <= v2]
                        current_seats.sort(key=lambda x: x[2])
                        cand = current_seats[:K]
                        curr_aura = sum(x[2] for x in cand)
                        if curr_aura < best_aura_sum:
                            best_aura_sum = curr_aura
                            best_seats = cand
                            if best_aura_sum == 0:
                                found_optimal = True
                                break
        for s in best_seats:
            out.append(f"{s[0]} {s[1]}")
    print('\n'.join(out))

if __name__ == '__main__':
    solve()