import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    out = []
    for _ in range(T):
        N = int(input_data[idx])
        idx += 1
        
        A = []
        for _ in range(N):
            A.append(int(input_data[idx]))
            idx += 1
            
        if N == 1:
            out.append(str(A[0]))
            continue
            
        optL = [0] * N
        optR = [0] * N
        
        u = A[0]
        v = A[0]
        optL[0] = A[0]
        optR[0] = A[0]
        
        for i in range(1, N):
            roots = sorted([u, v, A[i], A[i]])
            optL[i] = roots[1]
            optR[i] = roots[2]
            
            u = roots[1]
            v = roots[2]
            
        b = [0] * N
        b[N-1] = A[N-1]
        
        for i in range(N-2, -1, -1):
            b[i] = sorted([optL[i], b[i+1], optR[i]])[1]
            
        out.append(" ".join(map(str, b)))
        
    print("\n".join(out))

if __name__ == '__main__':
    solve()