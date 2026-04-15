import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    S1 = [input().strip() for _ in range(N)]
    S2 = [input().strip() for _ in range(N)]
    maxVol = 0
    for i in range(N):
        maxVol += S1[i].count('#') * S2[i].count('#')
    minVol = 0
    for i in range(N):
        a = S1[i].count('#')
        b = S2[i].count('#')
        minVol += max(a, b)

    print(maxVol, minVol)