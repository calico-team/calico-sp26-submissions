T=int(input())
for _ in range(T):
    alst=list(input().split())
    prim=(int(alst[0]) +int(alst[1]))*2
    needs=int(alst[2])
    R=int(alst[3])
    stepneeded=needs/R
    if stepneeded%prim==0:
        print(int(stepneeded/prim))
    else:
        lap=(stepneeded//prim)+1
        print(int(lap))