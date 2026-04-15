import sys
from fractions import Fraction

sys.setrecursionlimit(100000)

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    trace = {}

    def dfs(r, c):
        if (r, c) in trace:
            return trace[(r, c)]

        tile = factory[r][c]

        if tile == 'X':
            ans = (Fraction(0), Fraction(1))
            
        elif tile == '.':
            ans = (Fraction(0), Fraction(0))
            
        elif tile in '^<>v':
            if tile == '^': dr, dc = -1, 0
            elif tile == 'v': dr, dc = 1, 0
            elif tile == '<': dr, dc = 0, -1
            elif tile == '>': dr, dc = 0, 1

            nr, nc = r + dr, c + dc
            if not (0 <= nr < N and 0 <= nc < M):
                ans = (Fraction(1), Fraction(0))
            else:
                ans = dfs(nr, nc)
                
        elif tile == 'S':
            valid_next = []
            for dr, dc, char_last in [(-1, 0, 'v'), (1, 0, '^'), (0, -1, '>'), (0, 1, '<')]:
                nr, nc = r + dr, c + dc
                if not (0 <= nr < N and 0 <= nc < M):
                    continue
                    
                next_tile = factory[nr][nc]
                if next_tile == 'X':
                    valid_next.append((nr, nc))
                elif next_tile in '^<>v':
                    if next_tile != char_last:
                        valid_next.append((nr, nc))

            k = len(valid_next)
            if k == 0:
                ans = (Fraction(0), Fraction(1))
            else:
                frac_sp = Fraction(1, k)
                col = Fraction(0)
                dest_total = Fraction(0)
                for nr, nc in valid_next:
                    c_coll, c_dest = dfs(nr, nc)
                    col += c_coll * frac_sp
                    dest_total += c_dest * frac_sp
                ans = (col, dest_total)
                
        else:
            ans = (Fraction(0), Fraction(0))

        trace[(r, c)] = ans
        return ans

    collected, _ = dfs(0, 0)
    return collected.numerator, collected.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()