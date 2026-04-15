import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T_str = input_data[0]
    T = int(T_str)
    idx = 1
    
    for _ in range(T):
        xg = int(input_data[idx])
        yg = int(input_data[idx+1])
        xm = int(input_data[idx+2])
        ym = int(input_data[idx+3])
        idx += 4
        
        dx = abs(xg - xm)
        dy = abs(yg - ym)
        d = dx + dy
        
        limit = (7 * d - 1) // 3
        
        count = 0
        for x in range(xm - limit, xm + limit + 1):
            rem_y = limit - abs(x - xm)
            y_low = ym - rem_y
            y_high = ym + rem_y
            
            for y in range(y_low, y_high + 1):
                dist_m = abs(x - xm) + abs(y - ym)
                dist_g = abs(x - xg) + abs(y - yg)
                
                time_m = 7 * dist_m
                time_g = 2 * dist_g
                
                if time_m < time_g:
                    count += 1
                    
        print(count)

if __name__ == "__main__":
    solve()
