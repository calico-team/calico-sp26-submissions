def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    import sys # Crucial: Must be at the very top to avoid NameError

def solve(N, A):
    """
    To minimize the sum of absolute differences, mirroring the first row
    is an optimal strategy. This makes the 'Between Rows' difference 0.
    """
    return A

import sys

def main():
    # Standard way to read all input data for competitive programming
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    # Read the number of test cases (T)
    t_cases = int(input_data[ptr])
    ptr += 1
    
    for _ in range(t_cases):
        # Read N (the number of columns)
        n = int(input_data[ptr])
        ptr += 1
        
        # Read the heights of the top tower (A)
        # We take the next 'n' items starting from the current pointer
        a_row = input_data[ptr : ptr + n]
        ptr += n
        
        # OPTIMAL STRATEGY: Mirror the top row.
        # This makes the vertical difference 0, which minimizes the total sum.
        print(" ".join(a_row))

if __name__ == "__main__":
    main()


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
