nums=int(input())
for i in range (nums):
    A=input()
    B=list(input())
    C=""
    j=0
    for x in range(len(A)):
        if j<len(B) and A[x]==B[j]:
            C+=A[x]
            j+=1
        else:
            C+="#"
    print(C)


    
