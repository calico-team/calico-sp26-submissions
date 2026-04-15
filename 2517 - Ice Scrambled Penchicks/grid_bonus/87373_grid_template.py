def med(a):
    n=len(a)
    a.sort()
    return(a[n//2])


def compare(a,b):
    oda=a[1]-a[0]
    odb=b[1]-b[0]
    tda=a[2]-a[1]
    tdb=b[2]-b[1]
    yes=True
    if not((oda<=0 and odb<=0) or (oda>=0 and odb>=0)):
        yes=False
    if not((tda<=0 and tdb<=0) or (tda>=0 and tdb>=0)):
        yes=False
    return yes

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
            median=(arr[0]+arr[1])//2
            for i in range(2):
                ansarr.append(median)
    else:
        ansarr=arr
        for i in range(1,N-1):
            comparr=[arr[i-1],arr[i],arr[i+1]]
            runmed=med(comparr)
            curarr=[ansarr[i-1],runmed,ansarr[i+1]]
            if compare(comparr,curarr):
                ansarr[i]=runmed

            
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
