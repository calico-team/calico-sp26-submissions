from collections import deque
import sys

input = lambda: sys.stdin.readline().strip()
print = lambda *args, end='\n': sys.stdout.write(" ".join([str(arg) for arg in args]) + end)

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if n < 3:
        print(*a)
    elif (a[0] <= a[1] <= a[2]) or (a[0] >= a[1] >= a[2]):
        print(a[0], a[1], a[2])
    elif a[1] < min(a[0], a[2]):
        print(a[0], min(a[0], a[2]), a[2])
    else:
        print(a[0], max(a[0], a[2]), a[2])