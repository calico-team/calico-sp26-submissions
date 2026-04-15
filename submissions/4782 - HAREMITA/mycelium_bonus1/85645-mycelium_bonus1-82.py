import sys
input = sys.stdin.readline

def solve(xg, yg, xm, ym):
    # Point (x,y) is mycelium iff 7*dm < 2*dg
    # where dm = |x-xm|+|y-ym|, dg = |x-xg|+|y-yg|
    # Mycelium region is bounded - find bounding box and count
    
    # Max possible mycelium radius:
    # On the axis directly away from grass, mycelium wins if 7*r < 2*(d+r)
    # where d = manhattan dist between g and m
    # 7r < 2d + 2r => 5r < 2d => r < 2d/5
    # So mycelium radius < 2*d/5 where d = manhattan(g,m)
    
    d = abs(xm - xg) + abs(ym - yg)
    max_r = (2 * d) // 5 + 2  # small buffer
    
    count = 0
    for dx in range(-max_r, max_r + 1):
        for dy in range(-max_r, max_r + 1):
            x = xm + dx
            y = ym + dy
            dm = abs(dx) + abs(dy)
            dg = abs(x - xg) + abs(y - yg)
            if 7 * dm < 2 * dg:
                count += 1
    return count

T = int(input())
for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    print(solve(xg, yg, xm, ym))