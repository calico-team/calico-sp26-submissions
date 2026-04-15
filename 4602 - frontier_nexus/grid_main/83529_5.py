def solve():
    t = int(input().strip())
    
    for _ in range(t):
        n = int(input().strip())
        A = list(map(int, input().split()))
        
        if n == 1:
            print(A[0])
            continue
        
        b = [0] * n
        
        for i in range(n):
            b[i] = A[i]
        
        print(' '.join(map(str, b)))

if __name__ == "__main__":
    solve()