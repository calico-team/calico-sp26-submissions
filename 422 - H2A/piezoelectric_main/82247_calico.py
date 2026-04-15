import math
for _ in range(int(input())):
    l,w,e,r=list(map(int,input().split()))
    print(int(e/(math.ceil(2*(l+w)*r))))
