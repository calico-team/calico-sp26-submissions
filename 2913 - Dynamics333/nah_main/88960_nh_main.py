import math

def solve(N, P, R, K, danger_zone):
    fuel = P
    danger_zone_defeated = 0
    
    for i in range(N):
        # Check if Gojo can defeat this curse
        if fuel < danger_zone[i]:
            return "nah i'd lose"
        
        # Defeat the curse
        fuel -= danger_zone[i]
        danger_zone_defeated += 1
        
        # Check if Gojo can use Reverse Cursed Technique
        if danger_zone_defeated % K == 0:
            fuel += R
    
    return "nah i'd win"

def main():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        curses = list(map(int, input().split()))
        print(solve(N, P, R, K, curses))

if __name__ == "__main__":
    main()