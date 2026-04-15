__ = int(input())
L = []
for _ in range(__):
    A=input()
    B=input()
    s=""
    j=0
    for i in range(len(A)):
        if j<len(B) and A[i]==B[j]:
            s+=A[i]
            j+=1
        else:
            s+="#"

    L.append(s)

for ans in L:
    print(ans)
