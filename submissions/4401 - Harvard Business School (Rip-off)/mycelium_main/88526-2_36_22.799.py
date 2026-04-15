import sys

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    results = []
    
    for _ in range(t):
        XG, YG, XM, YM = map(int, data[idx:idx+4])
        idx += 4
        
        # 枚举范围
        limit = 500
        count = 0
        
        for dx in range(-limit, limit + 1):
            for dy in range(-limit, limit + 1):
                x = XM + dx
                y = YM + dy
                
                dM = abs(dx) + abs(dy)  # = |x-XM| + |y-YM|
                dG = abs(x - XG) + abs(y - YG)
                
                # 菌丝到达时间 < 草地到达时间
                if 7 * dM < 2 * dG:
                    count += 1
        
        results.append(str(count))
    
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    solve()