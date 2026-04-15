t = eval(input())
for a in range(t):
    x = input().split()
    l = eval(x[0])
    w = eval(x[1])
    e = eval(x[2])
    r = eval(x[3])
    p = 2 * l + 2 * w
    print(int(e / r / p))
