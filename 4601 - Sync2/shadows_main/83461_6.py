import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    s1 = [input().strip() for _ in range(n)]  # s1[z][x]
    s2 = [input().strip() for _ in range(n)]  # s2[z][y]
    
   
    
    ans_max = 0
    ans_min = 0
    
    for z in range(n):
        cx = s1[z].count('#')  # active x's at this z
        cy = s2[z].count('#')  # active y's at this z
        
        ans_max += cx * cy
        if cx > 0 and cy > 0:
            ans_min += max(cx, cy)
    
    print(ans_max, ans_min)

t = int(input())
for _ in range(t):
    solve()

def read_your_input():
    import sys
    return sys.stdin.readline().strip()