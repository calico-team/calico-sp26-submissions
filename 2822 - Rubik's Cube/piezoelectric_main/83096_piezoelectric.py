lines=input()

def electricity(l,w,e,r):
    return e/(((l*2)+(w*2))*r)

for i in range(int(lines[0]),1,int(lines[0])+1):
    p=lines[i].split()
    print(electricity(p[0],p[1],p[2],p[3]))