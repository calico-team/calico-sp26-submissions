import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T_cases = int(input_data[0])
    idx = 1
    
    for _ in range(T_cases):
        xg, yg = int(input_data[idx]), int(input_data[idx+1])
        xm, ym = int(input_data[idx+2]), int(input_data[idx+3])
        idx += 4
        
        dx, dy = xg - xm, yg - ym
        
        limit = (abs(dx) + abs(dy)) * 2 // 5 + 2
        total_tiles = 0
        
        for x in range(-limit, limit + 1):

            rhs = 2 * abs(x - dx) - 7 * abs(x)
       
            y_min = None
            y_max = None
            
            low, high = -limit, limit
            while low <= high:
                mid = (low + high) // 2
                if 7 * abs(mid) - 2 * abs(mid - dy) < rhs:
                    y_max = mid
                    low = mid + 1
                else:
                    high = mid - 1
            
            low, high = -limit, limit
            while low <= high:
                mid = (low + high) // 2
                if 7 * abs(mid) - 2 * abs(mid - dy) < rhs:
                    y_min = mid
                    high = mid - 1
                else:
                    low = mid + 1
            
            if y_min is not None and y_max is not None and y_min <= y_max:
                total_tiles += (y_max - y_min + 1)
                
        print(total_tiles)

if __name__ == "__main__":
    solve()
