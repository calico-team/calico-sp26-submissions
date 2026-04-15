T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    
    A.sort()
    median = A[N // 2]
    
    print(*([median] * N))