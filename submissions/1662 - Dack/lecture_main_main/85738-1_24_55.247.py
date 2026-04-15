def solve(N, M, K, GRID):
    available = []
    for r in range(N):
        for c in range(M):
            if GRID[r][c] == '-':
                left = sum(1 for cc in range(c) if GRID[r][cc] == '#')
                right = sum(1 for cc in range(c+1, M) if GRID[r][cc] == '#')
                aura = min(left, right)
                available.append((r, c, aura))

    def can_fit(seats, d):
        for i in range(len(seats)):
            group = [seats[i]]
            for j in range(i+1, len(seats)):
                if all(abs(seats[j][0]-s[0]) + abs(seats[j][1]-s[1]) <= d for s in group):
                    group.append(seats[j])
                if len(group) == K:
                    return True
        return False

    lo, hi = 0, 2 * (N + M)
    while lo < hi:
        mid = (lo + hi) // 2
        if can_fit(available, mid):
            hi = mid
        else:
            lo = mid + 1

    best_group = None
    best_aura = float('inf')

    for i in range(len(available)):
        group = [available[i]]
        for j in range(i+1, len(available)):
            if all(abs(available[j][0]-s[0]) + abs(available[j][1]-s[1]) <= lo for s in group):
                group.append(available[j])
            if len(group) == K:
                break
        if len(group) == K:
            aura = sum(s[2] for s in group)
            if aura < best_aura:
                best_aura = aura
                best_group = group

    return [(r, c) for r, c, _ in best_group]


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = []
        for _ in range(N):
            GRID.append(input().strip())
        result = solve(N, M, K, GRID)
        for r, c in result:
            print(f"{r} {c}")


if __name__ == '__main__':
    main()