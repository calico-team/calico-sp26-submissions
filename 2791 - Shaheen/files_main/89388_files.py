A="aacdalidcno"
B="calico"
k=0
res=""
for i in range(len(A)):
    if k<len(B) and A[i]==B[k]:
        res+=A[i]
        k+=1
    else:
            res+="#"

print(res)