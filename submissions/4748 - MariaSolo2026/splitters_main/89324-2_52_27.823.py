import sys

def solve():

    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    ptr = 1
    
    for _ in range(T):
        P = int(input_data[ptr])
        A = int(input_data[ptr+1])
        B = int(input_data[ptr+2])
        ptr += 3
        
    
        R, C = 7, 250
        grid = [['.' for _ in range(C)] for _ in range(R)]
    
        y, x = 1, 0
        grid[0][0] = 'v' 
        temp_p = P
        for _ in range(A):
            grid[y][x] = 'S'
            grid[y][x+1] = '>' 
            
            if temp_p % 2 == 1:
                grid[y+1][x] = 'v'
                grid[y+2][x] = '>' 
            else:
                grid[y+1][x] = 'v'
                grid[y+2][x] = 'X'
            temp_p //= 2
            x += 2

        for _ in range(B):
            grid[y][x] = 'S'
            grid[y][x+1] = '>'
            
            rem = temp_p % 3
            if rem >= 1:
                grid[y+1][x] = 'v'
                grid[y+2][x] = '>' 
            else:
                grid[y+1][x] = 'v'
                grid[y+2][x] = 'X'
                
            if rem == 2:
                grid[y-1][x] = '^'
                grid[y-2][x] = '>'
            else:
                grid[y-1][x] = '^'
                grid[y-2][x] = 'X'
            temp_p //= 3
            x += 2
        
        if temp_p > 0:
            grid[y][x] = '>'
        else:
            grid[y][x] = 'X'
        print(f"{R} {C}")
        for row in grid:
            print("".join(row))

def read_your_input():
    pass

if __name__ == "__main__":
    solve()