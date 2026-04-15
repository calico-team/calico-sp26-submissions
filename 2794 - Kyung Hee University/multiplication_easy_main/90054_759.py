import sys
input = sys.stdin.readline

n, m, d = map(int, input().split())
L = []
for i in range(m):
    r, c, v, w = map(int, input().split())
    L.append((i, v, w))

def f(a):
    ll = []
    for i, v, w in L:
        ll.append((w * abs(a ** 2 - v) / v, i))
    ll = sorted(ll)
    dl = []
    for i in range(d):
        v, i = ll.pop()
        dl.append(i)
    tot = sum(v for v, i in ll)
    return tot, dl, a

Lv = 1; Rv = 10 ** 9
for i in range(52):
    T1, T2 = (Lv * 2 + Rv) // 3, (Lv + Rv * 2) // 3
    if f(T1) > f(T2):
        Lv = T1
    else:
        Rv = T2

v, dl, a = min(f(Lv), f(T1), f(T2), f(Rv))
print(*(a for i in range(n)))
print(d, *(i+1 for i in dl))
