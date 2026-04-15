t = int(input())

for _ in range(t):
    l,w,e,r = map(int,input().split())
    x = e//r
    peri = 2*l+2*w
    print(x//peri)