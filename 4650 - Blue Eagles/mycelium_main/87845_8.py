def solve_one(XG,YG,XM,YM):
    from collections import deque
    d=abs(XM-XG)+abs(YM-YG)
    limit=2*d+10
    grass={}
    q=deque([(XG,YG,0)])
    grass[(XG,YG)]=0
    while q:
        x,y,t=q.popleft()
        if t+2>limit:continue
        for nx,ny in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)):
            if (nx,ny) not in grass:
                grass[(nx,ny)]=t+2
                q.append((nx,ny,t+2))
    mycelium={}
    q=deque([(XM,YM,0)])
    mycelium[(XM,YM)]=0
    while q:
        x,y,t=q.popleft()
        if t+7>limit:continue
        for nx,ny in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)):
            if (nx,ny) in mycelium:continue
            gt=grass.get((nx,ny),10**9)
            if t+7<gt:
                mycelium[(nx,ny)]=t+7
                q.append((nx,ny,t+7))
    return len(mycelium)

def read_your_input():
    import sys
    d=sys.stdin.read().split()
    if not d:return
    t=int(d[0]);idx=1;out=[]
    for _ in range(t):
        XG=int(d[idx]);YG=int(d[idx+1]);XM=int(d[idx+2]);YM=int(d[idx+3]);idx+=4
        out.append(str(solve_one(XG,YG,XM,YM)))
    sys.stdout.write("\n".join(out))

if __name__=="__main__":
    read_your_input()
