import sys

def your_inp():
    data = [int(toke) for toke in sys.stdin.read().split() if toke.lstrip("-").isdigit()]
    if not data:
        return []
    it = iter(data)
    tt1 = int(next(it))
    cases = []
    for _ in range(tt1):
        n = int(next(it))
        m = int(next(it))
        cases.append((n, m))
    return cases


def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    return make(N, M)

def make(N, M):
    grid = [[0 for _ in range(M)] for _ in range(N)]
    for r in range(N):
        for c in range(M):
            grid[r][c] = (r + 2 * c) % 5
    return grid




def main():
    cases = your_inp()
    out = []
    for n, m in cases:
        grid = solve(n, m)
        for row in grid:
            out.append(' '.join(str(x) for x in row))
    sys.stdout.write('\n'.join(out))



