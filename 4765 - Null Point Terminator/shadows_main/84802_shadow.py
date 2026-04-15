t = int(input())
for _ in range(t):
    n = int(input())
    s1 = []
    for i in range(n):
        s1.append(input())
    s2 = []
    for i in range(n):
        s2.append(input())
    mx = 0
    mn = 0
    for i in range(n):
        a = s1[i].count('#')
        b = s2[i].count('#')
        mx = mx + a * b
        mn = mn + max(a, b)
    print(mx, mn)
