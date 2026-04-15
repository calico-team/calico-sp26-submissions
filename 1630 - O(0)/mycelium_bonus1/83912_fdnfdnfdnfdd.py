# from collections import deque
# import math
bigd = [(0,1),(0,-1),(1,0),(-1,0)]

def solve():
    xg,yg,xm,ym = map(int, input().split())
    grid = {(xg,yg):'G', (xm,ym):'M'}
    grass, mycel = {(xg,yg)}, {(xm,ym)}
    ans, tick = 1, 0

    def ff(cells):
        new = set()
        for x,y in cells:
            for dx,dy in bigd:
                if (x+dx,y+dy) not in grid: new.add((x+dx,y+dy))
        return new

    while True:
        tick += 1
        ng = ff(grass) if tick%2==0 else set()
        nmy = ff(mycel) if tick%7==0 else set()
        nmy -= ng
        for pos in ng: grid[pos]='G'; grass.add(pos)
        for pos in nmy: grid[pos]='M'; mycel.add(pos); ans+=1
        if not any((x+dx,y+dy) not in grid for x,y in mycel for dx,dy in bigd): #keshav check
            break

    return ans

T = int(input())
for _ in range(T):
    print(solve())