from collections import deque

def solve():
    T = int(input())

    for _ in range(T):
        n, m = map(int, input().split())
        grid = [list(input().strip()) for _ in range(n)]

        q = deque()
        q.append((0, 0))

        exits = 0

        while q:
            r, c = q.popleft()

            # outside grid = exit
            if not (0 <= r < n and 0 <= c < m):
                exits += 1
                continue

            cell = grid[r][c]

            if cell == 'X':
                continue

            # decide movement
            if cell == '>':
                q.append((r, c + 1))

            elif cell == '<':
                q.append((r, c - 1))

            elif cell == '^':
                q.append((r - 1, c))

            elif cell == 'v':
                q.append((r + 1, c))

            elif cell == 'S':
                for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                    nr, nc = r + dr, c + dc
                    q.append((nr, nc))

            else:
               
                continue

        
        if exits == 0:
            print("0 1")
        else:
            print(exits, 1)

solve()