import math


def solve(N, M, D, constraints):
    # 初始数组
    a = [1] * (N + 1)  # 1-indexed

    # 简单启发式：根据约束更新 a
    for Ri, Ci, Vi, Wi in constraints:
        # 估计两个数的乘积应该接近 Vi
        # 如果其中一个还没更新过，就用 sqrt 来估计
        if a[Ri] == 1 and a[Ci] == 1:
            val = int(round(math.sqrt(Vi)))
            if val == 0: val = 1
            a[Ri] = val
            a[Ci] = max(1, Vi // val)
        else:
            # 如果一个已经有值，更新另一个
            if a[Ri] != 1:
                a[Ci] = max(1, Vi // a[Ri])
            elif a[Ci] != 1:
                a[Ri] = max(1, Vi // a[Ci])

    # 丢弃 penalty 最大的 D 个约束
    penalties = []
    for idx, (Ri, Ci, Vi, Wi) in enumerate(constraints, start=1):
        pred = a[Ri] * a[Ci]
        err = abs(pred - Vi) / Vi
        penalties.append((Wi * err, idx))
    penalties.sort(reverse=True)
    discard = [idx for _, idx in penalties[:D]]

    # 输出结果
    print(" ".join(str(x) for x in a[1:]))
    print(len(discard), *discard)


def main():
    N, M, D = map(int, input().split())
    constraints = []
    for _ in range(M):
        Ri, Ci, Vi, Wi = map(int, input().split())
        constraints.append((Ri, Ci, Vi, Wi))
    solve(N, M, D, constraints)


if __name__ == "__main__":
    main()
