def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    if N == 0:
        return []
    if N == 1:
        the_two_tower_heights = [A[0]]
        return the_two_tower_heights
        
    L_hist = [0] * N
    R_hist = [0] * N
    
    L = A[0]
    R = A[0]
    L_hist[0] = L
    R_hist[0] = R
    
    for i in range(1, N):
        if A[i] < L:
            R = L
            L = A[i]
        elif A[i] > R:
            L = R
            R = A[i]
        else:
            L = A[i]
            R = A[i]
        L_hist[i] = L
        R_hist[i] = R
        
    the_two_tower_heights = [0] * N
    the_two_tower_heights[N-1] = L_hist[N-1]
    
    for i in range(N-2, -1, -1):
        val = the_two_tower_heights[i+1]
        if val < L_hist[i]:
            the_two_tower_heights[i] = L_hist[i]
        elif val > R_hist[i]:
            the_two_tower_heights[i] = R_hist[i]
        else:
            the_two_tower_heights[i] = val
            
    return the_two_tower_heights


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()

def read_your_input():
    pass
