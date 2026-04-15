def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE
    arr=A
    if N<3:
        if N==1:
            ansarr=arr
        else:
            ansarr=[]
            med=(arr[0]+arr[1])//2
            for i in range(2):
                ansarr.append(med)
    else:
        iarr=[arr[0],arr[1],arr[2]]
        iarr.sort()
        ansarr=[iarr[1]]
        for i in range(N-2):
            curarr=[arr[i],arr[i+1],arr[i+2]]
            curarr.sort()
            ansarr.append(curarr[1])
        ansarr.append(ansarr[-1]) 
    return ansarr


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
