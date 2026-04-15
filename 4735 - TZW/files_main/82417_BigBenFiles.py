T = int(input())

for _ in range(T):
    A = input()
    B = input()
    
    j = 0 
    result = ""
    
    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            result += A[i]
            j += 1
        else:
            result += "#"
    
    print(result)
