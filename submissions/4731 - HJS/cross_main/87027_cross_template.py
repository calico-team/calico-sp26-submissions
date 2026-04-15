def make_the_criss_cross(N, M):
    grid = []
    for r in range(N):
        row = []
        for c in range(M):
            # The pattern (r + 2*c) % 5 ensures that for any cell (r,c),
            # its neighbors (r-1,c), (r+1,c), (r,c-1), (r,c+1) and itself
            # all have unique values from 0 to 4.
            val = (r + 2 * c) % 5
            row.append(val)
        grid.append(row)
    return grid

def solve(N, M):
    return make_the_criss_cross(N, M)

def read_your_input():
    import sys
    # Using sys.stdin.read().split() to handle all white-space separated tokens
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    idx = 0
    t_cases = int(input_data[idx])
    idx += 1
    
    for _ in range(t_cases):
        if idx + 1 >= len(input_data):
            break
        rows = int(input_data[idx])
        cols = int(input_data[idx + 1])
        idx += 2
        
        ans_grid = solve(rows, cols)
        for row in ans_grid:
            # Join with space for standard competitive programming output
            print(*(row))

if __name__ == '__main__':
    read_your_input()