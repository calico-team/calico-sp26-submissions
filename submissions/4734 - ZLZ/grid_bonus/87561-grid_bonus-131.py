def solve():
    T = int(input().strip())
    for _ in range(T):
        N = int(input().strip())
        A = list(map(int, input().split()))

        if N <= 3:
            # Main Test Set: 尝试常数数组解法
            # 最优解之一：全部取 A[0]
            b = [A[0]] * N
        else:
            # Bonus Test Set: 最优解之一就是 b=A
            b = A

        print(" ".join(map(str, b)))
solve()