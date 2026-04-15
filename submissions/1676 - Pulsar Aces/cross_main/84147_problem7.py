#@title Problem 7
T=int(input())
output=""
data=[
    [0,3,2,4,1],
    [4,1,0,3,2],
    [3,2,4,1,0],
    [1,0,3,2,4],
    [2,4,1,0,3]
]
for _ in range(T):
  M,N=tuple(input().split(" "))
  for i in range(int(M)):
    for j in range(int(N)):
      output+=str(data[i%5][j%5])
      if j!=int(N)-1:
        output+=" "
    output+="\n"
print(output)