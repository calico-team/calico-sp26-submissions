import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    for r in range(n):
        print(*[(r * 2 + c) % 5 for c in range(m)])