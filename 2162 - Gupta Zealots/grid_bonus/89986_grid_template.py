import statistics

def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    L = []
    for i in range(N):
        L.append(1)
        index = 0
    for j in range(max(A-1)):
        index = 0
        for i in range(N):
            if A[i] > L[i]:
                index += 1
            else:
                if ((i == 2) and (index == 2)):
                    L[0] += 1
                    L[1] += 1
                if (index >= 3):
                    for k in range(1,index+1):
                        L[i-k] += 1
                index = 0
        if (index >= 2):
            for k in range(1,index+1):
                L[N-k] += 1

    return L


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
