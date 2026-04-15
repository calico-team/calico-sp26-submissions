G = [
    [0,3,2,4,1],
    [4,1,0,3,2],
    [3,2,4,1,0],
    [1,0,3,2,4],
    [2,4,1,0,3]
]
T = int(input())
for _ in range(T):
    m,n = map(int, input().split())
    for i in range(m):
        a = []
        for j in range(n):
            a.append(str(G[i%5][j%5]))
        print(' '.join(a))