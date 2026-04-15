def solve():
    import sys
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    out_lines = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        A = []
        for __ in range(n):
            A.append(int(data[idx])); idx += 1
        
        if n == 1:
            out_lines.append(str(A[0]))
            continue
        
        b = [0] * n
        b[0] = A[0]
        b[n-1] = A[n-1]
        
        for i in range(1, n-1):
            three = [A[i-1], A[i], A[i+1]]
            three.sort()
            b[i] = three[1]
        
        out_lines.append(' '.join(str(x) for x in b))
    
    sys.stdout.write('\n'.join(out_lines))

if __name__ == '__main__':
    solve()
