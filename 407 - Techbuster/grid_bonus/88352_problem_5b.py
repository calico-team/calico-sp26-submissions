import sys
input = sys.stdin.readline

def solve():
    t =int(input())
    for _ in range(t):
        n = int(input())
        the_two_tower_heights = list(map(int, input().split()))
        print(' '.join(map(str, the_two_tower_heights)))

def read_input():
    solve()

if __name__ == "__main__":
    read_input()