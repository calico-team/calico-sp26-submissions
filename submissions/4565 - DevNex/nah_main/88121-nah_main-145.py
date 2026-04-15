def solve(N, P, R, K, curses):
    dylan_power = P
    for i, e in enumerate(curses, 1):
        dylan_power -= e
        if dylan_power < 0:
            return "nah i'd lose"
        if i % K == 0:
            dylan_power += R
    return "nah i'd win"

def read_your_input():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        curses = list(map(int, input().split()))
        print(solve(N, P, R, K, curses))

read_your_input()