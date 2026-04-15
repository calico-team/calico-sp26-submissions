def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # Base case for a grid with only 1 column
    if N == 1:
        return [A[0]]
        
    low = [0] * N
    high = [0] * N
    
    # Initialize the first column's optimal range
    low[0] = A[0]
    high[0] = A[0]
    
    # Forward pass: track the optimal interval for each B[i]
    for i in range(1, N):
        if A[i] < low[i-1]:
            low[i] = A[i]
            high[i] = low[i-1]
        elif A[i] > high[i-1]:
            low[i] = high[i-1]
            high[i] = A[i]
        else:
            low[i] = A[i]
            high[i] = A[i]
            
    # Backward pass: reconstruct the optimal B array
    B = [0] * N
    B[N-1] = high[N-1]  # Pick any valid endpoint to start tracking back
    
    for i in range(N-2, -1, -1):
        # Pull B[i] as close to B[i+1] as possible within its valid range
        if B[i+1] < low[i]:
            B[i] = low[i]
        elif B[i+1] > high[i]:
            B[i] = high[i]
        else:
            B[i] = B[i+1]
            
    return B


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()