import sys
input = sys.stdin.readline

def solve():
    T = int(input())
    for _ in range(T):
        N = int(input())
        
        S1 = [input().strip() for _ in range(N)]
        S2 = [input().strip() for _ in range(N)]
        
        row_count = [0] * N
        col_count = [0] * N
        
        for j in range(N):
            for i in range(N):
                if S1[i][j] == '#':
                    row_count[j] += 1
        
        for j in range(N):
            for k in range(N):
                if S2[j][k] == '#':
                    col_count[j] += 1
        
        max_vol = 0
        min_vol = 0
        
        for j in range(N):
            max_vol += row_count[j] * col_count[j]
            min_vol += max(row_count[j], col_count[j])
        
        print(max_vol, min_vol)

if __name__ == "__main__":
    solve()