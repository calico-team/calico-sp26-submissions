import sys

def count_lit_cells_optimized(s1, s2, n):
    # 四个方向的结果
    results = [0, 0, 0, 0]  # up, down, left, right
    
    for i in range(n):
        for j in range(n):
            if s2[i][j] == '#':
                # 检查上方向
                blocked_up = False
                for k in range(i):
                    if s1[k][j] == '#':
                        blocked_up = True
                        break
                if not blocked_up:
                    results[0] += 1
                
                # 检查下方向
                blocked_down = False
                for k in range(i+1, n):
                    if s1[k][j] == '#':
                        blocked_down = True
                        break
                if not blocked_down:
                    results[1] += 1
                
                # 检查左方向
                blocked_left = False
                for k in range(j):
                    if s1[i][k] == '#':
                        blocked_left = True
                        break
                if not blocked_left:
                    results[2] += 1
                
                # 检查右方向
                blocked_right = False
                for k in range(j+1, n):
                    if s1[i][k] == '#':
                        blocked_right = True
                        break
                if not blocked_right:
                    results[3] += 1
    
    return max(results), min(results)

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    t = int(data[0])
    idx = 1
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        
        s1 = [data[idx + i] for i in range(n)]
        idx += n
        
        s2 = [data[idx + i] for i in range(n)]
        idx += n
        
        max_v, min_v = count_lit_cells_optimized(s1, s2, n)
        print(max_v, min_v)

if __name__ == "__main__":
    main()