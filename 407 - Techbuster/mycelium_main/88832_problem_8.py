import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    ptr = 1
    
    for _ in range(T):
        xg= int(input_data[ptr])
        yg = int(input_data[ptr+1])
        xm =int(input_data[ptr+2])
        ym= int(input_data[ptr+3])
        ptr += 4
        
        dx= abs(xg - xm)
        dy = abs(yg - ym)
        dist_gm = dx + dy
        
        if dist_gm == 1:
            print(1)
            continue
            
        t_intercept = (14 * dist_gm + 9) // 10
        if t_intercept % 7 != 0:
            t_intercept = ((t_intercept //7) + 1) * 7
            
        limit = t_intercept // 7
        total_tiles = 0
        
        tx = xg - xm
        ty = yg - ym
        
        for d in range(limit):
            if d == 0:
                total_tiles += 1
                continue
            
            for sx, sy in [(1,1), (1,-1), (-1,1), (-1,-1)]:
                for i in range(d):
                    cur_x = i * sx
                    cur_y = (d - i) * sy
                    if 7 * d < 2 * (abs(cur_x - tx) + abs(cur_y - ty)):
                        total_tiles += 1
                        
        print(total_tiles)

if __name__ == '__main__':
    solve()