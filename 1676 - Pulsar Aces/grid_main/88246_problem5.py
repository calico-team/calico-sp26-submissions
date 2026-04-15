#@title Problem 5
output=""
for _ in range(int(input())):
    N=int(input())
    A=list(map(int, input().split()))
    B=[]
    for i in range(N):
        if i==0 or i==N-1:
            B.append(A[i])
        else:
            a,b,c=A[i-1],A[i],A[i+1]
            B.append(a if (b-a)*(b-c)<0 else b)
    output+=" ".join(list(map(str, B)))+"\n"
print(output)