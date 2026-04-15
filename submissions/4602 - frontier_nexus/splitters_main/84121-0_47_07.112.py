import sys
from math import gcd
from fractions import Fraction

input = sys.stdin.readline

def solve():
    N, M = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(input().strip())

    # direction maps
    dir_map = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1),
    }

    def get_next(r, c):
        ch = grid[r][c]
        if ch in dir_map:
            dr, dc = dir_map[ch]
            nr, nc = r + dr, c + dc
            # check if exits grid
            if 0 <= nr < N and 0 <= nc < M:
                return [(nr, nc)]
            else:
                return [None]  # collected
        elif ch == 'X':
            return ['destroy']
        elif ch == 'S':
            neighbors = []
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r+dr, c+dc
                if 0 <= nr < N and 0 <= nc < M:
                    t = grid[nr][nc]
                    # valid if destroy tile, or conveyor not pointing back at splitter
                    if t == 'X':
                        neighbors.append((nr, nc))
                    elif t in dir_map:
                        ndr, ndc = dir_map[t]
                        # points back at splitter if going to (r,c)
                        if (nr + ndr, nc + ndc) == (r, c):
                            pass  # invalid
                        else:
                            neighbors.append((nr, nc))
            return neighbors
        return []

    # simulate with fractions tracking what fraction of items reach each tile
    # start at (0,0) with fraction 1
    # BFS/DFS since no cycles guaranteed (items never visit same tile twice)

    from collections import deque

    flow = {}  # (r,c) -> fraction of total items
    flow[(0, 0)] = Fraction(1)

    queue = deque()
    queue.append((0, 0))

    collected = Fraction(0)

    while queue:
        r, c = queue.popleft()
        f = flow[(r, c)]
        ch = grid[r][c]

        if ch == 'X':
            # destroyed, don't propagate
            continue

        nexts = get_next(r, c)

        if ch == 'S':
            # split evenly among valid neighbors
            if not nexts:
                continue
            share = f / len(nexts)
            for dest in nexts:
                nr, nc = dest
                if (nr, nc) not in flow:
                    flow[(nr, nc)] = Fraction(0)
                    queue.append((nr, nc))
                flow[(nr, nc)] += share
        else:
            # conveyor
            for dest in nexts:
                if dest is None:
                    # exits grid = collected
                    collected += f
                elif dest == 'destroy':
                    pass
                else:
                    nr, nc = dest
                    if grid[nr][nc] == 'X':
                        pass  # destroyed
                    else:
                        if (nr, nc) not in flow:
                            flow[(nr, nc)] = Fraction(0)
                            queue.append((nr, nc))
                        flow[(nr, nc)] += f

    # also check if top-left is a destroy tile
    if grid[0][0] == 'X':
        collected = Fraction(0)

    p = collected.numerator
    q = collected.denominator
    print(p, q)


def main():
    T = int(input())
    for _ in range(T):
        solve()


def read_your_input():
    data = sys.stdin.buffer.read().split()
    return data


main()