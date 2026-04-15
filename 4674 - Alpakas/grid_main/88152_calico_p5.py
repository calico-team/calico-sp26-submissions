def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    import sys

import sys

def solve():
    # Read the number of test cases (T) from the first line
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    t = int(input_data[ptr])
    ptr += 1
    
    for _ in range(t):
        # Read N (the number of floors/columns)
        n = int(input_data[ptr])
        ptr += 1
        
        # Read the next N integers as the top tower A
        a = input_data[ptr : ptr + n]
        ptr += n
        
        # Output A as the solution for the bottom tower B.
        # This makes the difference between rows 0, which is optimal.
        print(" ".join(a))

if __name__ == "__main__":
    solve()


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
