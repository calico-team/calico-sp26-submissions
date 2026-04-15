import sys
import heapq

def solve():
    input = sys.stdin.readline
    T = int(input())
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    for _ in range(T):
        xg,yg,xm,ym = map(int,input().split())
        D = abs(xg-xm) + abs(yg-ym)
        R = D * 3 + 10  
        g = {}
        g[(xg,yg)] = 1
        g[(xm,ym)] = 2
        pq = []
        heapq.heappush(pq, (2, xg, yg, 1))
        heapq.heappush(pq, (7, xm, ym, 2))
        ans = 1 
        while pq:
            t, x, y, ty = heapq.heappop(pq)
            if g.get((x,y), 0) != ty:
                continue
            if ty == 2:
                ans += 1
            for i in range(4):
                nx, ny = x+dx[i], y+dy[i]
                if abs(nx-xm)+abs(ny-ym) > R:
                    continue
                if (nx,ny) not in g:
                    g[(nx,ny)] = ty
                    nt = t + (2 if ty==1 else 7)
                    heapq.heappush(pq, (nt, nx, ny, ty))
        print(ans)

if __name__ == "__main__":
    solve()