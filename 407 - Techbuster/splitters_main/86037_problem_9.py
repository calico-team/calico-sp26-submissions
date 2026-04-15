import sys
from fractions import Fraction
from collections import deque
input = sys.stdin.readline

DIR= {'>': (0, 1), '<': (0, -1), '^': (-1, 0), 'v': (1, 0)}

def destroy_tiles(grid, Z, M):

    def get_successors(r, c):

        tile = grid[r][c]
        if tile in ('.', 'X'):
            return []
        if tile in DIR:
            dr, dc =DIR[tile]
            nr, nc= r + dr, c + dc
            if 0 <= nr < Z and 0 <= nc < M:
                return [(nr, nc, Fraction(1))]
            return [('out', Fraction(1))]
        if tile =='S':
            valid = []
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc =r + dr, c + dc
                if not (0 <= nr < Z and 0 <= nc < M):
                    continue
                nb = grid[nr][nc]
                if nb == 'X':
                    valid.append((nr, nc))
                elif nb in DIR:
                    pdr, pdc = DIR[nb]
                    if (nr + pdr, nc + pdc) != (r, c): 
                        valid.append((nr, nc))
            k = len(valid)
            return [(nr, nc, Fraction(1, k)) for nr, nc in valid]
        return []

    pred_count = [[0] * M for _ in range(Z)]
    for r in range(Z):
        for c in range(M):
            for item in get_successors(r, c):
                if item[0] == 'out':
                    continue
                pred_count[item[0]][item[1]] += 1

    weight = [[Fraction(0)] * M for _ in range(Z)]
    weight[0][0] = Fraction(1)
    remaining = [row[:] for row in pred_count]

    collected = Fraction(0)
    queue = deque([(0, 0)])

    while queue:
        r, c = queue.popleft()
        w = weight[r][c]
        if w == 0:
            continue
        for item in get_successors(r, c):
            if item[0] == 'out':
                collected += w * item[1]
            else:
                nr, nc, frac = item
                weight[nr][nc] += w * frac
                remaining[nr][nc] -= 1
                if remaining[nr][nc] == 0:
                    queue.append((nr, nc))

    if collected== 0:
        return 0, 1
    return collected.numerator, collected.denominator


def read_input():
    T = int(input())
    for _ in range(T):
        Z, M = map(int, input().split())
        grid =[input().strip() for _ in range(Z)]
        H, q= destroy_tiles(grid, Z, M)
        print(H, q)

read_input()