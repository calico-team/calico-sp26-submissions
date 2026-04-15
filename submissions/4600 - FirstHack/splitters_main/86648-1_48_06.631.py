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

    flow = {}
    flow[(0,0)] = Fraction(1)
    queue = deque([(0,0)])
    visited = set()
    visited.add((0,0))
    collected = Fraction(0)

    while queue:
        r, c = queue.popleft()
        tile = factory[r][c]
        here = flow.get((r,c), Fraction(0))
        if here == 0:
            continue

        if tile == 'X':
            continue

        if tile in move:
            dr, dc = move[tile]
            nr, nc = r+dr, c+dc
            if 0 <= nr < N and 0 <= nc < M:
                flow[(nr,nc)] = flow.get((nr,nc), Fraction(0)) + here
                if (nr,nc) not in visited:
                    visited.add((nr,nc))
                    queue.append((nr,nc))
            else:
                collected += here

        if tile == 'S':
            neighbors = []
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r+dr, c+dc
                if not (0 <= nr < N and 0 <= nc < M):
                    continue
                nb = factory[nr][nc]
                if nb == 'X':
                    neighbors.append((nr,nc))
                elif nb in move:
                    pr, pc = move[nb]
                    if (nr+pr, nc+pc) != (r,c):
                        neighbors.append((nr,nc))

            each = here / len(neighbors)
            for nr, nc in neighbors:
                flow[(nr,nc)] = flow.get((nr,nc), Fraction(0)) + each
                if (nr,nc) not in visited:
                    visited.add((nr,nc))
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
