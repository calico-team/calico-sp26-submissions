import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    pointer = 1
    
    for _ in range(T):
        xg, yg = int(input_data[pointer]), int(input_data[pointer+1])
        xm, ym = int(input_data[pointer+2]), int(input_data[pointer+3])
        pointer += 4

        dx, dy = xg - xm, yg - ym
        
        count = 0
        limit = (abs(dx) + abs(dy)) * 2 // 5 + 5 
  
        for x in range(-limit, limit + 1):
            y = 0
            y_up = -1
            low, high = 0, limit
            
            while low <= high:
                mid = (low + high) // 2
                dist_m = abs(x) + abs(mid)
                dist_g = abs(x - dx) + abs(mid - dy)
                
                if 7 * dist_m < 2 * dist_g:
                    y_up = mid
                    low = mid + 1
                    
                else:
                    high = mid - 1
            
            y_down = 1
            low, high = 0, limit
            
            while low <= high:
                mid = (low + high) // 2
                dist_m = abs(x) + abs(-mid)
                dist_g = abs(x - dx) + abs(-mid - dy)
                
                if 7 * dist_m < 2 * dist_g:
                    y_down = -mid
                    low = mid + 1
                    
                else:
                    high = mid - 1
            
            if y_up != -1:
                count += (y_up - y_down + 1)
                
        print(count)

if __name__ == "__main__":
    solve()
