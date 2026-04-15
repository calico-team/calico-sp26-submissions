def abs_sum(grid):
    sum = 0
    for i in range(len(grid[0])):
        try:
            sum+=(abs(grid[0][i]-grid[0][i+1]))
            sum+=(abs(grid[1][i]-grid[1][i+1]))
        except:
            pass
        sum+=(abs(grid[0][i]-grid[1][i]))
    return sum


def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    sum = float('inf')

    #same bottom row
    temp_grid = [A, A]
    temp_sum = abs_sum(temp_grid)
    if temp_sum < sum:
        sum = temp_sum
        output = temp_grid[1]

    #median
    A.sort()
    if len(A) % 2 != 0:
        median = len(A)//2
        bottomrow = [A[median]]*N
    elif len(A) % 2 == 0:
        median = len(A)//2
        median2 = len(A)//2+1
        bottomrow = []
        for num in A:
            if abs(num-median) < abs(num-median2):
                bottomrow.append(median)
            else:
                bottomrow.append(median2)

    return bottomrow
    

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()