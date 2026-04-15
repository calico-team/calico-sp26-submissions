import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    idx = 0
    T_str = input_data[idx]
    idx += 1
    T = int(T_str)
    
    for _ in range(T):
        P = int(input_data[idx])
        A = int(input_data[idx+1])
        B = int(input_data[idx+2])
        idx += 3
        
        grid = [['.' for _ in range(100)] for _ in range(20)]
        
        for j in range(1, 100):
            grid[0][j] = '<'
        for j in range(99):
            grid[2][j] = '>'
        grid[0][0] = 'v'
        grid[1][0] = 'S'
        grid[1][99] = '^'
        grid[2][99] = 'v'
        
        current_P = P
        for i in range(A):
            if current_P % 2 == 1:
                grid[4 + i][1] = 'v'
                grid[5 + i][1] = 'X'
                current_P = (current_P + 1) // 2
            else:
                grid[4 + i][1] = '^'
                current_P //= 2
            grid[4 + i][0] = 'S'
            grid[4 + i][2] = 'v'
            
        for i in range(B):
            row = 4 + A + i
            if current_P % 3 == 1:
                grid[row][1] = 'v'
                grid[row + 1][1] = 'X'
                current_P = (current_P + 2) // 3
            elif current_P % 3 == 2:
                grid[row][1] = 'v'
                grid[row + 1][1] = 'v'
                grid[row + 2][1] = 'X'
                current_P = (current_P + 1) // 3
            else:
                grid[row][1] = '^'
                current_P //= 3
            grid[row][0] = 'S'
            grid[row][2] = 'v'

        print("20 100")
        for row in grid:
            print("".join(row))

if __name__ == "__main__":
    solve()