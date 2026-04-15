t = int(input())
for _ in range(t):
    A = input()
    B = input()
    j = 0
    res = ""
    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            res += A[i]
            j += 1
        else:
            res += '#'
    print(res)