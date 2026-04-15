from collections import deque
import sys

input = lambda: sys.stdin.readline().strip()
print = lambda *args, end='\n': sys.stdout.write(" ".join([str(arg) for arg in args]) + end)

for _ in range(int(input())):
    l, w, e, r = map(int, input().split())
    loop = 2 * (l + w) * r
    print(e // loop)