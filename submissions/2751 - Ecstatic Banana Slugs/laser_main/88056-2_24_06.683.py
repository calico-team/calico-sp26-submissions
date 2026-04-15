problems=int(input())

for i in range(problems):
    data = input().split()
    num_astroids=int(data[0])
    width=int(data[1])
    height=int(data[2])
    speedy=int(data[3])
    speedx=int(data[4])
    start=input().split()
    startx=int(start[0])
    starty=int(start[1])
    astroidsx=[]
    astroidsy=[]
    for j in range(num_astroids-1):
        astroid=input().split()
        astroidsx.append(int(astroid[0]))
        astroidsy.append(int(astroid[1]))
    no = True
    j = 0
    while no:
        if (speedx*j)%width==0 and (speedy*j)%height==0 and (not j==0):
            print(0)
            no = False
        for k in range(num_astroids-1):
            if (speedx*j)%width+startx==astroidsx[k] and (speedy*j)%height+starty==astroidsy[k] and not(j==0):
                print(k+1)
                no = False
        j+=1



