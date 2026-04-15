import math

def solve(N, P, R, K, curses):
    my_power = P
    curses_defeated = 0
    
    for v_num in range(N):
       
        if my_power < curses[v_num]:
            return "nah i'd lose"
        
        # Defeat the curse
        my_power -= curses[v_num]
        curses_defeated += 1
        
       
        if curses_defeated % K == 0:
            my_power += R
    
    return "nah i'd win"

def main():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        curses = list(map(int, input().split()))
        print(solve(N, P, R, K, curses))

if __name__ == "__main__":
    main()