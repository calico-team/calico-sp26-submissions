import sys
from sortedcontainers import SortedList

def solve():
    input_data = sys.stdin.buffer.read().decode()
    tokens = input_data.split()
    idx = 0
    def next_token():
        nonlocal idx
        val = tokens[idx]
        idx += 1
        return val

    T = int(next_token())
    results = []

    for _ in range(T):
        N, M, K = int(next_token()), int(next_token()), int(next_token())
        grid = []
        available = []
        for r in range(N):
            row = next_token()
            grid.append(row)
            for c in range(M):
                if row[c] == '-':
                    available.append((r, c))

        if K == 1:
            results.append(f"{available[0][0]} {available[0][1]}")
            continue

        # Rotate: u = r+c, v = r-c
        # Manhattan dist = max(|u1-u2|, |v1-v2|) (Chebyshev in rotated)
        rotated = []
        for r, c in available:
            rotated.append((r + c, r - c, r, c))
        rotated.sort()

        S = len(rotated)

        def check(D):
            # Find K points with Chebyshev distance <= D
            # i.e., max u - min u <= D and max v - min v <= D
            # Sort by u, sliding window where u_max - u_min <= D
            # Within window, need K points with v range <= D
            # Use sorted structure on v, sliding window
            best = None
            j = 0
            vs = SortedList()
            indices_in_window = []
            for i in range(S):
                u_i, v_i, r_i, c_i = rotated[i]
                vs.add(v_i)
                indices_in_window.append(i)
                while rotated[j][0] < u_i - D:
                    vs.remove(rotated[j][1])
                    indices_in_window.pop(0)
                    j += 1
                if len(vs) >= K:
                    # Sliding window on sorted v values to find K consecutive with range <= D
                    vs_list = list(vs)
                    for p in range(len(vs_list) - K + 1):
                        if vs_list[p + K - 1] - vs_list[p] <= D:
                            v_lo, v_hi = vs_list[p], vs_list[p + K - 1]
                            chosen = []
                            for idx2 in indices_in_window:
                                uu, vv, rr, cc = rotated[idx2]
                                if v_lo <= vv <= v_hi:
                                    chosen.append((rr, cc))
                                    if len(chosen) == K:
                                        break
                            return chosen
            return None

        lo, hi = 0, N + M - 2
        ans = None
        while lo <= hi:
            mid = (lo + hi) // 2
            res = check(mid)
            if res is not None:
                ans = res
                hi = mid - 1
            else:
                lo = mid + 1

        for r, c in ans:
            results.append(f"{r} {c}")

    print('\n'.join(results))

solve()
