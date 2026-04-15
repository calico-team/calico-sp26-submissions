def solve():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    
    # 读取输入
    N, M, D = map(int, input[ptr:ptr+3])
    ptr += 3
    
    constraints = []
    for i in range(M):
        R, C, V, W = map(int, input[ptr:ptr+4])
        ptr += 4
        # 转换为0-based索引
        R -= 1
        C -= 1
        constraints.append((R, C, V, W, i+1))  # 保存原始索引（1-based）
    
    # 初始化a数组为1
    a = [1.0] * N
    
    # 迭代更新a数组
    for _ in range(100):  # 迭代次数
        new_a = [0.0] * N
        counts = [0] * N
        
        # 计算每个a_i的加权和
        for R, C, V, W, idx in constraints:
            if a[C] > 0:
                new_a[R] += W * V / a[C]
                counts[R] += W
            if a[R] > 0:
                new_a[C] += W * V / a[R]
                counts[C] += W
        
        # 更新a数组
        for i in range(N):
            if counts[i] > 0:
                a[i] = new_a[i] / counts[i]
    
    # 计算每个约束的惩罚
    penalties = []
    for R, C, V, W, idx in constraints:
        if V == 0:
            penalty = 0.0
        else:
            penalty = W * abs(a[R] * a[C] - V) / V
        penalties.append((penalty, idx))
    
    # 选择惩罚最大的D个约束来丢弃
    penalties.sort(reverse=True)
    discarded = [idx for _, idx in penalties[:D]]
    
    # 转换a数组为整数（四舍五入）
    a_int = [round(x) for x in a]
    # 确保a_int[i]至少为1
    a_int = [max(1, x) for x in a_int]
    
    # 输出结果
    print(' '.join(map(str, a_int)))
    print(len(discarded), ' '.join(map(str, sorted(discarded))))

if __name__ == "__main__":
    solve()
