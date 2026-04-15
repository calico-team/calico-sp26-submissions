import sys
input = sys.stdin.readline

def solve(N, S1, S2):
    max_vol = 0
    min_vol = 0
    for r in range(N):
        s1_count = S1[r].count('#')
        s2_count = S2[r].count('#')
        max_vol += s1_count * s2_count
        min_vol += max(s1_count, s2_count)
    return max_vol, min_vol

T = int(input())
for _ in range(T):
    N = int(input())
    S1 = [input().strip() for _ in range(N)]
    S2 = [input().strip() for _ in range(N)]
    mx, mn = solve(N, S1, S2)
    print(mx, mn)