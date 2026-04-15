pattern = [
    [0, 1, 2, 3, 4],
    [1, 2, 3, 4, 0],
    [2, 3, 4, 0, 1],
    [3, 4, 0, 1, 2],
    [4, 0, 1, 2, 3]
]

T = int(input())
b = []
for _ in range(T):
    N, M = map(int, input().split())
    for i in range(N):
        a = []
        for j in range(M):
            a.append(str(pattern[i % 5][j % 5]))
        b.append(" ".join(a))
for i in b:
    print(i)