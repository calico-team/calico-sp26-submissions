import sys
input = sys.stdin.readline

def count_row(dy, dxg, dyg, max_r):
    # Count dx in [-max_r, max_r] where 7*(|dx|+|dy|) < 2*(|dx-dxg|+|dy-dyg|)
    # Let A = |dy|, B = |dy - dyg|
    # Need: 7*(|dx|+A) < 2*(|dx-dxg|+B)
    # => 7*|dx| - 2*|dx-dxg| < 2*B - 7*A
    A = abs(dy)
    B = abs(dy - dyg)
    rhs = 2 * B - 7 * A
    
    # Count integer dx where 7*|dx| - 2*|dx-dxg| < rhs
    # Split into regions based on sign of dx and dx-dxg
    # Breakpoints at dx=0 and dx=dxg
    
    count = 0
    lo = -max_r
    hi = max_r
    
    # We'll iterate over the 3 regions: dx<min(0,dxg), between, dx>max(0,dxg)
    breakpoints = sorted(set([lo, 0, dxg, hi+1]))
    
    def f(dx):
        return 7 * abs(dx) - 2 * abs(dx - dxg)
    
    # For each region, f(dx) is linear, so check endpoints
    # Actually just count analytically per linear region
    
    regions = []
    pts = sorted(set([0, dxg]))
    boundaries = [lo] + pts + [hi+1]
    
    for i in range(len(boundaries)-1):
        a = boundaries[i]
        b = boundaries[i+1] - 1
        if a > b:
            continue
        # In [a,b], |dx| and |dx-dxg| are linear
        # f(dx) = 7*s1*dx - 2*s2*(dx-dxg) where s1=sign, s2=sign
        # = (7*s1 - 2*s2)*dx + 2*s2*dxg
        if a >= 0:
            s1 = 1
        else:
            s1 = -1  # but dx could cross 0... boundaries handle this
        # Actually boundaries split at 0 and dxg so within region, signs are constant
        mid = a
        s1 = 1 if mid >= 0 else -1
        s2 = 1 if mid >= dxg else -1
        # f(dx) = (7*s1 - 2*s2)*dx + 2*s2*dxg
        slope = 7*s1 - 2*s2
        const = 2*s2*dxg
        # f(dx) < rhs => slope*dx < rhs - const
        rem = rhs - const
        if slope == 0:
            if 0 < rem:
                count += b - a + 1
        elif slope > 0:
            # dx < rem/slope
            import math
            max_dx = min(b, math.ceil(rem/slope) - 1)
            if max_dx >= a:
                count += max_dx - a + 1
        else:
            # dx > rem/slope
            import math
            min_dx = max(a, math.floor(rem/slope) + 1)
            if min_dx <= b:
                count += b - min_dx + 1
    
    return count

def solve(xg, yg, xm, ym):
    dxg = xg - xm
    dyg = yg - ym
    d = abs(dxg) + abs(dyg)
    max_r = (2 * d) // 5 + 5
    
    total = 0
    for dy in range(-max_r, max_r + 1):
        total += count_row(dy, dxg, dyg, max_r)
    return total

T = int(input())
for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    print(solve(xg, yg, xm, ym))