import sys

def solve():
    dylan_power = 0
    
    line = sys.stdin.readline().split()
    if not line:
        return
    
    n, p, r, k = map(int, line)
    curses = list(map(int, sys.stdin.readline().split()))
    
    current_power = p
    curses_defeated = 0
    won = True
    
    for cost in curses:
        current_power -= cost
        
        if current_power < 0:
            won = False
            break
        
        curses_defeated += 1
        
        if curses_defeated % k == 0:
            current_power += r
            
    if won:
        print("nah i'd win")
    else:
        print("nah i'd lose")

def read_your_input():
    line = sys.stdin.readline()
    if line:
        return int(line.strip())
    return None

if __name__ == "__main__":
    t_cases = read_your_input()
    if t_cases is not None:
        for _ in range(t_cases):
            solve()