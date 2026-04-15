T = int(input())
for i in range(T):
    n = int(input())
    A = list(map(int, input().split()))[:n]
    
    b = []
    if n == 1:
        b = [A[0]]
    else:
        is_smooth = True
        for i in range(n-1):
            if abs(A[i] - A[i+1]) > max(A):
                is_smooth = False
                break
        if is_smooth:
            b = A
        else:
            sorted_A = sorted(A)
            mid = sorted_A[n//2]
            b = [mid]*n
    
    print(' '.join(map(str, b)))
