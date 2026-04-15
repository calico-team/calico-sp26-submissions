T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
        
    b = [x for x in A]
        
    for i in range(N):
        l = b[i-1] if i > 0 else A[i]
        r = b[i+1] if i < N-1 else A[i]
            
        vals = sorted([l, r, A[i]])
        b[i] = vals[1]       
        
    print(*(b))