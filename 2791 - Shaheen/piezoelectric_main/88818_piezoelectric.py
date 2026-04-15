T1 = input() 
T = int(T1)
while T:
    line = input().split()
    L = int(line[0])
    W = int(line[1])
    E = int(line[2])
    R = int(line[3])
    perimeter =2*(L+W)
    lapeone=perimeter*R
    total=E//lapeone
    T-=1