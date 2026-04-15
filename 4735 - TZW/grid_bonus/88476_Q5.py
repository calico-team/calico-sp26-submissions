T = int(input())

for i in range(T):
    N = int(input())
    A = list(map(int, input().split()))

    cost1 = 0
    for i in range(N - 1):
        cost1 += abs(A[i] - A[i + 1])

    sorted_A = sorted(A)
    median = sorted_A[N // 2]
    cost2 = 0
    for num in A:
        cost2 += abs(num - median)
    
    if cost1 <= cost2:
        print(' '.join(map(str, A)))
    else:
        print(' '.join(map(str, [median] * N)))
