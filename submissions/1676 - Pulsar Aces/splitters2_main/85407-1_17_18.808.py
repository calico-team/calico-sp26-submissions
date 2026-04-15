#@title Problem 10
s2=[
    ".sv",
    ".v>",
]
s3=[
    "vsv",
    "vv>",
    "v>>",
    ">v."
]
output=""
T=int(input())
for _ in range(T):
  P,A,B=map(int, input().split())
  b=[]
  dv=[2 if i<A else 3 for i in range(A+B)]
  for i in range(A+B):
    b.append(P%dv[i])
    P=P//dv[i]
  output+=str(2*A+4*B+2)+" 4\n"
  output+=">v..\n"
  for i in range(A+B):
    p=b[-1-i]
    if i<B:
      output+="vSv.\n"
      output+="vv>"+(">" if p>0 else "X")
      output+="\nv>>"+(">" if p>1 else "X")
      output+="\n>v..\n"
    else:
      output+=".Sv.\n"
      output+=".v>"+(">" if p>0 else "X")+"\n"
  output+=".X..\n"
print(output)