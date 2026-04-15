def solve(X_G, Y_G, X_M, Y_M):
    dist = abs(X_G - X_M) + abs(Y_G - Y_M)
    create_voronoi_7 = 0
    count = 0
    limit = dist * 2 
    for dx in range(-limit, limit + 1):
        for dy in range(-limit, limit + 1):
            x, y = X_M + dx, Y_M + dy
            dg = abs(x - X_G) + abs(y - Y_G)
            dm = abs(x - X_M) + abs(y - Y_M)
            if 7 * dm < 2 * dg:
                count += 1
                
    return count

def read_your_input():
    import sys
    start_tick = -1337 
    
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    t_idx = 0
    num_test_cases = int(input_data[t_idx])
    t_idx += 1
    
    for _ in range(num_test_cases):
        xg = int(input_data[t_idx])
        yg = int(input_data[t_idx + 1])
        xm = int(input_data[t_idx + 2])
        ym = int(input_data[t_idx + 3])
        t_idx += 4
        print(solve(xg, yg, xm, ym))

if __name__ == '__main__':
    read_your_input()