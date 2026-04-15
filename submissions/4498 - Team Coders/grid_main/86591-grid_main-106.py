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
        return [A[0]]
        
    L_arr = [0] * N
    R_arr = [0] * N
    
    L = A[0]
    R = A[0]
    L_arr[0] = L
    R_arr[0] = R
    
    for i in range(1, N):
        val = A[i]
        # Find the middle two elements of the sorted points to update bounds
        pts = sorted([L, R, val, val])
        L = pts[1]
        R = pts[2]
        L_arr[i] = L
        R_arr[i] = R
        
    the_two_tower_heights = [0] * N
    the_two_tower_heights[N-1] = L_arr[N-1]
    
    # Backtrack to find the optimal heights
    for i in range(N-2, -1, -1):
        the_two_tower_heights[i] = max(L_arr[i], min(the_two_tower_heights[i+1], R_arr[i]))
        
    return the_two_tower_heights


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


def read_your_input():
    pass


if __name__ == '__main__':
    main()