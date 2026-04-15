import sys
input = sys.stdin.readline

def make_the_criss_cross(N, M):
    grid = [[0] * M for _ in range(N)]
    for r in range(N):
        for c in range(M):
            if r % 2 == 1:
                grid[r][c] = c % 4 + 1
            else:
                grid[r][c] = 0
    return grid

def read_your_input():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = make_the_criss_cross(N, M)
        for row in grid:
            print(*row)

read_your_input()