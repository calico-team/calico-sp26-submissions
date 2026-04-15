t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    a1 = sorted(a)

    ans = ' '.join(map(str,[a1[n//2] for _ in range(n)]))

    # one solution is taki
    ans1 = [a1[n//2] for _ in range(n)]

    ans2 = [a[i] for i in range(n)]

    def calc(a1,a2):
        ans = abs(a1[-1]-a2[-1])
        for i in range(n-1):
            ans+=abs(a1[i]-a1[i+1])
            ans+=abs(a2[i]-a2[i+1])
            ans+=abs(a1[i]-a2[i])
        return ans
    if calc(a,ans1)>calc(a,ans2):
        print(' '.join(map(str,ans2)))
    else:
        print(' '.join(map(str,ans1)))