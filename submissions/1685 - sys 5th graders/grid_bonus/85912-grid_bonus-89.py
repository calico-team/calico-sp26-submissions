def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    if N == 1:
        return A
    
    candidates = sorted(set(A))
    b = []
    
    for i in range(N):
        best_val = candidates[0]
        best_cost = float('inf')
        
        for v in candidates:
            cost = abs(A[i] - v)
            
            if i > 0:
                cost += abs(v - b[i - 1])
            
            if cost < best_cost:
                best_cost = cost
                best_val = v
        b.append(best_val)
    
    return b

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
