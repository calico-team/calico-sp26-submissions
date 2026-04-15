import sys
input = sys.stdin.readline

def solve(N, M):
    grid = [[0]*M for _ in range(N)]
    for r in range(N):
        for c in range(M):
            grid[r][c] = (r * 2 + c) % 5
    return grid

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    grid = solve(N, M)
    out = []
    for row in grid:
        out.append(' '.join(map(str, row)))
    print('\n'.join(out))