a = int(input())
for i in range(a):
    b,c,d,e = input().split()
    b,c,d,e = int(b),int(c),int(d),int(e)
    f = input().split()
    count = 0
    for j in range(len(f)):
        dam = int(f[j])
        c = c - dam
        if c >= 0:
            count += 1
        else:
            print( "nah i'd lose")
            break
        if count == e:
            c += d
            count = 0
    if c >= 0:
        print("nah i'd win")