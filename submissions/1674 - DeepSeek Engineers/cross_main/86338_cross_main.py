T=int(input())
for i in range(T):
    size=input()
    sizes=size.split()
    size_ints=[int(x) for x in sizes]
    n=size_ints[0]
    m=size_ints[1]
    offset=4
    for row in range(n):
        thing=""
        for num in range(m):
            thing=thing+str((num+offset)%5)
            if num != m-1:
                thing=thing+" "
        print(thing)
        offset=offset+2