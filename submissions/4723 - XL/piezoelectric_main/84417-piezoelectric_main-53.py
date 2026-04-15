a = int(input())
for i in range(a):
    b,c,d,e = input().split()
    b,c,d,e = int(b),int(c),int(d),int(e)
    f = 2*(b+c)*e
    if d % f == 0:
        print(d // f)
    else:
        print(d // f +1)
