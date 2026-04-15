tests = int(input())
for i in range(tests):
    amount, start, heal, gap = map(int, input().split())
    curse = list(map(int, input().split()))
    power = start
    count = 0
    win = True
    for need in curse:
        if power < need:
            win = False
            break
        power -= need
        count += 1
        if count == gap:
            power += heal
            count = 0
    if win:
        print("nah i'd win")
    else:
        print("nah i'd lose")