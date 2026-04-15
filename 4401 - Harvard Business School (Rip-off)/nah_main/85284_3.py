
count=int(input())
for i in range(0,count):
    defeat=False
    victory=False
    detect=False
    curse=[]
    count=0
    n,p,r,k=map(int,input().split())
    cursessssssssss=input()
    curse=cursessssssssss.split()
    while detect==False:
        detect=True
        for plp in range(1,n):
            if int(curse[plp])<int(curse[plp-1]):
                curse[plp],curse[plp-1]=curse[plp-1],curse[plp]
                detect=False
    for pop in range(0,n):
        if  p>=int(curse[pop]):
            p=p-int(curse[pop])
            count+=1 
        else:
            if count>=k:
                p+=r
                r=0   
                if p<int(curse[pop]):
                    defeat=True
                    print("nah i’d lose") 
                    break
                else :
                    p=p-int(curse[pop])
                    count+=1
            else:
                defeat=True
                print("nah i’d lose") 
                break 
        if pop==n-1 and defeat==False:
            victory=True
            print("nah i’d win")
            break
                
        
    