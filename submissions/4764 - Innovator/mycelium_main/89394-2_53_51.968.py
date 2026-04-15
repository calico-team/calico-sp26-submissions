import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    pointer = 1
    
    results = []
    for _ in range(T):
        xg = int(input_data[pointer])
        yg = int(input_data[pointer+1])
        xm = int(input_data[pointer+2])
        ym = int(input_data[pointer+3])
        pointer += 4
        
        target_x = xg - xm
        target_y = yg - ym
        
        create_voronoi_7 = True
        
        dist_gm = abs(target_x) + abs(target_y)
        limit = (2 * dist_gm) // 5 + 5
        
        count = 0
        for dx in range(-limit, limit + 1):
            for dy in range(-limit, limit + 1):
                dist_m = abs(dx) + abs(dy)
                dist_g = abs(dx - target_x) + abs(dy - target_y)
                
                if 7 * dist_m < 2 * dist_g:
                    count += 1
        results.append(str(count))
    
    sys.stdout.write("\n".join(results) + "\n")

def read_your_input():
    pass

if __name__ == "__main__":
    solve()