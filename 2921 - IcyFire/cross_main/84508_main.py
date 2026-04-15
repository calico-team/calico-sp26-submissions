T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    for r in range(n):
        row = []
        for c in range(m):
            val = (r + 2 * c) % 5
            row.append(str(val))
        print(" ".join(row))