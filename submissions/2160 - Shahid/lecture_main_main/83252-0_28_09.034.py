import sys
from bisect import insort, bisect_left

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
            j = 0
            vs = []
            indices_in_window = []
            for i in range(S):
                u_i, v_i, r_i, c_i = rotated[i]
                insort(vs, v_i)
                indices_in_window.append(i)
                while rotated[j][0] < u_i - D:
                    rem_v = rotated[j][1]
                    pos = bisect_left(vs, rem_v)
                    vs.pop(pos)
                    indices_in_window.pop(0)
                    j += 1
                if len(vs) >= K:
                    for p in range(len(vs) - K + 1):
                        if vs[p + K - 1] - vs[p] <= D:
                            v_lo, v_hi = vs[p], vs[p + K - 1]
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
