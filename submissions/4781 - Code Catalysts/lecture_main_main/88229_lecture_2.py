def solve(N, M, K, GRID):
    seats = []

    for i in range(N):
        for j in range(M):
            if GRID[i][j] == '-':
                seats.append((i, j))

    if K == 0:
        return []

    chosen = [seats[0]]
    used = set()
    used.add(seats[0])

    while len(chosen) < K:
        best = None
        best_dist = 10**18

        for s in seats:
            if s in used:
                continue
                
            dist = 10**18
            for c in chosen:
                dist = min(dist, abs(s[0] - c[0]) + abs(s[1] - c[1]))

            if dist < best_dist:
                best_dist = dist
                best = s

        chosen.append(best)
        used.add(best)

    return chosen


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = [input().strip() for _ in range(N)]
        res = solve(N, M, K, GRID)

        for r, c in res:
            print(r, c)


if __name__ == "__main__":
    main()