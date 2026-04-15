def solve():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    for _ in range(T):
        N = int(input[ptr])
        ptr += 1
        A = list(map(int, input[ptr:ptr+N]))
        ptr += N
        
        b = []
        for i in range(N):
            if i == 0 or i == N-1:
                b.append(A[i])
            else:
                # 取中位数
                values = [A[i-1], A[i], A[i+1]]
                values.sort()
                b.append(values[1])
        
        print(' '.join(map(str, b)))

if __name__ == "__main__":
    solve()
