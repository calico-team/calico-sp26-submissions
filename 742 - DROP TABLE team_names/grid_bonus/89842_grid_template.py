
import statistics

def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid

    2 6 7 2
    2 2 2 2

    +9
    +9



    2 5 7 5
    5 5 5 5

    +5


    1 3 6 4
    3 3 3 3
    4 4 4 4

    +6

    1 3 6 5
    4 4 4 4

    +7


    1 3 5 7 9
    5 5 5 5 5


    if its sorted,then return as is
    """

    # if A == sorted(A):
    #     return A
    toret = []
    for i in range(0, N, 2):
        try:
            med = (A[i] + A[i+1]) // 2
        except:
            med = A[i]
        toret.append(med)
        toret.append(med)

    return toret
    
    # return [round(statistics.median(A))] * N
    
    
    # modes = statistics.multimode(A)
    # if len(modes) == 1:
    #     return [modes[0]] * N
    
    # avg = sum(A) / N
    # closestmode = min(A, key=lambda e: abs(e - avg))
    # return [closestmode] * N
    


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
