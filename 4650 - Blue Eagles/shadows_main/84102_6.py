import sys

def solve():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out = []
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
        
        row_s1 = [row.count('#') for row in s1]
        col_s2 = [sum(s2[i][j] == '#' for i in range(n)) for j in range(n)]
        
        maxv = 0
        minv = 0
        
        out.append(str(maxv) + ' ' + str(minv))
    
    sys.stdout.write('\n'.join(out))

if __name__ == '__main__':
    solve()
