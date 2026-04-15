for tc in range(int(input())):
    p, a, b = map(int, input().split())
    denom = 2**a * 3**b
    arr = [['.' for _ in range(201)] for _ in range(7)]
    arr[0][0] = 'v'
    for i in range(201):
        arr[1][i] = '>'
    for i in range(a):
        arr[1][2*i+1] = 'S'
        if p >= denom//2:
            arr[0][2*i+1] = '^'
            p -= denom//2
        else:
            arr[0][2*i+1] = 'X'
        denom //= 2
    arr[1][-1] = 'v'
    arr[2][-1] = 'v'
    arr[3][-1] = 'v'
    arr[4][-1] = 'v'
    for i in range(200):
        arr[3][i] = '<'
    for i in range(201):
        arr[5][i] = '<'
    for i in range(b-1,-1,-1):
        ind = 2*i+1
        arr[5][ind] = 'S'
        denom //= 3
        if p>denom:
            p -= denom
            arr[4][ind] = '^'
        else:
            arr[4][ind] = 'X'
        if p>denom:
            p -= denom
            arr[6][ind] = 'v'
        else:
            arr[6][ind] = 'X'
    if p==0:
        arr[5][0] = 'X'
    print(7, 201)
    for row in arr:
        print(''.join(row))

