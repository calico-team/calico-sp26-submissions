nums=int(input())
for i in range (nums):
    A=input()
    B=list(input())
    C=""
    for x in range(len(A)):
        if(A[x] in B):
            C+=A[x]
            B.remove(A[x])
        else:
            C+="#"
    print(C)

    
