import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
    N, M, K = map(int, input().split())
    grid = [input().strip() for _ in range(N)]
    seats = [(r,c) for r in range(N) for c in range(M) if grid[r][c]=='-']
    best = float('inf')
    res = []
    for i in range(len(seats)-K+1):
        group = seats[i:i+K]
        d = max(abs(group[a][0]-group[b][0])+abs(group[a][1]-group[b][1]) for a in range(K) for b in range(K))
        if d < best:
            best = d
            res = group
    for r,c in res: print(r,c)