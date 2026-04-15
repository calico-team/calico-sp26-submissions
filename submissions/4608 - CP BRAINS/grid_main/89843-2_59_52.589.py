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
    arr8=[0]*N
    arr9=[1000000000]*N
    arr10=[-1000000000]*N
    arr11=[mode+2]*N
    arr12=[mode-2]*N
    arr13=[mode+3]*N
    arr14=[mode-3]*N
    arr15=[mode+4]*N
    arr16=[mode-4]*N
    arr17=[mode+5]*N
    arr18=[mode-5]*N
    arr19=[mode+6]*N
    arr20=[mode-6]*N
    arr21=[mode+7]*N
    arr22=[mode-7]*N
    a1=sumvalues(N,A,arr1)
    a2=sumvalues(N,A,arr2)
    a3=sumvalues(N,A,arr3)
    a4=sumvalues(N,A,arr4)
    a5=sumvalues(N,A,A)
    a6=sumvalues(N,A,arr6)
    a7=sumvalues(N,A,arr7)
    a8=sumvalues(N,A,arr8)
    a9=sumvalues(N,A,arr9)
    a9=sumvalues(N,A,arr10)
    a10=sumvalues(N,A,arr11)    
    a11=sumvalues(N,A,arr12)
    a12=sumvalues(N,A,arr13)
    a13=sumvalues(N,A,arr14)
    a14=sumvalues(N,A,arr15)
    a15=sumvalues(N,A,arr16)
    a16=sumvalues(N,A,arr17)
    a17=sumvalues(N,A,arr18)
    a18=sumvalues(N,A,arr19)
    a19=sumvalues(N,A,arr20)
    a20=sumvalues(N,A,arr21)
    a21=sumvalues(N,A,arr22)

    a=[]
    a.append((a1,arr1))
    a.append((a2,arr2))
    a.append((a3,arr3))
    a.append((a4,arr4))
    a.append((a5,A))
    a.append((a6,arr5))
    a.append((a7,arr6))
    a.append((a7,arr7))
    a.append((a8,arr8))
    a.append((a9,arr9))
    a.append((a9,arr10))
    a.append((a10,arr11))
    a.append((a11,arr12))
    a.append((a12,arr13))
    a.append((a13,arr14))
    a.append((a14,arr15))
    a.append((a15,arr16))
    a.append((a16,arr17))
    a.append((a17,arr18))
    a.append((a18,arr19))
    a.append((a19,arr20))
    a.append((a20,arr21))
    a.append((a21,arr22))
    
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
