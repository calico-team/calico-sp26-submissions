T = int(input())
for i in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    if N == 1:
        b = [A[0]]
    elif N == 2:
        b = A.copy()
    else:
        m = sorted(A)[N // 2]
        b = [A[0]] + [m] * (N - 2) + [A[-1]]
    print(' '.join(map(str, b)))
