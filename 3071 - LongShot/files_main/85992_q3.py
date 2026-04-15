def solve():
    T = int(input().strip())
    for _ in range(T):
        A = input().strip()
        B = input().strip()
        
        res = ['#'] * len(A)  
        i = len(A) - 1
        j = len(B) - 1
        
        while i >= 0 and j >= 0:
            if A[i] == B[j]:
                res[i] = A[i]  
                j -= 1
            i -= 1
        
        print(''.join(res))

if __name__ == "__main__":
    solve()