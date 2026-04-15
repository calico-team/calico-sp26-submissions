def solve():
    import sys
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out = []
    
    for _ in range(t):
        n = int(data[idx]); idx += 1
        A = []
        for __ in range(n):
            A.append(int(data[idx])); idx += 1
        
        b = []
        for i in range(n):
            left = A[i-1] if i > 0 else A[i]
            right = A[i+1] if i < n-1 else A[i]
            b.append(sorted([left, A[i], right])[1])
        
        out.append(' '.join(map(str, b)))
    
    print('\n'.join(out))

if __name__ == "__main__":
    solve()
