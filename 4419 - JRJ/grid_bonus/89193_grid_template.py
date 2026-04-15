def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
def solve(N, A):
    if N == 0:
        return []
    
    A_sorted = sorted(A)
    median = A_sorted[N // 2]
    
    return [median for _ in range(N)]

def main():
    import sys
    input = sys.stdin.read().split()
    if not input:
        return
    
    idx = 0
    T_str = input[idx]
    idx += 1
    T = int(T_str)
    
    for _ in range(T):
        N = int(input[idx])
        idx += 1
        A = []
        for _ in range(N):
            A.append(int(input[idx]))
            idx += 1
        
        result = solve(N, A)
        print(' '.join(map(str, result)))

if __name__ == '__main__':
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
