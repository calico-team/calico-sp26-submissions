def make_the_criss_cross(N, M):
    grid = [[0 for _ in range(M)] for _ in range(N)]
    
    for r in range(N):
        for c in range(M):
            grid[r][c] = (r + 2 * c) % N
            
    return grid

def solve(N, M):
    return make_the_criss_cross(N, M)

def read_your_input():
    import sys
    raw_data = sys.stdin.read().split()
    if not raw_data:
        return
        
    idx = 0
    num_test_cases = int(raw_data[idx])
    idx += 1
    
    for _ in range(num_test_cases):
        rows = int(raw_data[idx])
        cols = int(raw_data[idx + 1])
        idx += 2
        
        ans_grid = solve(rows, cols)
        for row in ans_grid:
            print(*(row))

if __name__ == '__main__':
    read_your_input()