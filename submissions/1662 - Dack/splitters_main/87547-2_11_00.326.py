def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    from fractions import Fraction
    
    directions = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1)
    }
    
    memo = [[None] * M for _ in range(N)]
    
    def get_valid_neighbors(r, c):
        neighbors = []
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                tile = factory[nr][nc]
                if tile == 'X' or tile == 'S':
                    neighbors.append((nr, nc))
                elif tile in directions:
                    dr2, dc2 = directions[tile]
                    if not (nr + dr2 == r and nc + dc2 == c):
                        neighbors.append((nr, nc))
        return neighbors
    
    def compute(r, c):
        if memo[r][c] is not None:
            return memo[r][c]
        
        tile = factory[r][c]
        
        if tile == '.':
            memo[r][c] = Fraction(0)
            return memo[r][c]
        
        if tile == 'X':
            memo[r][c] = Fraction(0)
            return memo[r][c]
        
        if tile in directions:
            dr, dc = directions[tile]
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                memo[r][c] = compute(nr, nc)
            else:
                memo[r][c] = Fraction(1)
            return memo[r][c]
        
        if tile == 'S':
            neighbors = get_valid_neighbors(r, c)
            if not neighbors:
                memo[r][c] = Fraction(0)
                return memo[r][c]
            
            total = Fraction(0)
            for nr, nc in neighbors:
                total += compute(nr, nc)
            memo[r][c] = total / len(neighbors)
            return memo[r][c]
        
        memo[r][c] = Fraction(0)
        return memo[r][c]
    
    result = compute(0, 0)
    
    p = result.numerator
    q = result.denominator
    
    return (p, q)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
