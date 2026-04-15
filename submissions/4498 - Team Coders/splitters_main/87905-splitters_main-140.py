import math
import sys

# Increase recursion depth for the 15x15 grid
sys.setrecursionlimit(2000)

def get_gcd(p, q):
    return math.gcd(p, q)

def simplify(p, q):
    if p == 0: return 0, 1
    common = get_gcd(p, q)
    return p // common, q // common

def add_fractions(p1, q1, p2, q2):
    num = p1 * q2 + p2 * q1
    den = q1 * q2
    return simplify(num, den)

# Global memoization table
memo = {}

def get_flow(r, c, N, M, factory):
    # Base Case: Out of bounds means the item is collected
    if not (0 <= r < N and 0 <= c < M):
        return (1, 1)
    
    state = (r, c)
    if state in memo:
        return memo[state]
    
    tile = factory[r][c].upper()
    
    # Base Case: Destroyer or unreachable
    if tile == 'X' or tile == '.':
        res = (0, 1)
    
    elif tile in '^V<>':
        # Conveyor movement
        dr, dc = 0, 0
        if tile == '^': dr, dc = -1, 0
        elif tile == 'V': dr, dc = 1, 0
        elif tile == '<': dr, dc = 0, -1
        elif tile == '>': dr, dc = 0, 1
        res = get_flow(r + dr, c + dc, N, M, factory)
        
    elif tile == 'S':
        # Splitter logic
        valid_neighbors = []
        directions = [(-1, 0, 'V'), (1, 0, '^'), (0, -1, '>'), (0, 1, '<')]
        for dr, dc, back_char in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                n_tile = factory[nr][nc].upper()
                if n_tile == 'X' or (n_tile in '^V<>' and n_tile != back_char):
                    valid_neighbors.append((nr, nc))
        
        if not valid_neighbors:
            res = (0, 1)
        else:
            total_p, total_q = 0, 1
            num_valid = len(valid_neighbors)
            for nr, nc in valid_neighbors:
                p, q = get_flow(nr, nc, N, M, factory)
                total_p, total_q = add_fractions(total_p, total_q, p, q * num_valid)
            res = (total_p, total_q)
    else:
        res = (0, 1)

    memo[state] = res
    return res

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    global memo
    memo = {}
    # Ensure grid handles leading/trailing spaces for robustness
    factory_padded = [row.ljust(M) for row in factory]
    return get_flow(0, 0, N, M, factory_padded)


def main():
    try:
        T_str = sys.stdin.readline().strip()
        if not T_str: return
        T = int(T_str)
        for _ in range(T):
            line = sys.stdin.readline()
            while line and not line.strip(): line = sys.stdin.readline()
            if not line: break
            
            N, M = map(int, line.split())
            factory = [sys.stdin.readline().rstrip('\n\r') for _ in range(N)]
            P, Q = solve(N, M, factory)
            print(P, Q)
    except EOFError:
        pass


if __name__ == '__main__':
    main()