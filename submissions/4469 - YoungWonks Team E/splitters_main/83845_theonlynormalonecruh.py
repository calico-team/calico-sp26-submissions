from fractions import Fraction
from collections import deque

def main():
    n, m = map(int, input().split())
    grid = []
    for i in range(n):
        grid.append(input())
    move = {"v": (1, 0), "^": (-1, 0), "<": (0, -1), ">": (0, 1)}
    collected = Fraction(0)
    queue = deque()
    queue.append((0, 0, Fraction(1)))

    while queue:
        r, c, amt = queue.popleft()
        cell = grid[r][c]

        if cell in move:
            dr, dc = move[cell]
            nr, nc = r + dr, c + dc
            if nr < 0 or nr >= n or nc < 0 or nc >= m:
                collected += amt
            else:
                queue.append((nr, nc, amt))

        elif cell == "X":
            continue

        elif cell == "S":
            targets = []
            neighbors = [(r - 1, c, 1, 0), (r + 1, c, -1, 0), (r, c - 1, 0, 1), (r, c + 1, 0, -1)]
            for nr, nc, br, bc in neighbors:
                if nr < 0 or nr >= n or nc < 0 or nc >= m:
                    continue
                adj = grid[nr][nc]
                if adj == "X":
                    targets.append((nr, nc))
                elif adj in move:
                    adr, adc = move[adj]
                    if not (adr == br and adc == bc):
                        targets.append((nr, nc))
            if len(targets) > 0:
                part = amt / len(targets)
                for nr, nc in targets:
                    queue.append((nr, nc, part))
    print(collected.numerator, collected.denominator)

t = int(input())
for i in range(t):
    main()