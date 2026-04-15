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
        ans = [a[0],]+ [[*sorted(a[1:-1])][(n-2)//2],]*(n-2) + [a[-1]]
        print(" ".join(map(str,ans)))
