t = int(input())
for _ in range(t):
    line = input().split()
    n = int(line[0])
    p = int(line[1])
    r = int(line[2])
    k = int(line[3])

    e = input().split()
    for i in range(len(e)):
        e[i] = int(e[i])

    power = p
    defeats = 0
    can_win = True

    for curse in e:
        power = power - curse
        if power < 0:
            can_win = False
            break
        defeats = defeats + 1
        if defeats >= k:
            power = power + r
            defeats = 0

    if can_win:
        print("nah, I'd win")
    else:
        print("nah, I'd lose")