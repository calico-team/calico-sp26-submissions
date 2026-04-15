def solve(N, M, factory):
    grid = [[[0, 1] for _ in range(M)] for _ in range(N)]
    p_num, p_den = 0, 1
    if factory[0][0] == 'X':
        return 0, 1
    grid[0][0] = [1, 1]
    for _ in range(N * M + 1):
        for r in range(N):
            for c in range(M):
                n, d = grid[r][c]
                if n == 0:
                    continue
                tile = factory[r][c]
                grid[r][c] = [0, 1]
                targets = []
                if tile == '^':
                    targets.append((r - 1, c, n, d))
                elif tile == 'v':
                    targets.append((r + 1, c, n, d))
                elif tile == '<':
                    targets.append((r, c - 1, n, d))
                elif tile == '>':
                    targets.append((r, c + 1, n, d))
                elif tile == 'S':
                    valid = []
                    adj = [(-1, 0, 'v'), (1, 0, '^'), (0, -1, '>'), (0, 1, '<')]
                    for dr, dc, opp in adj:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < N and 0 <= nc < M:
                            nt = factory[nr][nc]
                            if nt == 'X':
                                valid.append((nr, nc))
                            elif nt in '^v<>':
                                if nt != opp:
                                    valid.append((nr, nc))
                    if valid:
                        for nr, nc in valid:
                            targets.append((nr, nc, n, d * len(valid)))
                for nr, nc, tn, td in targets:
                    if 0 <= nr < N and 0 <= nc < M:
                        an, ad = grid[nr][nc]
                        nn, nd = an * td + tn * ad, ad * td
                        a, b = nn, nd
                        while b:
                            a, b = b, a % b
                        grid[nr][nc] = [nn // a, nd // a]
                    else:
                        nn, nd = p_num * td + tn * p_den, p_den * td
                        a, b = nn, nd
                        while b:
                            a, b = b, a % b
                        p_num, p_den = nn // a, nd // a
    return p_num, p_den
def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)
if __name__ == '__main__':
    main()
