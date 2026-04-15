T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    for i in range(N):
        row = []
        for j in range(M):
            row.append((i + 2*j) % 5)
        print(' '.join(map(str, row)))
