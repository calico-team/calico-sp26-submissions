import sys

def make_the_criss_cross(n, m):
    grid = [[0]*m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            grid[i][j] = (i + j) % 5
    
    return grid

def read_your_input():
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    idx = 1
    out = []
    
    for _ in range(t):
        n = int(data[idx])
        m = int(data[idx+1])
        idx += 2
        
        g = make_the_criss_cross(n, m)
        for row in g:
            out.append(" ".join(map(str, row)))
    
    print("\n".join(out))

if __name__ == "__main__":
    read_your_input()