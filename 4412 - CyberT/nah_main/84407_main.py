t = int(input().strip())
for _ in range(t):
    n, p, r, k = map(int, input().split()) 
    enemies = list(map(int, input().split())) 
    win = True
    count = 0
    for damage in enemies:
        p -= damage
        count += 1
        if p < 0:
            win = False
            break
        if count % k == 0:
            p += r
    if win:
        print("nah i'd win")
    else:
        print("nah i'd lose")