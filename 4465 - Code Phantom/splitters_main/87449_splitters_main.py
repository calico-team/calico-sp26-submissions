from fractions import Fraction


def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    directions = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1),
    }

    memo = {}

    def in_bounds(r, c):
        return 0 <= r < N and 0 <= c < M

    def outgoing_edges(r, c):
        cell = factory[r][c]
        if cell in directions:
            dr, dc = directions[cell]
            return [((r + dr, c + dc), Fraction(1))]
        
        if cell == 'S':
            neighbors = []
            for d_name, (dr, dc) in directions.items():
                nr, nc = r + dr, c + dc
                adj_tile = factory[nr][nc]
              
                if adj_tile == 'X':
                    neighbors.append((nr, nc))
                elif adj_tile in directions:
                    adr, adc = directions[adj_tile]
                    if (nr + adr, nc + adc) != (r, c):
                        neighbors.append((nr, nc))
            
            if not neighbors: return []
            weight = Fraction(1, len(neighbors))
            return [(pos, weight) for pos in neighbors]
        return []

    def dfs(r, c):
        if not in_bounds(r, c):
            return Fraction(1)
        if (r, c) in memo:
            return memo[(r, c)]
        cell = factory[r][c]
        if cell == 'X' or cell == '.':
            memo[(r, c)] = Fraction(0)
            return Fraction(0)
        edges = outgoing_edges(r, c)
        if not edges:
            memo[(r, c)] = Fraction(0)
            return Fraction(0)
        total = Fraction(0)
        for (nr, nc), weight in edges:
            total += weight * dfs(nr, nc)
        memo[(r, c)] = total
        return total

    result = dfs(0, 0)
    return result.numerator, result.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input().strip() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
