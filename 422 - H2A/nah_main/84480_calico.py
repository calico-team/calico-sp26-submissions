import math
for _ in range(int(input())):
    n,p,r,k=list(map(int,input().split()))
    curses=list(map(int,input().split()))
    flag=True
    for i in range(0,n,k):
        summ=sum(curses[i:i+k])
        if p-summ<0:
            flag=False
            break
        else:
            p-=summ
            p+=r
    if flag==True:
        print("nah i'd win")
    else:
        print("nah i'd lose")
