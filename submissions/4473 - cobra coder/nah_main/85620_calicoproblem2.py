t=input()
t=int(t)
for j in range(t):
        n,p,r,k=input().split()
        n=int(n)
        p=int(p)
        r=int(r)
        k=int(k)
        e=int(input().split())
        counter=0
        alive=True
        if 1<=t<100 and 1<=n<=10**4 and 1<=p<=10**5 and 1<=r<=10**4 and 1<=k<=10**4 and 1<=e<=10**4:
            for i in e:
                p=p-int(i)
                if p<0:
                    print("nah i'd lose")
                    alive=False
                    break
                counter=counter+1
                if counter==k:
                    p=p+r
                    counter=0
            if alive==True:
                print("nah i'd win")
        
            
                
                
            
        
        
