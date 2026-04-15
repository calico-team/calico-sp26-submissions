import sys

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    t = int(data[0])
    idx = 1
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        
        s1 = []
        for i in range(n):
            s1.append(data[idx])
            idx += 1
        
        s2 = []
        for i in range(n):
            s2.append(data[idx])
            idx += 1
        
        max_v = 0
        min_v = 0
        
        for z in range(n):
            row_cnt = 0
            col_cnt = 0
            for x in range(n):
                if s2[x][z] == '#':
                    row_cnt += 1
            for y in range(n):
                if s1[y][z] == '#':
                    col_cnt += 1
            max_v += row_cnt * col_cnt
            min_v += max(row_cnt, col_cnt)
        
        print(max_v, min_v)

if __name__ == "__main__":
    main()