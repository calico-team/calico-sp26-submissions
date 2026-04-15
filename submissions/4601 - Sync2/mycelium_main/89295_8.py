import sys
input = sys.stdin.readline

def solve():
    t = int(input())
    for _ in range(t):
        xg, yg, xm, ym = map(int, input().split())
        
        D = abs(xg - xm) + abs(yg - ym)
        
        K = (2 * D - 1) // 9
        
        if K < 0:
            print(0)
            continue
        
        ans = 1 + 2 * K * (K + 1)
        print(ans)

if __name__ == "__main__":
    solve()