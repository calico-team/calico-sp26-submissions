
l=int(input())
for i in range(l):
    defeat=False
    
    detect=False
    curse=[]
    count=0
    n,p,r,k=map(int,input().split())
    cursessssssssss=input()
    curse=cursessssssssss.split()
    
    for pop in range(0,n):
        if  p>=int(curse[pop]):
            p=p-int(curse[pop])
            count+=1 
        if count==k:
            p+=r
        if p<int(curse[pop]):
            defeat=True
            
            
                
               
       
    if defeat==False:
        
        print("nah i’d win")
        break
    else:
        print("nah i’d lose")
        break              
    