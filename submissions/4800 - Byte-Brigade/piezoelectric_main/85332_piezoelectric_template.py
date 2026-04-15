import sys
input = sys.stdin.readline

def solve():
    t = int(input())
    for _ in range(t):
        L, W, E, R = map(int, input().split())

        triangle_area = (L * W) // 2
        energy_per_lap = triangle_area * R
        
        laps = E // energy_per_lap
        print(laps)

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()