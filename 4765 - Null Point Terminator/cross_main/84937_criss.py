t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    for r in range(n):
        row = []
        for c in range(m):
            row.append(str((2 * r + c) % 5))
        print(' '.join(row))
