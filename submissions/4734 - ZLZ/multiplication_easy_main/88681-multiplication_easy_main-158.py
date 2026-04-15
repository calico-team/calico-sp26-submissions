import math, random

def compute_penalty(a, constraints, discard_set):
    total = 0.0
    for idx, (Ri, Ci, Vi, Wi) in enumerate(constraints, start=1):
        if idx in discard_set:
            continue
        pred = a[Ri] * a[Ci]
        err = abs(pred - Vi) / Vi
        total += Wi * err
    return total

def solve(N, M, D, constraints, iterations=20000):
    # 初始数组
    a = [1] * (N + 1)
    for Ri, Ci, Vi, Wi in constraints:
        if a[Ri] == 1 and a[Ci] == 1:
            val = int(round(math.sqrt(Vi)))
            if val == 0: val = 1
            a[Ri] = val
            a[Ci] = max(1, Vi // val)
        elif a[Ri] != 1:
            a[Ci] = max(1, Vi // a[Ri])
        elif a[Ci] != 1:
            a[Ri] = max(1, Vi // a[Ci])

    # 优化迭代
    discard_set = set()
    best_penalty = compute_penalty(a, constraints, discard_set)
    for _ in range(iterations):
        i = random.randint(1, N)
        old_val = a[i]
        change = random.choice([-1, 1])
        new_val = max(1, old_val + change)
        a[i] = new_val
        new_penalty = compute_penalty(a, constraints, discard_set)
        if new_penalty < best_penalty:
            best_penalty = new_penalty
        else:
            a[i] = old_val  # 回退

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
