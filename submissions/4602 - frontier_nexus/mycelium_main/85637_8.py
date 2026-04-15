import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T_cases = int(input_data[0])
    pointer = 1
    
    for _ in range(T_cases):
        # Ensure we grab exactly 4 integers per test case
        xg = int(input_data[pointer])
        yg = int(input_data[pointer+1])
        xm = int(input_data[pointer+2])
        ym = int(input_data[pointer+3])
        pointer += 4
        
        # For the Bonus sets, the area where 7*dm < 2*dg is finite.
        # We find the bounding box of this region.
        # Since 7*dm < 2*dg, then 7*dm < 2*(dm + dist(G,M))
        # 5*dm < 2*dist(G,M) => dm < 0.4 * dist(G,M)
        
        dist_gm = abs(xg - xm) + abs(yg - ym)
        limit = (2 * dist_gm) // 5 + 2
        
        count = 0
        # Iterate only within the possible range of the mycelium
        for dx in range(-limit, limit + 1):
            nx = xm + dx
            # Calculate the range of dy that satisfies the inequality
            # 7*(|dx| + |dy|) < 2*(|nx - xg| + |ny - yg|)
            # For a fixed nx, we check ny values:
            for dy in range(-limit + abs(dx), limit - abs(dx) + 1):
                ny = ym + dy
                
                dm = abs(dx) + abs(dy)
                dg = abs(nx - xg) + abs(ny - yg)
                
                if 7 * dm < 2 * dg:
                    count += 1
        print(count)

if __name__ == "__main__":
    solve()