from fractions import Fraction
from functools import lru_cache


def solve(N, M, factory):
    dirs = {
        '<': (0, -1),   
        '>': (0, 1),    
        '^': (-1, 0),  
        'v': (1, 0),  
    }

    def in_b(r, c):
        return 0 <= r < N and 0 <= c < M

    @lru_cache(None)
    def prob_collector(r, c):
        tile = factory[r][c]

        if tile == 'X':
            return Fraction(0, 1)

        if tile in dirs:
            dr, dc = dirs[tile]
            nr, nc = r + dr, c + dc
            if not in_b(nr, nc):
                return Fraction(1, 1)

            return prob_collector(nr, nc)

        if tile == 'S':
            neighbors = []

            for dr, dc in dirs.values():
                nr, nc = r + dr, c + dc
                if not in_b(nr, nc):
                    continue

                nxt = factory[nr][nc]

                if nxt == 'X':
                    neighbors.append((nr, nc))
                elif nxt in dirs:
                    back_dr, back_dc = dirs[nxt]
                    if (back_dr, back_dc) != (-dr, -dc):
                        neighbors.append((nr, nc))

            total = Fraction(0, 1)
            for nr, nc in neighbors:
                total += prob_collector(nr, nc)

            return total / len(neighbors)
        return Fraction(0, 1)


    result = prob_collector(0, 0)
    return result.numerator, result.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
