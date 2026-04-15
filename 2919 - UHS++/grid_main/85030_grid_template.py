# def calculate(top, bottom):
#     top_sum = 0
#     for i in range(len(top)-1):


def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    ans = []
    ans.append(A[0])
    for i in range(1, N-1):
        last = ans[i-1]
        next = A[i]
        next_2 = A[i+1]
        if next_2 <= max(last,next) and next_2 >= min(last,next):
            ans.append(next_2)
        elif next_2 > max(last,next):
            ans.append(max(last,next))
        else:
            ans.append(min(last,next))
    
    ans.append(A[N-1])

    return ans




def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
