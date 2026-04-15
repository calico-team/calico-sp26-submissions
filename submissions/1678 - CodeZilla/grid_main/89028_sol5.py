import sys
import threading

def solve():
    input = sys.stdin.readline
    T = int(input())
    for _ in range(T):
        n = int(input())
        the_two_tower_heights = list(map(int, input().split()))
        arr = sorted(the_two_tower_heights)
        median = arr[n // 2]
        print(' '.join([str(median)] * n))

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()