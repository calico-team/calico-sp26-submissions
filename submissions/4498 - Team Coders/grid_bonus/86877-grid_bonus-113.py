import sys

def solve(N, A):
    """
    Finds the optimal second row B to minimize the sum of absolute differences.
    """
    if N == 0:
        return []
    
    # Forward pass: Determine the optimal range [L, R] for each b_i
    L_bounds = [0] * N
    R_bounds = [0] * N
    
    L = A[0]
    R = A[0]
    L_bounds[0] = L
    R_bounds[0] = R
    
    for i in range(1, N):
        val = A[i]
        # Find the intersection points of the previous range and the current A[i]
        pts = sorted([L, R, val, val])
        L = pts[1]
        R = pts[2]
        L_bounds[i] = L
        R_bounds[i] = R
    
    # Backward pass: Select specific values within those ranges
    the_two_tower_heights = [0] * N
    the_two_tower_heights[N-1] = L_bounds[N-1]
    
    for i in range(N-2, -1, -1):
        target = the_two_tower_heights[i+1]
        if target < L_bounds[i]:
            the_two_tower_heights[i] = L_bounds[i]
        elif target > R_bounds[i]:
            the_two_tower_heights[i] = R_bounds[i]
        else:
            the_two_tower_heights[i] = target
            
    return the_two_tower_heights

def main():
    # Robust input reading for competitive programming environments
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    ptr = 1
    for _ in range(T):
        if ptr >= len(input_data):
            break
        N = int(input_data[ptr])
        ptr += 1
        A = [int(x) for x in input_data[ptr : ptr + N]]
        ptr += N
        
        result = solve(N, A)
        print(" ".join(map(str, result)))

def read_your_input():
    main()

if __name__ == '__main__':
    main()