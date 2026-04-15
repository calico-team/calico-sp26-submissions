tn = int(input())
for _ in range(tn):
    n, m = map(int, input().split())
    a = [[(-1 + j + i*2) % 5 for j in range(m)] for i in range(n)]
    for x in a: print(*x)
