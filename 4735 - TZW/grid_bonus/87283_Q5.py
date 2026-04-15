T = int(input())
for i in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    A_sorted = sorted(A)
    mid = A_sorted[N // 2]
    b = [mid] * N
    print(' '.join(map(str, b)))
