from fractions import Fraction
from collections import deque

def solve(N, M, factory):
    move = {'^': (-1,0), 'v': (1,0), '<': (0,-1), '>': (0,1)}
    
    amount = [[Fraction(0)] * M for _ in range(N)]
    amount[0][0] = Fraction(1)
    out = Fraction(0)
    
    todo = deque([(0, 0)])
    done = {(0, 0)}
    
    while todo:
        r, c = todo.popleft()
        tile = factory[r][c]
        here = amount[r][c]
        
        if tile == 'X':
            continue
        
        if tile in move:
            dr, dc = move[tile]
            nr, nc = r+dr, c+dc
            if 0 <= nr < N and 0 <= nc < M:
                amount[nr][nc] += here
                if (nr, nc) not in done:
                    done.add((nr, nc))
                    todo.append((nr, nc))
            else:
                out += here
        
        elif tile == 'S':
            going = []
            for dr, dc in move.values():
                nr, nc = r+dr, c+dc
                if 0 <= nr < N and 0 <= nc < M:
                    nb = factory[nr][nc]
                    if nb == 'X' or (nb in move and move[nb] != (-dr, -dc)):
                        going.append((nr, nc))
            
            each = here / len(going)
            for nr, nc in going:
                amount[nr][nc] += each
                if (nr, nc) not in done:
                    done.add((nr, nc))
                    todo.append((nr, nc))
    
    return (0, 1) if out == 0 else (out.numerator, out.denominator)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()