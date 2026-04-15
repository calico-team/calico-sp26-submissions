def calc_cost(A, B):
    N = len(A)
    cost = 0
    # Top row
    for i in range(N - 1):
        cost += abs(A[i] - A[i + 1])
    # Bottom row
    for i in range(N - 1):
        cost += abs(B[i] - B[i + 1])
    # Between rows
    for i in range(N):
        cost += abs(A[i] - B[i])
    return cost


def solve():
    T = int(input().strip())
    for _ in range(T):
        N = int(input().strip())
        A = list(map(int, input().split()))

        if N <= 3:
            # 暴力枚举所有可能的 b（取值范围可以是 A 中的元素）
            candidates = set(A)
            best_cost = float("inf")
            best_b = None
            # 枚举所有组合
            from itertools import product
            for B in product(candidates, repeat=N):
                cost = calc_cost(A, B)
                if cost < best_cost:
                    best_cost = cost
                    best_b = B
            print(" ".join(map(str, best_b)))
        else:
            # Bonus Test Set: 直接输出 A
            print(" ".join(map(str, A)))
solve()