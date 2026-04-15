import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    s1 = [input().strip() for _ in range(n)]
    s2 = [input().strip() for _ in range(n)]
    
    
    ans_max = 0
    ans_min = 0
    
    for y in range(n):
        ax = s1[y].count('#')
        bz = s2[y].count('#')
        ans_max += ax * bz
        if ax and bz:
            ans_min += max(ax, bz)
    
    print(ans_max, ans_min)

t = int(input())
for _ in range(t):
    solve()

def read_your_input():
    import sys
    return sys.stdin.readline().strip()