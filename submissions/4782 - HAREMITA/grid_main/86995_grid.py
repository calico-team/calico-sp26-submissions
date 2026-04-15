import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    
    # Sort to find the median
    sorted_A = sorted(A)
    median = sorted_A[N // 2]
    
    # Output the median N times
    # This ensures the bottom row difference is 0
    # and the vertical difference is minimized.
    ans = [median] * N
    print(*ans)