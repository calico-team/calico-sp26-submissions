import sys

def solve():
    input = sys.stdin.readline
    line = input()
    t = int(line)
    
    for _ in range(t):
        n = int(input())
        A = list(map(int, input().split()))
        
        ranges = [(0, 0)] * n
        ranges[0] = (A[0], A[0])
        
        for i in range(1, n):
            prev_l, prev_r = ranges[i-1]
            if A[i] < prev_l:
                ranges[i] = (A[i], prev_l)
            elif A[i] > prev_r:
                ranges[i] = (prev_r, A[i])
            else:
                ranges[i] = (A[i], A[i])
        
        ans = [0] * n
        ans[n-1] = ranges[n-1][0]
        
        for i in range(n-2, -1, -1):
            l, r = ranges[i]
            val = ans[i+1]
            if val < l: ans[i] = l
            elif val > r: ans[i] = r
            else: ans[i] = val
            
        sys.stdout.write(" ".join(map(str, ans)) + "\n")

if __name__ == "__main__":
    solve()