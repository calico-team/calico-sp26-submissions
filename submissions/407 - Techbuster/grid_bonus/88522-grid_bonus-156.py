import sys
input = sys.stdin.readline

def solve():
    t =int(input())
    for _ in range(t):
        n = int(input())
        the_two_tower_heights = list(map(int, input().split()))
        b = [0]*n
        b[0]= the_two_tower_heights[0]
        for i in range(1, n):
            b[i] = min(max(the_two_tower_heights[i], b[i-1]), max(min(the_two_tower_heights[i], b[i-1]), the_two_tower_heights[i-1]))
        print(' '.join(map(str, b)))

def read_input():
    solve()

if __name__ == "__main__":
    read_input()
