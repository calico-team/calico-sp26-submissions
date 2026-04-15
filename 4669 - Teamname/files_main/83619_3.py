# ﷽
from math import ceil
for _ in range(int(input())):
    s=input()
    k=input()
    ans=''
    ind=0
    ind2=0
    while(ind2<len(k)):
        if(s[ind]==k[ind2]):
            ans+=k[ind2]
            ind+=1
            ind2+=1
        else:
            ans+="#"
            ind+=1 
    for i in range(ind,len(s)):
        ans+="#"
    print(ans)    