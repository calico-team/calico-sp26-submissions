def ggrow():
    global g
    global gnew
    global gnewnew
    global m
    global mnew
    global mnewnew
    gnew=gnewnew
    gnewnew=set()
    for (x,y) in gnew:
        for (xn,yn) in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)):
            if (xn,yn) not in g and (xn,yn) not in m:
                gnewnew.add((xn,yn))
                g.add((xn,yn))
def mgrow():
    global g
    global gnew
    global gnewnew
    global m
    global mnew
    global mnewnew
    mnew=mnewnew
    mnewnew=set()
    for (x,y) in mnew:
        for (xn,yn) in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)):
            if (xn,yn) not in g and (xn,yn) not in m:
                mnewnew.add((xn,yn))
                m.add((xn,yn))
for _ in range(int(input())):
    xg,yg,xm,ym=map(int,input().split())
    g,m,gnew,gnewnew,mnew,mnewnew={(xg,yg)},{(xm,ym)},set(),{(xg,yg)},set(),{(xm,ym)}
    for i in range(abs(xg-xm)+abs(yg-ym)): #14 ticks per i
        ggrow()
        ggrow()
        ggrow()
        mgrow()
        ggrow()
        ggrow()
        ggrow()
        ggrow()
        mgrow()
    print(len(m))
