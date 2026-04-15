t = int(input())
for _ in range(t):
    inputs = input().split()
    n = int(inputs[0])
    p = int(inputs[1])
    r = int(inputs[2])
    k = int(inputs[3])
    cnt = 0
    win = 1
    es = input().split()
    for e in es:
        e = int(e)
        p -= e
        cnt += 1
        if p < 0:
            win = 0
            break
        if cnt % k == 0:
            p += r
    if win:
        print("nah i'd win")
    else:
        print("nah i'd lose")