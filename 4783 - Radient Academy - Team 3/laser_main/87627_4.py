t = int(input())

for _ in range(t):
    k, n, m, p, q = map(int, input().split())
    
    ast = []
    for i in range(k):
        x, y = map(int, input().split())
        ast.append((x, y))
    
    x, y = ast[0]  # inicio
    start = (x, y)
    
    pos = {}
    for i in range(k):
        pos[ast[i]] = i
    
    while True:
        x = (x + q) % n
        y = (y + p) % m
        
        if (x, y) in pos:
            print(pos[(x, y)])
            break
        
        if (x, y) == start:
            print(0)
            break