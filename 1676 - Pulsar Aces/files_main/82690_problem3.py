#@title Problem 3
T=int(input())
output=""
for _ in range(T):
  A=input()
  B=input()
  s=""
  loc=0
  for i in A:
    if loc<len(B):
      if i==B[loc]:
        s+=i
        loc+=1
      else:
        s+="#"
    else:
      s+="#"
  output+=s+"\n"
print(output)