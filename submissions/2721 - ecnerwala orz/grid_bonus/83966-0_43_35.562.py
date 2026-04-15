from collections import deque
import sys

input = lambda: sys.stdin.readline().strip()
print = lambda *args, end='\n': sys.stdout.write(" ".join([str(arg) for arg in args]) + end)

def soln_greedy():
    n = int(input())
    a = list(map(int, input().split()))
    b = [0] * n
    b[0], b[n - 1] = a[0], a[n - 1]
    for i in range(1, n - 1):
        lower = min(a[i], b[i - 1])
        upper = max(a[i], b[i - 1])
        check = a[i + 1]
        if lower <= check <= upper:
            b[i] = check
        elif upper <= check:
            b[i] = upper
        else:
            b[i] = lower
    print(*b)

for _ in range(int(input())):
    soln_greedy()