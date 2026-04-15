t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))

    candidates = sorted(set(A))

    all_combinations = [[]]
    for _ in range(n):
        all_combinations = [c + [v] for c in all_combinations for v in candidates]

    best = None
    best_b = None

    for b in all_combinations:
        cost = 0
        for i in range(n - 1):
            cost += abs(A[i] - A[i + 1])
            cost += abs(b[i] - b[i + 1])
        for i in range(n):
            cost += abs(A[i] - b[i])
        if best is None or cost < best:
            best = cost
            best_b = b

    print(*best_b)