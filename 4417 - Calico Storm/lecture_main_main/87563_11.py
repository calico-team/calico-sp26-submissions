import sys
from sortedcontainers import SortedList

input = sys.stdin.readline


def compute_aura_loss(grid, N, M):
    aura = {}
    for r in range(N):
        row = grid[r]
        prefix = [0] * (M + 1)
        for c in range(M):
            prefix[c + 1] = prefix[c] + (1 if row[c] == '#' else 0)
        total = prefix[M]
        for c in range(M):
            if row[c] == '-':
                aura[(r, c)] = min(prefix[c], total - prefix[c + 1])
    return aura


def check_feasible(seats, D, K):
    sv = SortedList()
    left = 0
    for right in range(len(seats)):
        ur, vr = seats[right]
        sv.add(vr)
        while ur - seats[left][0] > D:
            sv.remove(seats[left][1])
            left += 1
        if len(sv) >= K:
            for i in range(len(sv) - K + 1):
                if sv[i + K - 1] - sv[i] <= D:
                    return True
    return False


def find_answer(seats, D, K, bonus):
    sv = SortedList()
    left = 0
    best_seats = None
    best_aura = float('inf')

    for right in range(len(seats)):
        cur = seats[right]
        sv.add((cur[1], cur[2], cur[3], cur[4]))

        while cur[0] - seats[left][0] > D:
            l = seats[left]
            sv.remove((l[1], l[2], l[3], l[4]))
            left += 1

        size = len(sv)
        if size >= K:
            for i in range(size - K + 1):
                if sv[i + K - 1][0] - sv[i][0] <= D:
                    group = [sv[i + j] for j in range(K)]
                    if not bonus:
                        return [(s[1], s[2]) for s in group]
                    total_aura = sum(s[3] for s in group)
                    if total_aura < best_aura:
                        best_aura = total_aura
                        best_seats = [(s[1], s[2]) for s in group]
                    break

    return best_seats


def solve():
    N, M, K = map(int, input().split())
    grid = [input().strip() for _ in range(N)]

    aura_map = compute_aura_loss(grid, N, M)

    seats = []
    for r in range(N):
        for c in range(M):
            if grid[r][c] == '-':
                seats.append((r + c, r - c, r, c, aura_map.get((r, c), 0)))
    seats.sort()

    simple = [(s[0], s[1]) for s in seats]

    lo, hi = 0, 2 * (N + M)
    while lo < hi:
        mid = (lo + hi) // 2
        if check_feasible(simple, mid, K):
            hi = mid
        else:
            lo = mid + 1

    result = find_answer(seats, lo, K, True)
    print('\n'.join(f"{r} {c}" for r, c in result))


def main():
    T = int(input())
    for _ in range(T):
        solve()


main()