def solve(n, a):
    l =[0] *n
    r=[0] *n
    l[0]=r[0]= a[0]

    for i in range(1, n):
        if a[i]>r[i-1]:
            l[i]=r[i-1]
            r[i]= a[i]
        elif a[i]<l[i-1]:
            l[i]= a[i]
            r[i] =l[i-1]
        else: l[i] =r[i] = a[i]

    res =[0]*n
    res[-1]= r[-1]

    for i in range(n-2,-1,-1):
        if res[i+1]< l[i]:
            res[i]=l[i]
        elif res[i+1]>r[i]:
            res[i] = r[i]
        else: res[i]=res[i+1]
    return res

def read_input():
    T=int(input())
    for _ in range(T):
        N =int(input())
        A=list(map(int, input().split()))
        ans=solve(N,A)
        print(*ans)

if __name__ =='__main__':
    read_input()
