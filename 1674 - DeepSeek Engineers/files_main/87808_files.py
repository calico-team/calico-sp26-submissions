t = int(input())

for i in range(t):
    a = input()
    b = input()
    bi = 0

    for i in range(len(a)):
        if bi == len(a):
            break
        if a[i] == b[bi]:
            bi += 1
        else:
            a = a[:i] + "#" + a[i+1:]
    
    print(a)