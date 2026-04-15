import sys
input = sys.stdin.readline
from fractions import Fraction as F
from graphlib import TopologicalSorter as TS

for i in range(int(input())):
    p, a, b = map(int, input().split())
    n = a + b
    print(3, 2*n+1)
    s = ['>v.']
    p1 = 2 ** a * 3 ** b
    for i in range(a):
        if p // (p1 // 2) == 1:
            p %= (p1 // 2)
            s.append('.S>')
        else:
            s.append('.SX')
        s.append('.v.')
        p1 //= 2
    for i in range(b):
        if p // (p1 // 3) == 2:
            p %= (p1 // 3)
            s.append('<S>')
        elif p // (p1 // 3) == 1:
            p %= (p1 // 3)
            s.append('<SX')
        else:
            s.append('XSX')
        s.append('.v.')
        p1 //= 3

    s.pop()
    s.append('.X.')
    print('\n'.join(s))
