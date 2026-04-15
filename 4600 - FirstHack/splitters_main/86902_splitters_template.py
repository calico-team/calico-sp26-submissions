from fractions import Fraction
from collections import deque

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """

    move = {'^': (-1,0), 'v': (1,0), '<': (0,-1), '>': (0,1)}

    in_degree = {}
    for r in range(N):
        for c in range(M):
            if factory[r][c] != '.':
                in_degree[(r,c)] = 0

    edges = {}  # (r,c) -> list of (nr,nc) it sends to
    for r in range(N):
        for c in range(M):
            tile = factory[r][c]
            if tile == '.' :
                continue
            sends = []
            if tile in move:
                dr, dc = move[tile]
                nr, nc = r+dr, c+dc
                if 0 <= nr < N and 0 <= nc < M:
                    sends.append((nr,nc))
            elif tile == 'S':
                for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                    nr, nc = r+dr, c+dc
                    if not (0 <= nr < N and 0 <= nc < M):
                        continue
                    nb = factory[nr][nc]
                    if nb == 'X':
                        sends.append((nr,nc))
                    elif nb == 'S':
                        sends.append((nr,nc))
                    elif nb in move:
                        pr, pc = move[nb]
                        if (nr+pr, nc+pc) != (r,c):
                            sends.append((nr,nc))
            edges[(r,c)] = sends
            for nb in sends:
                in_degree[nb] = in_degree.get(nb, 0) + 1

    # topo sort
    queue = deque()
    for pos, deg in in_degree.items():
        if deg == 0:
            queue.append(pos)

    flow = {(0,0): Fraction(1)}
    collected = Fraction(0)

    while queue:
        r, c = queue.popleft()
        tile = factory[r][c]
        here = flow.get((r,c), Fraction(0))

        if tile == 'X' or tile == '.':
            continue

        sends = edges.get((r,c), [])

        if tile in move:
            dr, dc = move[tile]
            nr, nc = r+dr, c+dc
            if 0 <= nr < N and 0 <= nc < M:
                flow[(nr,nc)] = flow.get((nr,nc), Fraction(0)) + here
                in_degree[(nr,nc)] -= 1
                if in_degree[(nr,nc)] == 0:
                    queue.append((nr,nc))
            else:
                collected += here

        elif tile == 'S':
            each = here / len(sends)
            for nr, nc in sends:
                flow[(nr,nc)] = flow.get((nr,nc), Fraction(0)) + each
                in_degree[(nr,nc)] -= 1
                if in_degree[(nr,nc)] == 0:
                    queue.append((nr,nc))

    if collected == 0:
        return (0, 1)
    return (collected.numerator, collected.denominator)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
