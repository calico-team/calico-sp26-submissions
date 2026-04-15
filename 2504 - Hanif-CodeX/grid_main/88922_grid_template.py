def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    
    return A

def main():
    # Read the number of test cases
    line = input().split()
    if not line:
        return
    T = int(line[0])
    
    for _ in range(T):
        # Read N and the array A
        N = int(input())
        A = list(map(int, input().split()))
        
        # Solve and print result
        result = solve(N, A)
        print(' '.join(str(x) for x in result))

if __name__ == '__main__':
    main()