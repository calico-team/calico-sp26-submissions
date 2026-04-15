import sys
input = sys.stdin.readline
from math import gcd

t = int(input())
for i in range(t):
    k, n, m, p, q = map(int, input().split())
    start = (0, 0)
    lst = []
    for j in range(k):
        a, b = map(int, input().split())
        if j == 0:
            pass
        else:
            o = 1
            l = 1
            while True:
                if (o * p + a) % m == 0:
                    break
            while True:
                if (l * q + b) % n == 0:
                    break
            lst.append(max(o, l))
    lst.sort()
    print(lst[0])
