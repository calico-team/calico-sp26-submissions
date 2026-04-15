from collections import deque

T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    g = [list(input().strip()) for _ in range(n)]

    q = deque([(0, 0)])
    visitor = [[0] * m for _ in range(n)]
    visitor[0][0] = 1

    exits = 0

    while q:
        r, c = q.popleft()

        if g[r][c] == 'X':
            continue

        if g[r][c] == '>':
            nxt = [(r, c + 1)]
        elif g[r][c] == '<':
            nxt = [(r, c - 1)]
        elif g[r][c] == '^':
            nxt = [(r - 1, c)]
        elif g[r][c] == 'v':
            nxt = [(r + 1, c)]
        else:
            nxt = [(r+1,c),(r-1,c),(r,c+1),(r,c-1)]

        for nr, nc in nxt:
            if nr < 0 or nr >= n or nc < 0 or nc >= m:
                exits += 1
                continue

            if g[nr][nc] != 'X' and not visitor[nr][nc]:
                visitor[nr][nc] = 1
                q.append((nr, nc))

    print("0 1" if exits == 0 else f"{exits} 1")