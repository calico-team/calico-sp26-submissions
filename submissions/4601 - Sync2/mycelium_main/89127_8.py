import sys
input = sys.stdin.readline

def solve():
    t = int(input())
    for _ in range(t):
        xg, yg, xm, ym = map(int, input().split())
        
        dx = xg - xm
        dy = yg - ym
        
        limit = 500
        
        ans = 0
        
        for x in range(-limit, limit + 1):
            for y in range(-limit, limit + 1):
                
                dm = abs(x) + abs(y)
                dg = abs(x - dx) + abs(y - dy)
                
                if 7 * dm < 2 * dg:
                    ans += 1
        
        print(ans)

if __name__ == "__main__":
    solve()