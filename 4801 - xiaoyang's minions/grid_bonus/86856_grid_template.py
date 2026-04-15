import random
def top_row(grid): 
    sum = 0 
    for x in range(len(grid[0])-1):
        sum+=(abs(grid[0][x]-grid[0][x+1]))
    return sum

def bottom_row(grid): 
    sum = 0 
    for i in range(len(grid[0])-1):
        sum+=(abs(grid[1][i]-grid[1][i+1]))
    return sum

def between_rows(grid): 
    sum = 0 
    for i in range(len(grid[0])):
        sum+=(abs(grid[0][i]-grid[1][i]))
    return sum

def abs_sum(grid):
    return between_rows(grid) + bottom_row(grid) + top_row(grid)

def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    sum = 1000000

    #try between rows same
    temp_grid = [A] * 2
    temp_sum = abs_sum(temp_grid)
    if temp_sum < sum:
        sum = temp_sum
        output = temp_grid[1]

    #median solution
    A.sort()
    if len(A) % 2 != 0:
        median = len(A)//2
        bottomrow = [A[median]]*N
    elif len(A) % 2 == 0:
        median = len(A)//2 - 1
        bottomrow = [A[median]]* (N//2) +  [A[median+1]]* (N//2)
    
    temp_grid = [A, bottomrow]
    temp_sum = abs_sum(temp_grid)
    if temp_sum < sum:
        sum = temp_sum
        output = temp_grid[1]
    return output
    

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
