import sys
input = sys.stdin.readline

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        S1 = [input().strip() for _ in range(n)]
        S2 = [input().strip() for _ in range(n)]
        
        max_vol = 0
        min_vol = 0
        
        for j in range(n):
            A = 0  
            B = 0  
            
            for i in range(n):
                if S1[i][j] == '#':
                    A += 1
            
            for k in range(n):
                if S2[j][k] == '#':
                    B += 1
            
            max_vol += A * B
            min_vol += max(A, B)
        
        print(max_vol, min_vol)

if __name__ == "__main__":
    solve()