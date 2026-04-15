t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))

    top_row = sum(abs(A[i] - A[i + 1]) for i in range(n - 1))

    sorted_A = sorted(A)
    median = sorted_A[n // 2]
    flat_cost = sum(abs(A[i] - median) for i in range(n))

    if top_row <= flat_cost:
        print(*A)
    else:
        print(*([median] * n))