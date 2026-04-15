import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())

    for i in range(N):
        row = [(i + 2 * j) % 5 for j in range(M)]
        print(*row)


