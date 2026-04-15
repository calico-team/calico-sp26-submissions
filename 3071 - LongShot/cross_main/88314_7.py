d = [
    [0, 1, 2, 3, 4],
    [1, 2, 3, 4, 0],
    [2, 3, 4, 0, 1],
    [3, 4, 0, 1, 2],
    [4, 0, 1, 2, 3]
]

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    for i in range(N):
        a = [d[i % 5][b % 5] for b in range(M)]
        print(' '.join(map(str, a)))