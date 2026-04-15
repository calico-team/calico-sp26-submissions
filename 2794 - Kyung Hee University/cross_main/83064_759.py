import sys
input = sys.stdin.readline

for i in range(int(input())):
    n, m = map(int, input().split())
    for i in range(n):
        for j in range(m):
            print((i*2+j)%5, end=' ')
        print()
