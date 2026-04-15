t = int(input())

for _ in range(t):
    n = int(input())
    s1 = [input() for i in range(n)]
    s2 = [input() for i in range(n)]
    mx = 0
    mn = 0

    for i in range(n):
        a = s1[i].count('#')
        b = s2[i].count('#')
        mx += a * b
        mn += max(a, b)
        
    print(mx, mn)
