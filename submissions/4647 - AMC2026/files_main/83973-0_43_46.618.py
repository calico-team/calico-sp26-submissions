#CALICO-2026-Problem-3
t = int(input())
for i in range(t):
    c = input()
    a = []
    for i in c:
        a.append(i)
    d = input()
    b = []
    for i in d:
        b.append(i)
    #print(a)
    #print(b)
    for i in range(len(a)):
        if len(b) != 0 and a[i] == b[0]:
            #print(a[i])
            b.remove(a[i])
            #print(b)
        else:
            a[i] = '#'
    for i in a:
        print(i, end = '')
    print()
