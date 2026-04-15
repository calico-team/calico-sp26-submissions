#CALICO Q2
T = eval(input())
for i in range(T):
    num = input().split()
    N = int(num[0])
    P = int(num[1])
    R = int(num[2])
    K = int(num[3])
    eList = input().split()
    cnt = 0
    for n in range(N):
        P -= int(eList[n])
        cnt += 1
        if P < 0:
            print("nah i'd lose")
            break
        if cnt == K:
            P += R
            cnt = 0
        if P <= 0 and n != N - 1:
            print("nah i'd lose")
            break
        if n == N - 1 and P >= 0:
            print("nah i'd win")
