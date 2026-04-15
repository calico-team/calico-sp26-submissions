def solve():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        curses = list(map(int, input().split()))
        
        power = P
        win = True
        
        for i in range(N):
            if power < curses[i]:
                win = False
                break
            
            power -= curses[i]
            if (i + 1) % K == 0 and i + 1 < N:
                power += R
        
        print("nah i'd win" if win else "nah i'd lose")

if __name__ == "__main__":
    solve()