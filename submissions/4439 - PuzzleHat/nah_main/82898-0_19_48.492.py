def solve(N, P, R, K, curses):
    power = P
    curses_defeated = 0

    for i in range(N):
        power -= curses[i]
        
        if power < 0:
            return "nah i'd lose"
        
        curses_defeated += 1
        
        if curses_defeated % K == 0:
            power += R

    return "nah i'd win"


T = int(input())
for _ in range(T):
    N, P, R, K = map(int, input().split())
    curses = list(map(int, input().split()))
    print(solve(N, P, R, K, curses))