def solve():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())   
        for i in range(n):
            row = []
            for j in range(m):
                row.append((i + 2 * j) % 5)
            print(*row)

solve()