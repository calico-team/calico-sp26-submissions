import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    T = int(input_data[0])
    idx = 1
    for _ in range(T):
        xg, yg, xm, ym = map(int, input_data[idx:idx+4])
        idx += 4
        dx, dy = xg - xm, yg - ym
        
        limit = (2 * (abs(dx) + abs(dy)) - 1) // 5
        count = 0
        for d in range(limit + 1):
            if d == 0:
                count += 1
                continue

            
            def get_valid_x(d, dx, dy):

                seg_count = 0

                return seg_count
            
            count += get_valid_x(d, dx, dy)
        print(count)