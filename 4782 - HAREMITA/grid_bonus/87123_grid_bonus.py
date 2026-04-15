import sys

# Standard fast I/O
input = sys.stdin.readline

def solve():
    line1 = input().split()
    if not line1: return
    N = int(line1[0])
    
    A = list(map(int, input().split()))
    
    # To minimize the sum of absolute differences |Ai - bi| 
    # while keeping bi harmonious (bi = bi+1), 
    # we use the median of array A.
    sorted_A = sorted(A)
    median = sorted_A[N // 2]
    
    # Create the bottom row filled with the median
    ans = [median] * N
    print(*(ans))

line = input().split()
if line:
    T = int(line[0])
    for _ in range(T):
        solve()