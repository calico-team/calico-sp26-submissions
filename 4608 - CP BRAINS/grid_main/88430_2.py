import statistics
from collections import Counter
import math

def sumvalues(N,A,arr):
    sum1=0
    for i in range(N):
        sum1+=abs(A[i]-arr[i])


    sum2=0

    for i in range(N-1):    
        sum2+=abs(arr[i]-arr[i+1])  
    
    sum3=0
    for i in range(N):
        sum3+=abs(A[i]-arr[i])
    
    return sum1+sum2+sum3
    


def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    sum1=0
    maxValue=0
    maxkey=0
    hashmap=Counter(A)
    for key in hashmap:
        if hashmap[key]>maxValue:
            maxValue=hashmap[key]
            maxkey=key
    
    arr1=[maxkey]*N

    maximum=max(A)
    minimum=min(A)
    arr2=[maximum]*N
    arr3=[minimum]*N


    median=math.ceil(statistics.median(A))
    arr4=[median]*N

    mode=sum(A)/N
    arr5=[mode]*N

    arr6=[mode+1]*N
    arr7=[mode-1]*N
    a1=sumvalues(N,A,arr1)
    a2=sumvalues(N,A,arr2)
    a3=sumvalues(N,A,arr3)
    a4=sumvalues(N,A,arr4)
    a5=sumvalues(N,A,A)
    a6=sumvalues(N,A,arr6)
    a7=sumvalues(N,A,arr7)
    a=[]
    a.append((a1,arr1))
    a.append((a2,arr2))
    a.append((a3,arr3))
    a.append((a4,arr4))
    a.append((a5,A))
    a.append((a6,arr5))
    a.append((a7,arr6))
    a.append((a7,arr7))
    minimum=min(a)
    return minimum[1]
    


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
