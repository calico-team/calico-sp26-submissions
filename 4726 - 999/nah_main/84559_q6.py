a = int(input())
for i in range(a):
    b, c, d, e = map(int, input().split())
    f = input().split()
    count = 0
    for dam in map(int, f):
        c -= dam
        if c >= 0:
            count += 1
        else:
            print("nah i'd lose")
            break
        if count == e:
            c += d
            count = 0
    else:
        if c >= 0:
            print("nah i'd win")
