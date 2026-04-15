input_data = sys.stdin.read().strip().split()
t = int(input_data[0])
idx = 1
results = []
for _ in range(t):
    n = int(input_data[idx]); idx += 1
    A = list(map(int, input_data[idx:idx+n])); idx += n
        
    if n == 1:
        results.append(str(A[0]))
        continue
        
        # 加权中位数
    pairs = [(A[i], 1 if i == 0 or i == n-1 else 2) for i in range(n)]
    pairs.sort()
        
    total_weight = 2*n - 2
    target = total_weight // 2  # 整数除法，足够
    cum = 0
    m = None
    for val, w in pairs:
        cum += w
        if cum > target:
            m = val
            break
        # 确保 m 被设置
    if m is None:
        m = pairs[-1][0]
        
    results.append(' '.join(str(m) for _ in range(n)))
    
print('\n'.join(results))
