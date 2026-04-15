
data = sys.stdin.read().strip().split()
if not data:
    return
t = int(data[0])
idx = 1
out_lines = []
for _ in range(t):
    n = int(data[idx]); idx += 1
    A = list(map(int, data[idx:idx+n])); idx += n
        
    if n == 1:
        out_lines.append(str(A[0]))
        continue
        
    pairs = [(A[i], 1 if i == 0 or i == n-1 else 2) for i in range(n)]
    pairs.sort()
        
    total_weight = 2 * n - 2
    target = total_weight // 2  # 整数除法
        
    cum = 0
    m = None
    for val, w in pairs:
        cum += w
        if cum > target:
            m = val
            break
        
        # 理论上这里 m 一定不为 None，因为总和 > target
    if m is None:
        m = pairs[-1][0]
        
    out_lines.append(' '.join(str(m) for _ in range(n)))
    
sys.stdout.write('\n'.join(out_lines))


