T = int(input())
for h in range(T):
    A = input().strip()
    B = input().strip()
    j = 0
    res = []
    for i in range(len(A)):
        if j <len(B) and A[i] == B[j]:
            res.append(A[i])
            j += 1
        else:
            res.append("#")
    print("".join(res) if j == len(B) else "impossible")