import math

def get_gcd(p, q):
    return math.gcd(p, q)

def simplify(p, q):
    common = get_gcd(p, q)
    return p // common, q // common

def add_fractions(p1, q1, p2, q2):
    # p1/q1 + p2/q2 = (p1*q2 + p2*q1) / (q1*q2)
    num = p1 * q2 + p2 * q1
    den = q1 * q2
    return simplify(num, den)

def solve(N, M, factory):
    # probabilities[r][c] stores the fraction of total items at tile (r, c)
    # stored as (numerator, denominator)
    probs = [[(0, 1) for _ in range(M)] for _ in range(N)]
    probs[0][0] = (1, 1)
    
    collected_p, collected_q = 0, 1
    
    # Process tiles. Since there are no loops and items move forward, 
    # we can iterate in a way that ensures we process inputs before outputs.
    # A simple BFS/Queue approach works well here.
    queue = [(0, 0)]
    visited = [[False for _ in range(M)] for _ in range(N)]
    visited[0][0] = True
    
    idx = 0
    while idx < len(queue):
        r, c = queue[idx]
        idx += 1
        
        curr_p, curr_q = probs[r][c]
        if curr_p == 0:
            continue
            
        tile = factory[r][c]
        
        if tile == 'x' or tile == '.':
            continue # Items are destroyed or cannot reach empty tiles
            
        elif tile in '^v<>':
            # Conveyor movement
            dr, dc = 0, 0
            if tile == '^': dr = -1
            elif tile == 'v': dr = 1
            elif tile == '<': dc = -1
            elif tile == '>': dc = 1
            
            nr, nc = r + dr, c + dc
            
            # Check if collected (moves out of bounds)
            if not (0 <= nr < N and 0 <= nc < M):
                collected_p, collected_q = add_fractions(collected_p, collected_q, curr_p, curr_q)
            else:
                probs[nr][nc] = add_fractions(probs[nr][nc][0], probs[nr][nc][1], curr_p, curr_q)
                if not visited[nr][nc]:
                    visited[nr][nc] = True
                    queue.append((nr, nc))
                    
        elif tile == 's':
            # Splitter logic: find valid neighbors
            valid_neighbors = []
            for dr, dc, back_char in [(-1, 0, 'v'), (1, 0, '^'), (0, -1, '>'), (0, 1, '<')]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M:
                    n_tile = factory[nr][nc]
                    # Valid if it's a destroy tile or a conveyor not pointing back
                    if n_tile == 'x' or (n_tile in '^v<>' and n_tile != back_char):
                        valid_neighbors.append((nr, nc))
            
            if valid_neighbors:
                # Split current probability equally
                split_p, split_q = simplify(curr_p, curr_q * len(valid_neighbors))
                for nr, nc in valid_neighbors:
                    probs[nr][nc] = add_fractions(probs[nr][nc][0], probs[nr][nc][1], split_p, split_q)
                    if not visited[nr][nc]:
                        visited[nr][nc] = True
                        queue.append((nr, nc))

    return collected_p, collected_q

def main():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    ptr = 1
    for _ in range(T):
        N = int(input_data[ptr])
        M = int(input_data[ptr+1])
        ptr += 2
        factory = input_data[ptr : ptr + N]
        ptr += N
        
        P, Q = solve(N, M, factory)
        print(f"{P} {Q}")

def read_your_input():
    main()

if __name__ == '__main__':
    main()