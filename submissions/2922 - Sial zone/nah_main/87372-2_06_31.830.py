import sys
input = sys.stdin.readline

def solve():
    N, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))
    
    power = P
    defeated = 0
    for i in range(N):
        power -= E[i]
        if power < 0:
            print("nah i'd lose")
            return
        defeated += 1
        if defeated % K == 0:
            power += R
    print("nah i'd win")

T = int(input())
for _ in range(T):
    solve()