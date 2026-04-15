import sys
input = sys.stdin.readline

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        towers_heights =list(map(int, input().split()))
        towers_heights.sort()
        m = towers_heights[n//2]
        print(' '.join([str(m)]*n))

def read_input():
    solve()

if __name__ == "__main__":
    read_input()