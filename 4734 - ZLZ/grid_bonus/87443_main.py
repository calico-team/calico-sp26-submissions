def solve():
    T = int(input().strip())
    for _ in range(T):
        N = int(input().strip())
        A = list(map(int, input().split()))
        # 最优解：直接输出 A
        print(" ".join(map(str, A)))

solve()