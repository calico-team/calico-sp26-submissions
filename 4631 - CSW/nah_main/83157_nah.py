k = list(map(int,input().split()))
n = k[0]
p = k[1]
r = k[2]
k = k[3]
e = list(map(int,input().split()))
p += n//k*r
for i in range(n):
    p -= e[i]
if p >= 0:
    print("nah i'd win")
else:
    print("nah i'd lose")