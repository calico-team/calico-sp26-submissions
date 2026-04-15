import sys
input = sys.stdin.readline

def solve():
    T = int(input())
    for _ in range(T):
        xg, yg, xm, ym = map(int, input().split())
        
        D = abs(xg - xm) + abs(yg - ym)
        
        # number of tiles mycelium occupies
        ans = (D - 1) * (D - 2) // 2
        
        print(ans)

if __name__ == "__main__":
    solve()


def read_your_input():
    return sys.stdin.buffer.read().decode()