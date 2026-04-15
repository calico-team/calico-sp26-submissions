def c(A, B):
    n, m = len(A), len(B)
    
    right = [n] * m 
    j = m - 1
    for i in range(n - 1,-1, -1):
        if j >= 0 and A[i] == B[j]:
            right[j] = i
            j -= 1
    
    result = []
    j = 0
    
    for i in range(n):
        if j <m and A[i]==B[j] and (j==m- 1 or i <= right[j+1]):
            result.append(A[i])
            j+=1
        else:
            result.append('#')
    
    return ''.join(result)
T = int(input())
for _ in range(T):
    A = input().strip()
    B = input().strip()
    print(c(A, B))