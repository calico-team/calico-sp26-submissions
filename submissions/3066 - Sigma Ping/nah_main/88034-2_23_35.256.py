import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))
    
    ok = True
    
    for i in range(N):
        P -= E[i]
        if P < 0:
            ok = False
            break
        if (i + 1) % K == 0:
            P += R
    
    print("nah i'd win" if ok else "nah i'd lose")