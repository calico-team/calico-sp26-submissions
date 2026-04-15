T=int(input())
for i in range(T):
    size = int(input())
    side1=[]
    side2=[]
    for row in range(size):
        r=input()
        side1.append(r)
    for row in range(size):
        r=input()
        side2.append(r)
        
    max = 0
    
    for slice in range(size):
        sidea=side1[slice]
        aCount=sidea.count("#")
        sideb=side2[slice]
        bCount=sideb.count("#")
        max = max + aCount*bCount
    
    min = 0
    
    for slice in range(size):
        sidea=side1[slice]
        aCount=sidea.count("#")
        sideb=side2[slice]
        bCount=sideb.count("#")
        if aCount>bCount:
            min=min+aCount
        else:
            min=min+bCount
    
    print(max, min)
