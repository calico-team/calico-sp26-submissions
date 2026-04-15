import sys
T = int(sys.stdin.readline())
for _ in range(T):
    K, N, M, P, Q = map(int, sys.stdin.readline().split(" "))
    M -= 1
    N -= 1
    l = tuple(map(int, sys.stdin.readline().split(" ")))
    asts = {l: None}
    x, y = l
    l = (x+P)%M, (y+Q)%N
    for __ in range(K-1):
        asts[tuple(map(int, sys.stdin.readline().split(" ")))] = None
    while l not in asts:
        x, y = l
        if x + P == M:
            x = -P
        if y + Q == N:
            y = -Q
        l = (x+P)%M, (y+Q)%N
    print(list(asts.keys()).index(l))