import sys
input = sys.stdin.readline

def solve(N, P, R, K, curses):
    power = P
    defeated = 0
    for e in curses:
        power -= e
        if power < 0:
            return "nah i'd lose"
        defeated += 1
        if defeated % K == 0:
            power += R
    return "nah i'd win"

T = int(input())
for _ in range(T):
    N, P, R, K = map(int, input().split())
    curses = list(map(int, input().split()))
    print(solve(N, P, R, K, curses))