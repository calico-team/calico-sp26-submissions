def make_the_criss_cross(n, m):
    grid = []
    for r in range(n):
        row = [(r + 2 * c) % 5 for c in range(m)]
        grid.append(row)
    return grid

def read_your_input():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        grid = make_the_criss_cross(n, m)
        for row in grid:
            print(*row)

read_your_input()
