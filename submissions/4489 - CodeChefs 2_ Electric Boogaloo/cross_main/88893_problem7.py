T = int(input())
for _ in range(T):
    N, M = map(int, input().split())

    for r in range(N):
        row = []
        for c in range(M):
            value = (r + 2 * c) % 5
            row.append(str(value))
        print(" ".join(row))