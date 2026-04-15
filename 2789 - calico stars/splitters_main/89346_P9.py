from math import gcd
from fractions import Fraction

def solve(N, M, factory):
    direction = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1)
    }

    def dtiles(r, c):
        return factory[r][c] == 'X'

    def gnext(r, c):
        tile = factory[r][c]
        if tile in direction:
            dr, dc = direction[tile]
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                return [(nr, nc)]
            else:
                return [('out', 'out')]
        elif dtiles(r, c):
            return [('destroy', 'destroy')]
        elif tile == 'S':
            neighbors = []
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M:
                    t = factory[nr][nc]
                    if dtiles(nr, nc):
                        neighbors.append((nr, nc))
                    elif t in direction:
                        odr, odc = direction[t]
                        if not (nr + odr == r and nc + odc == c):
                            neighbors.append((nr, nc))
            return neighbors
        return []

    collected = Fraction(0)
    queue = [((0, 0), Fraction(1))]

    while queue:
        (r, c), frac = queue.pop()

        if dtiles(r, c):
            continue

        nexts = gnext(r, c)
        if not nexts:
            continue

        if ('out', 'out') in nexts:
            collected += frac
            continue

        share = frac / len(nexts)
        for nr, nc in nexts:
            if nr == 'destroy':
                continue
            queue.append(((nr, nc), share))

    p = collected.numerator
    q = collected.denominator

    if p == 0:
        return 0, 1

    g = gcd(p, q)
    return p // g, q // g


def main():
    T = int(input())
    for i in range(T):
        N, M = map(int, input().split())
        factory = [input() for j in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()