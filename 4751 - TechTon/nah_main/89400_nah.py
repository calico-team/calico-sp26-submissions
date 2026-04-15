import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))
    
    taqat = P
    haraya = 0
    jeeta = True
    
    for e in E:
        taqat -= e
        if taqat < 0:
            jeeta = False
            break
        haraya += 1
        if haraya % K == 0:
            taqat += R
    
    print("nah i'd win" if jeeta else "nah i'd lose")