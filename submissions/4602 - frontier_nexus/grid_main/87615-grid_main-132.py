def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    if not data:
        return
    
    T = int(data[0])
    idx = 1
    
    out = []
    for _ in range(T):
        N = int(data[idx])
        idx += 1
        
        A = []
        for _ in range(N):
            A.append(int(data[idx]))
            idx += 1
            
        # L[i] and R[i] represent the optimal value bounds for B[i]
        L = [0] * N
        R = [0] * N
        
        L[0] = A[0]
        R[0] = A[0]
        
        # Forward pass: compute DP bounds
        for i in range(1, N):
            if L[i-1] <= A[i] <= R[i-1]:
                L[i] = A[i]
                R[i] = A[i]
            elif A[i] > R[i-1]:
                L[i] = R[i-1]
                R[i] = A[i]
            else:
                L[i] = A[i]
                R[i] = L[i-1]
                
        # Backward pass: resolve exact values for B array
        B = [0] * N
        B[N-1] = L[N-1] # Any value in [L[N-1], R[N-1]] is optimal, pick L
        
        for i in range(N-2, -1, -1):
            # Clamp B[i+1] to the valid interval [L[i], R[i]]
            B[i] = max(L[i], min(R[i], B[i+1]))
            
        out.append(" ".join(map(str, B)))
        
    print("\n".join(out))

if __name__ == '__main__':
    solve()