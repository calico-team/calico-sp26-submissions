def read():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr +=1
    for _ in range(T):
        K,N,M,P,Q = map(int,input[ptr:ptr+5])
        ptr +=5
        ast = []
        pos = dict()
        for i in range(K):
            x,y = map(int,input[ptr:ptr+2])
            ptr +=2
            ast.append((x,y))
            pos[(x,y)] = i
        sx,sy = ast[0]
        cx,cy = sx,sy
        res = -1
        while True:
            cx = (cx + Q) % N
            cy = (cy + P) % M
            if (cx,cy) in pos:
                res = pos[(cx,cy)]
                break
            if cx == sx and cy == sy:
                res = 0
                break
        print(res)
read()