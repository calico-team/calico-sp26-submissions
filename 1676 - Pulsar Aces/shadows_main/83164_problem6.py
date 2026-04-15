#@title Problem 6
T=int(input())
output=""
for _ in range(T):
  N=int(input())
  A=[0 for _ in range(N)]
  B=[0 for _ in range(N)]
  for i in range(N):
    s=input()
    for k in s:
      if k=="#":
        A[i]+=1
  for i in range(N):
    s=input()
    for k in s:
      if k=="#":
        B[i]+=1
  output+=str(sum([i*j for i,j in zip(A,B)]))+" "+str(sum([max(i,j) for i,j in zip(A,B)]))+"\n"
print(output)