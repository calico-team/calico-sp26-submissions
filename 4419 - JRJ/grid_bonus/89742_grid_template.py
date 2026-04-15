def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
import sys

def solve(N, A):
    if N == 0:
        return []
    A_sorted = sorted(A)
    median = A_sorted[N // 2]
    return [median for _ in range(N)]

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    try:
        T_str = next(it)
        T = int(T_str)
        for _ in range(T):
            N = int(next(it))
            A = [int(next(it)) for _ in range(N)]
            result = solve(N, A)
            print(*(result))
    except (StopIteration, ValueError):
        pass

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
