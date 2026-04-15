T = int(input())
for i in range(T):
    N,P,R,K = map(int,input().split())
    E = list(map(int,input().split()))
    IsAlive = True
    for j in range(N):
        P = P - E[j]
        if P<0:
            print("nah i'd lose")
            IsAlive = False
            break
        if (j+1)%K == 0:
            P = P + R
    if IsAlive == True:
        print("nah i'd win")



