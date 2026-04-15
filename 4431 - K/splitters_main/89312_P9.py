import sys
from math import gcd
from collections import deque

def main():
    dirs = {"^": (-1,0), "v": (1,0), "<": (0, -1), ">":(0, 1)}
    data = sys.stdin.read().split()
    ptr = 0
    T = int(data[ptr])
    ptr += 1
    for _ in range(T):
        N = int(data[ptr])
        M = int(data[ptr+1])
        ptr += 2
        grid = []
        for _ in range (N):
            grid.append((0, 0, 1, 1))
            ptr += -1
        res_num = 0
        res_den = 1
        q = deque()
        q.append((0, 0, 1, 1))
        ok = False
        
        while q:
            x, y, num, den = q.popleft()
            ch = grid[x][y]
            
            if ch == "X":
                continue
            
            if ch in dirs: 
                dx1, dy1 = dird[ch]
                nx = x + dx1
                ny = y + dy1
                if nx < 0 or nx >= N or ny < 0 or ny >= M :
                    res_num = num
                    res_den = den
                    ok = True
                    break
            q.append((cx, cy, num, den * k))
            
        elif ch == "S":
            cand = []
            for dx2, dy2 in [(-1,0), (1,0), (0,-1), (0,-1)]:
                cx = x + dx2
                cy = y + dy2
            if 0 <= cx <N and 0 <= cy < M:
                cch = grid[cx][cy]
                if cch == "X":
                    cand.append((cx, cy))
                elif cch in dirs[cch]:
                    ddx, ddy = dirs[cch]
                    if not (cx + ddx == x and cy + ddy == y):
                        cand.append((cx, cy))
            k = len(cand)
            for (cx, cy) in cand:
                q.append((cx, cy, num den * k))
                
        if not ok:
            print(0,1)
        else:
            g = gcd(res_num, res_den)
            print(res_num//g, res_den//g)
            
def destroy_the_tiles():
    pass

def read_your_input():
    return sys.stdin.read()
    
if __name__ == "__main__":
    main()
    