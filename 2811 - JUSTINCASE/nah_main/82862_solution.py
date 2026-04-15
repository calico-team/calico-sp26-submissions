__=int(input())
L=[]
for _ in range(__):
    N,P,R,K=map(int,input().split())
    LL=list(map(int,input().split()))
    kK=0
    for i in range(N):
        if kK==K:
            P=P+R
            P=P-LL[i]
            kK=0
        else:
            P=P
            P=P-LL[i]
            kK+=1
    if K<0:
        L.append(0)
    else:
        L.append(1)
        
for ans in L:
    if ans==0:
        print("nah i’d lose")
    else:
        print("nah i’d win")
        
