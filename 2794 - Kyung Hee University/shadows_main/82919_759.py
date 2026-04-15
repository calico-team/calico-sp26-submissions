import sys
input = sys.stdin.readline

for i in range(int(input())):
    n = int(input())
    g1 = [input().strip().count('#') for i in range(n)]
    g2 = [input().strip().count('#') for i in range(n)]
    print(sum(i*j for i, j in zip(g1, g2)), sum(max(i, j) for i, j in zip(g1, g2)))
