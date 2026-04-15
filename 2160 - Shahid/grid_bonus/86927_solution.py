import sys
input = sys.stdin.readline

def solve():
    N = int(input())
    A = list(map(int, input().split()))

    if N == 1:
        print(A[0])
        return

    Lo = [0] * N
    Hi = [0] * N
    Lo[0] = A[0]
    Hi[0] = A[0]

    for i in range(1, N):
        vals = sorted([Lo[i-1], Hi[i-1], A[i], A[i]])
        Lo[i] = vals[1]
        Hi[i] = vals[2]

    the_two_tower_heights = [0] * N
    the_two_tower_heights[N-1] = Lo[N-1]

    for i in range(N-2, -1, -1):
        v = the_two_tower_heights[i+1]
        if v < Lo[i]:
            the_two_tower_heights[i] = Lo[i]
        elif v > Hi[i]:
            the_two_tower_heights[i] = Hi[i]
        else:
            the_two_tower_heights[i] = v

    print(*the_two_tower_heights)


def read_your_input():
    T = int(input())
    for _ in range(T):
        solve()

if __name__ == '__main__':
    read_your_input()
