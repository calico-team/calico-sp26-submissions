import sys
from collections import deque
input = sys.stdin.readline

def solve(N, M, K, GRID):
    seats = []
    for r in range(N):
        left_occ = 0
        right_occ = sum(1 for c2 in range(M) if GRID[r][c2] == '#')
        for c in range(M):
            if GRID[r][c] == '#':
                right_occ -= 1
                left_occ += 1
            else:
                aura = min(left_occ, right_occ)
                seats.append((r + c, r - c, r, c, aura))

    seats.sort()
    S = len(seats)
    if S == 0:
        return []

    aura_vals_sorted = sorted(set(s[4] for s in seats))
    aura_rank = {v: i + 1 for i, v in enumerate(aura_vals_sorted)}
    A = len(aura_vals_sorted)

    def find_best(D):
        bit_cnt = [0] * (A + 2)
        bit_sum = [0] * (A + 2)

        def update(i, delta_cnt, delta_sum):
            j = i
            while j <= A:
                bit_cnt[j] += delta_cnt
                bit_sum[j] += delta_sum
                j += j & (-j)

        def query_k_sum(k):
            pos = 0
            cnt_acc = 0
            sum_acc = 0
            for i in range(A.bit_length(), -1, -1):
                npos = pos + (1 << i)
                if npos <= A and cnt_acc + bit_cnt[npos] < k:
                    cnt_acc += bit_cnt[npos]
                    sum_acc += bit_sum[npos]
                    pos = npos
            remaining = k - cnt_acc
            sum_acc += aura_vals_sorted[pos] * remaining
            return sum_acc

        max_dq = deque()
        min_dq = deque()
        best_sum = None
        best_l = best_r = -1
        left = 0

        for right in range(S):
            u_r, v_r, _, _, a_r = seats[right]
            while max_dq and seats[max_dq[-1]][1] <= v_r:
                max_dq.pop()
            max_dq.append(right)
            while min_dq and seats[min_dq[-1]][1] >= v_r:
                min_dq.pop()
            min_dq.append(right)
            rk = aura_rank[a_r]
            update(rk, 1, a_r)

            while left <= right:
                if (seats[right][0] - seats[left][0] <= D and
                        seats[max_dq[0]][1] - seats[min_dq[0]][1] <= D):
                    break
                al = seats[left][4]
                update(aura_rank[al], -1, -al)
                if max_dq[0] == left:
                    max_dq.popleft()
                if min_dq[0] == left:
                    min_dq.popleft()
                left += 1

            if right - left + 1 >= K:
                s = query_k_sum(K)
                if best_sum is None or s < best_sum:
                    best_sum = s
                    best_l, best_r = left, right

        if best_sum is None:
            return None
        window = sorted(seats[best_l:best_r + 1], key=lambda x: x[4])
        return window[:K]

    lo, hi = 0, (N + M) * 2
    result = None
    while lo <= hi:
        mid = (lo + hi) // 2
        res = find_best(mid)
        if res is not None:
            result = res
            hi = mid - 1
        else:
            lo = mid + 1

    return [(s[2], s[3]) for s in result]

def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = [input().strip() for _ in range(N)]
        for r, c in solve(N, M, K, GRID):
            print(r, c)

if __name__ == '__main__':
    main()