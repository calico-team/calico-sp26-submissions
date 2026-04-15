def idk(a):
    ans=[a[0]]
    for i in range(1,n-1):
        ans.append(mid(a[i-1],a[i],a[i+1]))
    ans.append(a[-1])
    return ans
def mid(a,b,c):
    return sorted([a,b,c])[1]
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if n==1:
        print(a[0])
    elif n==2:
        print(a[0],a[1])
    else:
        ans=idk(a)
        for i in range(10):
            ans=idk(ans)
        print(" ".join(map(str,ans)))
