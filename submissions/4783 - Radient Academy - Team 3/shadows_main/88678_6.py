t = int(input())

for _ in range(t):
    n = int(input())
    s1 = [input() for _ in range(n)]
    s2 = [input() for _ in range(n)]
    a = [row.count('#') for row in s1]
    b = [0]*n
    for j in range(n):
        for i in range(n):
            if s2[i][j] == '#':
                b[j] += 1
    
    maxi = 0
    for i in range(n):
        maxi += a[i] * b[i]

    mini = 0
    for i in range(n):
        mini += max(a[i], b[i])
    
    print(maxi, mini)