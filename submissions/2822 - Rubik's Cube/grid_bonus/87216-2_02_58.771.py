def grid():
    length = int(input())
    blocks = list(map(int, input().split()))
    
    if length == 1:
        print(blocks[0])
        return
    l = [0] * length
    r = [0] * length
    l[0] = blocks[0]
    r[0] = blocks[0]
    
    for i in range(1, length):
        a = blocks[i]
        pl = l[i-1]
        pr = r[i-1]
        
        if a < pl:
            l[i] = a
            r[i] = pl
        elif a > pr:
            l[i] = pr
            r[i] = a
        else:
            l[i] = a
            r[i] = a
    b = [0] * length
    b[-1] = blocks[-1]
    
    for i in range(length-2, -1, -1):
        nxt = b[i+1]
        if nxt < l[i]:
            b[i] = l[i]
        elif nxt > r[i]:
            b[i] = r[i]
        else:
            b[i] = nxt
    print(' '.join(map(str, b)))

lines = int(input())
for i in range(lines):
    grid()