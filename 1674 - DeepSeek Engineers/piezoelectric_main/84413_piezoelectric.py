t = int(input())

for i in range(t):
    l, w, e, r = map(int, input().split())
    p = 2*l+2*w
    laps = e/(p*r)
    print(int(laps))