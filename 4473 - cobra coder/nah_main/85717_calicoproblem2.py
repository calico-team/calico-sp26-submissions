t=input()
t=int(t)
for j in range(t):
        n,p,r,k=input().split()
        n=int(n)
        p=int(p)
        r=int(r)
        k=int(k)
        e=input().split()
        counter=0
        alive=True
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
        
            
                
                
            
        
        
